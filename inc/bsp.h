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

#ifndef BSP_H
#define BSP_H

/**
 * @file bsp.h
 * @brief Board support hardware abstraction layer declarations
 */

/* === Headers files inclusions ================================================================ */

#include "hal.h"

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

/**
 * @brief Structure with gpio outputs to drive an RGB led
 */
typedef struct led_rgb_s {
    hal_gpio_bit_t red;   /**< Gpio output used to drive red channel of RGB led */
    hal_gpio_bit_t green; /**< Gpio output used to drive green channel of RGB led */
    hal_gpio_bit_t blue;  /**< Gpio output used to drive blue channel of RGB led */
} const * const led_rgb_t;

/**
 * @brief Structure with gpio outputs to drive an RGB led
 */
typedef struct leds_s {
    hal_gpio_bit_t red;    /**< Gpio output used to drive red channel of RGB led */
    hal_gpio_bit_t yellow; /**< Gpio output used to drive blue channel of RGB led */
    hal_gpio_bit_t green;  /**< Gpio output used to drive green channel of RGB led */
} const * const leds_t;

/**
 * @brief Structure with gpio outputs to drive an RGB led
 */
typedef struct keys_s {
    hal_gpio_bit_t up;     /**< Gpio output used to read status of key up on board */
    hal_gpio_bit_t left;   /**< Gpio output used to read status of key left on board */
    hal_gpio_bit_t right;  /**< Gpio output used to read status of key right on board */
    hal_gpio_bit_t down;   /**< Gpio output used to read status of key down on board */
    hal_gpio_bit_t accept; /**< Gpio output used to read status of key accept on board */
    hal_gpio_bit_t cancel; /**< Gpio output used to read status of key cancel on board */
} const * const keys_t;

/**
 * @brief Structure with gpio terminals usted by board
 */
typedef struct board_s {
    struct led_rgb_s led_rgb[1]; /**< Structure with gpio output used by RGB led */
    struct leds_s leds[1];       /**< Structure with gpio output used by RGB led */
    struct keys_s keys[1];       /**< Structure with gpio output used by RGB led */
} const * board_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Function to initialize the board and create an descriptor to his resources
 *
 * @return  board_t  Pointer to descriptor with board resources
 */
board_t BoardCreate(void);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* BSP_H */
