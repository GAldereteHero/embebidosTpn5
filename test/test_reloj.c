#include "unity.h"
#include "stdint.h"
#include <stdbool.h>
#include "clock.h"

// Configurar la libreria, consultar la hora tiene que ser invalida.
void test_hora_inicial_invalida(void){
    static const uint8_t ESPERADO[] = {0,0,0,0,0,0};
    uint8_t hora[6];
    clock_t reloj = ClockCreate(5); // Recibe por params la cant. de pulsos de reloj que valen 1 segundo
    TEST_ASSERT_FALSE( ClockGetTime(reloj, hora, 6));
    TEST_ASSERT_EQUAL_UINT8_ARRAY( ESPERADO, hora, 6);
}

