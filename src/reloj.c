#include "reloj.h"
#include "stdio.h"
#include <string.h>


#define UNIDAD_SEG  5
#define DECENA_SEG  4
#define UNIDAD_MIN  3
#define DECENA_MIN  2
#define UNIDAD_HOR  1
#define DECENA_HOR  0

#define TIEMPO_DECENA 6
#define TIEMPO_UNIDAD 10


struct clock_s {
    uint8_t hora_actual[6];
	uint32_t tics_per_second;
    uint32_t tics;
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

bool ClockSetTime(clock_t reloj,const uint8_t * hora, int size){

	memcpy(reloj->hora_actual, hora, size);
	reloj->valida = true;
	
	return true;
}

void ClockTick(clock_t reloj){
	
	reloj -> tics++;

	if (reloj -> tics == UNIDAD_SEG) {
		reloj -> hora_actual[UNIDAD_SEG]++;
		reloj -> tics = 0;
	}

	if (reloj -> hora_actual[UNIDAD_SEG] == TIEMPO_UNIDAD) {
        reloj -> hora_actual[UNIDAD_SEG] = 0;
        reloj -> hora_actual[DECENA_SEG]++;
    }

    if (reloj -> hora_actual[DECENA_SEG] == TIEMPO_DECENA) {
        reloj -> hora_actual[DECENA_SEG] = 0;
        reloj -> hora_actual[UNIDAD_MIN]++;
    }

    if (reloj -> hora_actual[UNIDAD_MIN] == TIEMPO_UNIDAD) {
        reloj -> hora_actual[UNIDAD_MIN] = 0;
        reloj -> hora_actual[DECENA_MIN]++;
    }

    if (reloj -> hora_actual[DECENA_MIN] == TIEMPO_DECENA) {
        reloj -> hora_actual[DECENA_MIN] = 0;
        reloj -> hora_actual[UNIDAD_HOR]++;
    }

    if (reloj -> hora_actual[UNIDAD_HOR] == TIEMPO_UNIDAD) {
        reloj -> hora_actual[UNIDAD_HOR] = 0;
        reloj -> hora_actual[DECENA_HOR]++;
    }

    if ((reloj -> hora_actual[DECENA_HOR] == 2) & (reloj -> hora_actual[UNIDAD_HOR] == 4)) {
        reloj -> hora_actual[UNIDAD_HOR] = 0;
        reloj -> hora_actual[DECENA_HOR] = 0;
    }
}