#include "reloj.h"
#include "stdio.h"
#include <string.h>


struct clock_s {
    uint8_t hora_actual[6];
	bool valida;

};
        



clock_t ClockCreate(int tics_por_segundo){
	static struct clock_s self[1];

	memset(self, 0, sizeof(self));
	return self;
    //return NULL;
}

bool ClockGetTime(clock_t reloj, uint8_t * hora, int size){
	memcpy(hora, reloj->hora_actual, size);
	return reloj->valida;
    //return true;
}

void ClockSetTime(clock_t reloj,const uint8_t * hora, int size){

	reloj->valida = true;
	//	memcpy(reloj->hora_actual, hora, size);
	return true;
}

void ClockTrick(clock_t clock){
	clock->hora_actual[5] =1;
}