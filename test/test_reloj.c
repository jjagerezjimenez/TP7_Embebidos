#include "unity.h"
#include "reloj.h"


void setUp(void) {
   static const uint8_t INICIAL[] = {1, 2, 3, 4};
   reloj = ClockCreate(TRIKS_PER_SECOND);
   
}




void test_reloj_arranca_con_hora_invalida(void) {
   static const uint8_t ESPERANDO[] = {0, 0, 0, 0, 0, 0};
   uint8_t hora[6] = {0xFF};

   clock_t reloj = ClockCreate(5);
   TEST_ASSERT_FALSE(ClockGetTime(reloj, hora, 6));
   TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO, hora, 6);
}



void test_ajustar_hora(void){
   static const uint8_t ESPERANDO[] = {1, 2, 3, 4, 0, 0};
   uint8_t hora[6] = {0xFF};                    //no hace falta dejarlo en FF

   clock_t reloj = ClockCreate(5);
   //CloclSetTime(reloj, ESPERANDO, 4);
   TEST_ASSERT_TRUE(ClockGetTime(reloj, ESPERANDO, 4));           //ojo, corregir, uso get y no deberia, se cuelag porque pide escritura
//   TEST_ASSERT_TRUE(ClockGetTime(reloj, hora, 6));
//   TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERANDO, hora, 6);

}


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