#include <avr/io.h>
#include "FSM.h"
#include "commands.h"
#include <ctype.h>
void init_callbacks() {
    for(int i=0;i<NUMBER_CMDS;i++){
        cb_command[i].id = 0;
        cb_command[i].fxn = NULL;
    }
}

void setup_callbacks() {
    init_callbacks();
    cb_command[0].id = GAINC1;
    cb_command[0].fxn = cb_gainC1; 
    cb_command[1].id = GAINV1;
    cb_command[1].fxn = cb_gainV1;
    cb_command[2].id = FILTERV1;
    cb_command[2].fxn = cb_filterV1;
    cb_command[3].id = FILTERC1;
    cb_command[3].fxn = cb_filterC1;
    cb_command[4].id = NOTCHV1;
    cb_command[4].fxn = cb_notchV1;
    cb_command[5].id = NOTCHC1;
    cb_command[5].fxn = cb_notchC1;
    cb_command[6].id = GAINC2;
    cb_command[6].fxn = cb_gainC2; 
    cb_command[7].id = GAINV2;
    cb_command[7].fxn = cb_gainV2;
    cb_command[8].id = FILTERV2;
    cb_command[8].fxn = cb_filterV2;
    cb_command[9].id = FILTERC2;
    cb_command[9].fxn = cb_filterC2;
    cb_command[10].id = NOTCHV2;
    cb_command[10].fxn = cb_notchV2;
    cb_command[11].id = NOTCHC2;
    cb_command[11].fxn = cb_notchC2;

}


int16_t search_callback(COMMAND *cmd) {
    
    for (int i=0;i<NUMBER_CMDS;i++) {

        if (cmd->command == cb_command[i].id) {
            //LEDs_ToggleLEDs(LEDS_LED1);
            cb_command[i].fxn(cmd->param);
            return 0;
        }
    }
    return -1;
}

void init_FSM() {
    FSM_State = WAITING_CMD;
    init_command(&cmd);
}

void init_command(COMMAND *cmd) {
    cmd->command = 0;
    cmd->param[0] = '\0';
}

void set_command(COMMAND *cmd, int16_t c) {
    if(VALIDCMD(c)) { 
        cmd->command = c;
        FSM_State = PARAM1;
    } else {
    
        init_FSM();
    }
}

void set_param0(COMMAND *cmd, int16_t p) {
    if(isxdigit(p)) {
        cmd->param[0] = (char)p;
        cmd->param[1] = '\0';
        FSM_State = PARAM2;
    } else {
        init_FSM();
    }
}

void set_param1(COMMAND *cmd, int16_t p) {
    if(isxdigit((int)p)) {
        cmd->param[1] = (char)p;
        cmd->param[2] = '\0';
        FSM_State = RUN;
    } else {
        init_FSM();
    }
}

void process_byte(int16_t rxbyte) {
    switch(FSM_State) { 
        case WAITING_CMD:
            set_command(&cmd, rxbyte);
            break;
        case PARAM1:
            set_param0(&cmd, rxbyte);
            break;
        case PARAM2:
            set_param1(&cmd, rxbyte);
            break;
        case RUN:
            if(isspace(rxbyte)) {
                search_callback(&cmd);
                init_FSM();
                break;
            }
        default:
            init_FSM();
            break;
     }
}
