#include "unity.h"
#include "stdint.h"
#include <stdbool.h>
#include "clock.h"

#define TICKS_PER_SECOND 5

// Configurar la libreria, consultar la hora tiene que ser invalida.
void test_hora_inicial_invalida(void){
    static const uint8_t ESPERADO[] = {0,0,0,0,0,0};
    uint8_t hora[6];
    clock_t reloj = ClockCreate(TICKS_PER_SECOND); // Recibe por params la cant. de pulsos de reloj que valen 1 segundo
    TEST_ASSERT_FALSE( ClockGetTime(reloj, hora, sizeof(hora)));
    TEST_ASSERT_EQUAL_UINT8_ARRAY( ESPERADO, hora, sizeof(ESPERADO));
}

// Configurar la libreria, ajustar la hora (con valores correctos), consultar la hora y tiene que ser valida.
void test_set_up_current_time(void){
    static const uint8_t INICIAL[] = {1,2,3,4};
    static const uint8_t ESPERADO[] = {1,2,3,4,0,0};
    uint8_t hora[6];
    clock_t reloj = ClockCreate(TICKS_PER_SECOND);
    ClockSetupTime(reloj, INICIAL, sizeof(INICIAL));
    TEST_ASSERT_TRUE( ClockGetTime(reloj, hora, sizeof(hora)));
    TEST_ASSERT_EQUAL_UINT8_ARRAY( ESPERADO, hora, sizeof(ESPERADO));
}