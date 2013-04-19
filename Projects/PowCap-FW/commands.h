#ifndef _COMMANDS_H_
#define _COMMANDS_H

#include "FSM.h"

void cb_gain1(char *param);	//voltage PGA
void cb_gain2(char *param);	//current PGA

void cb_filter1(char *param); //voltage filters
void cb_filter2(char *param); //current filters

void cb_notch1(char *param); //voltage 60hz notch filter
void cb_notch2(char *param); //current 60hz notch filter

#endif
