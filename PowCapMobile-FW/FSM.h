#ifndef _FSM_H_
#define _FSM_H_

#include <stdint.h>
#include <LUFA/Drivers/Board/LEDs.h>
#include "commands.h"
#define GAINC1    'G'		//current1 gain
#define GAINV1    'g'		//voltage1 gain
#define FILTERV1  'f'		//voltage1  filter designation
#define FILTERC1  'F'		//current1 filter designation
#define NOTCHV1	  'n'		//voltage1 notch filter designation
#define NOTCHC1   'N'		//current1 notch filter designation

#define GAINC2    'A'		//current2 gain
#define GAINV2    'a'		//voltage2 gain
#define FILTERV2  'b'		//voltage2  filter designation
#define FILTERC2  'B'		//current2 filter designation
#define NOTCHV2	  's'		//voltage2 notch filter designation
#define NOTCHC2   'S'		//current2 notch filter designation

#define NUMBER_CMDS 12

#define VALIDCMD(c) (((c)==(GAINC1)) || ((c)==(GAINV1)) || ((c)==(FILTERV1)) || ((c)==(FILTERC1)) || ((c)==(NOTCHV1)) || ((c)==(NOTCHC1)) || ((c)==(GAINC2)) || ((c)==(GAINV2)) || ((c)==(FILTERV2)) || ((c)==(FILTERC2)) || ((c)==(NOTCHV2)) || ((c)==(NOTCHC2)))
typedef enum {WAITING_CMD,PARAM1,PARAM2,PARAM3,PARAM4,RUN} FSM_STATE;

FSM_STATE FSM_State;

typedef struct{
    int16_t command;
    char param[5];
} COMMAND; 

COMMAND cmd;

typedef void(*CMD_CALLBK)(char *param);

typedef struct{
    int16_t id; 
    CMD_CALLBK fxn;
} CALLBACK;

CALLBACK cb_command[NUMBER_CMDS];

void init_callbacks(void);

void setup_callbacks(void);

int16_t search_callback(COMMAND *cmd);

void init_FSM(void);

void init_command(COMMAND *cmd); 

void set_command(COMMAND *cmd, int16_t c);

void set_param0(COMMAND *cmd, int16_t p);

void set_param1(COMMAND *cmd, int16_t p);

void process_byte(int16_t rxbyte);

#endif

