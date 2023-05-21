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
 * @file test_toggle.c
 * @brief Press to toggle task unit test
 */

/* === Headers files inclusions =============================================================== */

#include "common.h"
#include "toggle.h"
#include "mock_hal_gpio.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

hal_gpio_bit_t test_led;

hal_gpio_bit_t test_key;

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================= */

void setUp(void) {
    // Simulate the key release to set the static variable to a known state
    GpioGetState_IgnoreAndReturn(KEY_RELEASED);
    ToggleLed(test_key, test_led);
}

void test_press_key_once_time(void) {
    GpioGetState_ExpectAndReturn(test_key, KEY_PRESSED);
    GpioBitToggle_Expect(test_led);

    ToggleLed(test_key, test_led);
}

void test_press_key_once_time_even_on_long_time_pressed(void) {
    GpioGetState_ExpectAndReturn(test_key, KEY_PRESSED);
    GpioBitToggle_Expect(test_led);
    GpioGetState_ExpectAndReturn(test_key, KEY_PRESSED);
    GpioGetState_ExpectAndReturn(test_key, KEY_PRESSED);

    CallInLoop(ToggleLed(test_key, test_led), 3);
}

void test_press_key_tow_times(void) {
    GpioGetState_ExpectAndReturn(test_key, KEY_PRESSED);
    GpioBitToggle_Expect(test_led);
    GpioGetState_ExpectAndReturn(test_key, KEY_RELEASED);
    GpioGetState_ExpectAndReturn(test_key, KEY_PRESSED);
    GpioBitToggle_Expect(test_led);

    CallInLoop(ToggleLed(test_key, test_led), 3);
}

/* === End of documentation ==================================================================== */
