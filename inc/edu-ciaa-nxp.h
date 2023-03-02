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

#define GPIO_CHANEL_RED   HAL_GPIO2_1
#define GPIO_CHANEL_GREEN HAL_GPIO2_2
#define GPIO_CHANEL_BLUE  HAL_GPIO2_3

#define GPIO_LED_RED      HAL_GPIO1_8;
#define GPIO_LED_YELLOW   HAL_GPIO3_12;
#define GPIO_LED_GREEN    HAL_GPIO3_13;

#define GPIO_KEY_LEFT     HAL_GPIO3_14;
#define GPIO_KEY_UP       HAL_GPIO5_4;
#define GPIO_KEY_RIGHT    HAL_GPIO5_3;
#define GPIO_KEY_DOWN     HAL_GPIO5_8;
#define GPIO_KEY_ACCEPT   HAL_GPIO5_9;
#define GPIO_KEY_CANCEL   HAL_GPIO2_0;

/* === Public data type declarations =========================================================== */

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* EDU_CIAA_NXP_H */
