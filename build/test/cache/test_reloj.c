#include "src/reloj.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


static clock_t reloj;

static uint8_t hora[6];







void setUp(void) {

    static const uint8_t INICIAL[] = {1, 2, 3, 4};

 reloj = ClockCreate(5);



}









void test_reloj_arranca_con_hora_invalida(void) {

 static const uint8_t ESPERANDO[] = {0, 0, 0, 0, 0, 0};

 uint8_t hora[6] = {0xFF};



 clock_t reloj = ClockCreate(5);



 do {if (!(ClockGetTime(reloj, hora, 6))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(36)));}} while(0);

 UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

((void *)0)

), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}







void test_ajustar_hora(void){

 static const uint8_t ESPERANDO[] = {1, 2, 3, 4, 0, 0};

 uint8_t hora[6];



 clock_t reloj = ClockCreate(5);



 do {if ((ClockSetTime(reloj, ESPERANDO, 4))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(48)));}} while(0);

 do {if ((ClockGetTime(reloj, hora, 6))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(49)));}} while(0);

 UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

((void *)0)

), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



}







void test_unidad_segundos(void){

 static const uint8_t INICIAL[] = {1, 2, 3, 4, 0, 0};

 static const uint8_t ESPERANDO[] = {1, 2, 3, 4, 0, 1};

 uint8_t hora[6];



 clock_t reloj = ClockCreate(5);

 ClockSetTime(reloj, INICIAL, 4);



 for (int i = 0; i < 1; i++) { for (int index = 0; index < 5; index++) { ClockTick(reloj); } };

 ClockGetTime(reloj, hora, 6);



 UnityAssertEqualIntArray(( const void*)((ESPERANDO)), ( const void*)((hora)), (UNITY_UINT32)((6)), (

((void *)0)

), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);



}
