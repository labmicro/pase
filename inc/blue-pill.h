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

#ifndef EDU_CIAA_NXP_H
#define EDU_CIAA_NXP_H

/**
 * @file edu-ciaa-nxp.h
 * @brief EDU-CIAA-NXP board hardware declarations
 */

/* === Headers files inclusions ================================================================ */

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

#define GPIO_CHANEL_RED   HAL_GPIO_PA10
#define GPIO_CHANEL_GREEN HAL_GPIO_PA9
#define GPIO_CHANEL_BLUE  HAL_GPIO_PA8

#define GPIO_LED_RED      HAL_GPIO_PB9
#define GPIO_LED_YELLOW   HAL_GPIO_PB8
#define GPIO_LED_GREEN    HAL_GPIO_PB5

#define GPIO_KEY_LEFT     HAL_GPIO_PB4
#define GPIO_KEY_UP       HAL_GPIO_PB3
#define GPIO_KEY_RIGHT    HAL_GPIO_PB15
#define GPIO_KEY_DOWN     HAL_GPIO_PB14
#define GPIO_KEY_ACCEPT   HAL_GPIO_PB13
#define GPIO_KEY_CANCEL   HAL_GPIO_PB12

/* === Public data type declarations =========================================================== */

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* EDU_CIAA_NXP_H */
