#include "unity.h"
#include "reloj.h"
#include <string.h>


#define TICS_POR_SEGUNDO 5

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


/*
void test_ajustar_hora(void){
	static const uint8_t INICIAL[] = {1, 2, 3, 4};
	static const uint8_t ESPERANDO[] = {1, 2, 3, 4, 0, 1};
	uint8_t hora[6] = {0xFF};                    //no hace falta dejarlo en FF

	clock_t reloj = ClockCreate(TICK_PER_SECOND);
	ClockSetTime(reloj, INICIAL sizeof(INICIAL));
	fro (int index = 0; index < TICKS:PER_SECOND; index++) {

	}
	//CloclSetTime(reloj, ESPERANDO, 4);
	TEST_ASSERT_TRUE(ClockGetTime(reloj, ESPERANDO, 4));           //ojo, corregir, uso get y no deberia, se cuelag porque pide escritura
	//   TEST_ASSERT_TRUE(ClockGetTime(reloj, hora, 6));
	//   TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO, hora, 6);

}
*/