#include "unity.h"
#include "stdint.h"
#include <stdbool.h>
#include "clock.h"

#define TICKS_PER_SECOND 5

clock_t reloj;

void SimulateSeconds( int seconds){
        for (int i = 0; i < seconds * TICKS_PER_SECOND; i++){
        ClockNewTick(reloj);
    }
}

/**
 * @brief Funcion que Ceedling ejecuta antes de realizar cada una de las pruebas
 * 
 */
void setUp(void){
    static const uint8_t INICIAL[] = {1,2,3,4};
    reloj = ClockCreate(TICKS_PER_SECOND);
    ClockSetupTime(reloj, INICIAL, sizeof(INICIAL));
}

// Configurar la libreria, consultar la hora tiene que ser invalida.
void test_start_up(void){
    static const uint8_t ESPERADO[] = {0,0,0,0,0,0};
    uint8_t hora[6];
    reloj = ClockCreate(TICKS_PER_SECOND); // Recibe por params la cant. de pulsos de reloj que valen 1 segundo
    TEST_ASSERT_FALSE( ClockGetTime(reloj, hora, sizeof(hora)));
    TEST_ASSERT_EQUAL_UINT8_ARRAY( ESPERADO, hora, sizeof(ESPERADO));
}

// Configurar la libreria, ajustar la hora (con valores correctos), consultar la hora y tiene que ser valida.
void test_set_up_current_time(void){
    static const uint8_t ESPERADO[] = {1,2,3,4,0,0};
    uint8_t hora[6];
    TEST_ASSERT_TRUE( ClockGetTime(reloj, hora, sizeof(hora)));
    TEST_ASSERT_EQUAL_UINT8_ARRAY( ESPERADO, hora, sizeof(ESPERADO));
}

// Simular el paso de n ciclos de reloj, consultar la hora y verificar que avanzo un segundo 
void test_one_second_elapsed(void){
    static const uint8_t ESPERADO[] = {1,2,3,4,0,1};
    uint8_t hora[6];

    SimulateSeconds(1);
    ClockGetTime(reloj, hora, sizeof(hora));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, sizeof(ESPERADO));
}

// Simular el paso de n ciclos de reloj, consultar la hora y verificar que avanzo diez segundos 
void test_ten_second_elapsed(void){
    static const uint8_t ESPERADO[] = {1,2,3,4,1,0};
    uint8_t hora[6];
    
    SimulateSeconds(10);
    ClockGetTime(reloj, hora, sizeof(hora));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, sizeof(ESPERADO));
}

// Simular el paso de n ciclos de reloj, consultar la hora y verificar que avanzo 1 minuto 
void test_one_minute_elapsed(void){
    static const uint8_t ESPERADO[] = {1,2,3,5,0,0};
    uint8_t hora[6];
    
    SimulateSeconds(60);
    ClockGetTime(reloj, hora, sizeof(hora));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ESPERADO, hora, sizeof(ESPERADO));
}