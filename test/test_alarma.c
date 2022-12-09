#include "unity.h"
#include "stdint.h"
#include <stdbool.h>
#include "clock.h"

#define TICKS_PER_SECOND 5

clock_t reloj;

bool alarm_state;

void SimulateSeconds( int seconds){
        for (int i = 0; i < seconds * TICKS_PER_SECOND; i++){
        ClockNewTick(reloj);
    }
}

void AlarmEventHandler(clock_t clock, bool state){
    alarm_state = state;
}

/**
 * @brief Funcion que Ceedling ejecuta antes de realizar cada una de las pruebas
 * 
 */
void setUp(void){
    static const uint8_t INICIAL[] = {1,2,3,4};
    reloj = ClockCreate(TICKS_PER_SECOND, AlarmEventHandler);
    ClockSetupTime(reloj, INICIAL, sizeof(INICIAL));
    alarm_state = false;
}

void test_start_up(void){
    static const uint8_t ESPERADO[] = {0,0,0,0,0,0};
    uint8_t hora[6];
    reloj = ClockCreate(TICKS_PER_SECOND, AlarmEventHandler); // Recibe por params la cant. de pulsos de reloj que valen 1 segundo
    TEST_ASSERT_FALSE( ClockGetTime(reloj, hora, sizeof(hora)));
    TEST_ASSERT_EQUAL_UINT8_ARRAY( ESPERADO, hora, sizeof(ESPERADO));
}

//Configurar la hora de la alarmar (con valores correctos), revisar si la guarda y si queda activada.
void test_setup_and_get_alarm(void) {
    static const uint8_t ALARMA[] = {1,2,3,5};
    uint8_t hora[4];

    ClockSetupAlarm(reloj, ALARMA, sizeof(ALARMA));
    TEST_ASSERT_TRUE(ClockGetAlarm(reloj, hora, sizeof(hora)));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ALARMA, hora, sizeof(ALARMA));    
}

// Si la alarma esta activa y la desactivo, queda desactivada pero no cambia la hora. 
void test_setup_and_disabled_alarm(void) {
    static const uint8_t ALARMA[] = {1,2,3,5};
    uint8_t hora[4];

    ClockSetupAlarm(reloj, ALARMA, sizeof(ALARMA));
    TEST_ASSERT_FALSE(ClockToggleAlarm(reloj));
    TEST_ASSERT_FALSE(ClockGetAlarm(reloj, hora, sizeof(hora)));
    TEST_ASSERT_EQUAL_UINT8_ARRAY(ALARMA, hora, sizeof(ALARMA));    
}

void test_setup_and_fired_alarm(void) {
    static const uint8_t ALARMA[] = {1,2,3,5};

    ClockSetupAlarm(reloj, ALARMA, sizeof(ALARMA));
    SimulateSeconds(60);
    TEST_ASSERT_TRUE(alarm_state);
    alarm_state = false;
    SimulateSeconds(10);
    TEST_ASSERT_FALSE(alarm_state);
}

void test_setup_and_not_fired_alarm(void) {
    static const uint8_t ALARMA[] = {1,2,3,5};

    ClockSetupAlarm(reloj, ALARMA, sizeof(ALARMA));
    ClockToggleAlarm(reloj);

    SimulateSeconds(60);
    TEST_ASSERT_FALSE(alarm_state);
}