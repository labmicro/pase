/************************************************************************************************
Copyright (c) 2022-2023, Laboratorio de Microprocesadores
Facultad de Ciencias Exactas y Tecnología, Universidad Nacional de Tucumán
https://www.microprocesadores.unt.edu.ar/

Copyright (c) 2022-2023, Esteban Volentini <evolentini@herrera.unt.edu.ar>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/**
 * @file press.c
 * @brief Press to test task unit test
 */

/* === Headers files inclusions =============================================================== */

#include "unity.h"
#include "press.h"
#include "mock_hal_gpio.h"

/* === Macros definitions ====================================================================== */

#define KEY_PRESSED  false

#define KEY_RELEASED true

#define LED_ON       true

#define LED_FF       false

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

hal_gpio_bit_t test_led;

hal_gpio_bit_t test_key;

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================= */

void test_no_pressed_key(void) {
    GpioGetState_ExpectAndReturn(test_key, KEY_PRESSED);
    GpioSetState_Expect(test_led, LED_ON);
    PressLed(test_key, test_led);
}

void test_pressed_key(void) {
    GpioGetState_ExpectAndReturn(test_key, KEY_RELEASED);
    GpioSetState_Expect(test_led, LED_OFF);
    PressLed(test_key, test_led);
}

/* === End of documentation ==================================================================== */
