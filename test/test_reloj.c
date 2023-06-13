#include "unity.h"
#include "reloj.h"
#include <string.h>


#define TICS_POR_SEGUNDO 5

#define SIMULADOR_SEGUNDOS(VALOR, VALOR_2)\
	for (int i = 0; i < VALOR; i++) {\
		for (int index = 0; index < TICS_POR_SEGUNDO; index++) {\
			VALOR_2;\
		}\
    }


static clock_t	reloj;		//?
static uint8_t hora[6];		//?



void setUp(void) {
   	static const uint8_t INICIAL[] = {1, 2, 3, 4};
	reloj = ClockCreate(TICS_POR_SEGUNDO);
   
}




void test_reloj_arranca_con_hora_invalida(void) {
	static const uint8_t ESPERANDO[] = {0, 0, 0, 0, 0, 0};
	uint8_t hora[6] = {0xFF};

	clock_t reloj = ClockCreate(TICS_POR_SEGUNDO);

	TEST_ASSERT_FALSE(ClockGetTime(reloj, hora, 6));
	TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO, hora, 6);
}



void test_ajustar_hora(void){
	static const uint8_t ESPERANDO[] = {1, 2, 3, 4, 0, 0};
	uint8_t hora[6];                  //no hace falta dejarlo en FF
	
	clock_t reloj = ClockCreate(TICS_POR_SEGUNDO);
	//CloclSetTime(reloj, ESPERANDO, 4);
	TEST_ASSERT_TRUE(ClockSetTime(reloj, ESPERANDO, 4));           //ojo, corregir, uso get y no deberia, se cuelag porque pide escritura
	TEST_ASSERT_TRUE(ClockGetTime(reloj, hora, 6));
	TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO, hora, 6);

}



void test_unidad_segundos(void){
	static const uint8_t INICIAL[] = {1, 2, 3, 4, 0, 0};
	static const uint8_t ESPERANDO[] = {1, 2, 3, 4, 0, 1};
	uint8_t hora[6];                  //no hace falta dejarlo en FF

	clock_t reloj = ClockCreate(TICS_POR_SEGUNDO);
	ClockSetTime(reloj, INICIAL, 4);

	SIMULADOR_SEGUNDOS(1, ClockTick(reloj));
	ClockGetTime(reloj, hora, 6);

	TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO, hora, 6);

}
