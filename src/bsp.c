/* Copyright 2022, Laboratorio de Microprocesadores 
 * Facultad de Ciencias Exactas y Tecnología 
 * Universidad Nacional de Tucuman
 * http://www.microprocesadores.unt.edu.ar/
 * Copyright 2022, Esteban Volentini <evolentini@herrera.unt.edu.ar>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/** @file plantilla.c
 **
 ** @brief Plantilla de archivos fuente
 **
 ** Plantilla para los archivos de codigo fuente de prácticos de las 
 ** asignaturas Diseño Integrado de Sistemas Emebebidos y Sistemas Embebidos
 ** de Tiempo Real dictadas en de la Especialización en Integración de
 ** Sistemas Informaticos de la Univesidad Nacional de Tucumán
 ** 
 ** | RV | YYYY.MM.DD | Autor       | Descripción de los cambios              |
 ** |----|------------|-------------|-----------------------------------------|
 ** |  1 | 2022.08.27 | evolentini  | Version inicial del archivo             |
 ** 
 ** @defgroup plantilla Plantilals de Archivos
 ** @brief Plantillas de archivos normalizadas
 ** @{ 
 */

/* === Inclusiones de cabeceras ============================================ */
#include "chip.h"
#include "bsp.h"
#include "poncho.h"

/* === Definicion y Macros privados ======================================== */



/* === Declaraciones de tipos de datos privados ============================ */

static struct board_s board = {0};

/* === Definiciones de variables privadas ================================== */

/* === Definiciones de variables publicas ================================== */

/* === Declaraciones de funciones privadas ================================= */

/* === Definiciones de funciones privadas ================================== */

/* === Definiciones de funciones publicas ================================== */

board_t BoardCreate(void){

    Chip_SCU_PinMuxSet(LED_R_PORT, LED_R_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_R_FUNC);
    board.ledRed = DigitalOutputCreate(LED_R_GPIO, LED_R_BIT);

    Chip_SCU_PinMuxSet(LED_G_PORT, LED_G_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_G_FUNC);
    board.ledGreen = DigitalOutputCreate(LED_G_GPIO, LED_G_BIT);

    Chip_SCU_PinMuxSet(LED_B_PORT, LED_B_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_B_FUNC);
    board.ledBlue = DigitalOutputCreate(LED_B_GPIO, LED_B_BIT);

    Chip_SCU_PinMuxSet(LED_1_PORT, LED_1_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_1_FUNC);
    board.ledRojo = DigitalOutputCreate(LED_1_GPIO, LED_1_BIT);

    Chip_SCU_PinMuxSet(LED_2_PORT, LED_2_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_2_FUNC);
    board.ledAmar = DigitalOutputCreate(LED_2_GPIO, LED_2_BIT);

    Chip_SCU_PinMuxSet(LED_3_PORT, LED_3_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | LED_3_FUNC);
    board.ledVerde = DigitalOutputCreate(LED_3_GPIO, LED_3_BIT);
    
    Chip_SCU_PinMuxSet(TEC_F1_PORT, TEC_F1_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TEC_F1_FUNC);
    board.setTime = DigitalInputCreate(TEC_F1_GPIO, TEC_F1_BIT, false);
    
    Chip_SCU_PinMuxSet(TEC_F2_PORT, TEC_F2_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TEC_F2_FUNC);
    board.setAlarm = DigitalInputCreate(TEC_F2_GPIO, TEC_F2_BIT, false);

    Chip_SCU_PinMuxSet(TEC_F3_PORT, TEC_F3_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TEC_F3_FUNC);
    board.decrement = DigitalInputCreate(TEC_F3_GPIO, TEC_F3_BIT, false);

    Chip_SCU_PinMuxSet(TEC_F4_PORT, TEC_F4_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TEC_F4_FUNC);
    board.increment = DigitalInputCreate(TEC_F4_GPIO, TEC_F4_BIT, false);

    Chip_SCU_PinMuxSet(TEC_ACCEPT_PORT, TEC_ACCEPT_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TEC_ACCEPT_FUNC);
    board.accept = DigitalInputCreate(TEC_ACCEPT_GPIO, TEC_ACCEPT_BIT, false);

    Chip_SCU_PinMuxSet(TEC_CANCEL_PORT, TEC_CANCEL_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_PULLUP | TEC_CANCEL_FUNC);
    board.cancel = DigitalInputCreate(TEC_CANCEL_GPIO, TEC_CANCEL_BIT, false);

    Chip_SCU_PinMuxSet(BUZZER_PORT, BUZZER_PIN, SCU_MODE_INBUFF_EN | SCU_MODE_INACT | BUZZER_FUNC);
    board.buzzer = DigitalOutputCreate(BUZZER_GPIO, BUZZER_BIT);

    return &board;
}


/* === Ciere de documentacion ============================================== */

/** @} Final de la definición del modulo para doxygen */

