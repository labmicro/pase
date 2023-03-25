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
 * @file bsp.c
 * @brief Board support hardware abstraction layer implementation
 */

/* === Headers files inclusions =============================================================== */

#include "bsp.h"
#include "board.h"
#include <string.h>

#if defined(EDU_CIAA_NXP)
#include "edu-ciaa-nxp.h"
#elif defined(BLUE_PILL)
#include "blue-pill.h"
#else
#error "This program does not have support for the selected board"
#endif

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/**
 * @brief Function to init structu with board hardware resources definition
 *
 * @return  board_t     Pointer to board resources definition
 */
static board_t AssignResources(void);

/**
 * @brief Function to configure board hardware resources
 *
 * @param   board       Pointer to board resources definition
 */
static void ConfigHardware(board_t board);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

static board_t AssignResources(void) {
    static struct board_s board[1];

    board->led_rgb->red = GPIO_CHANEL_RED;
    board->led_rgb->green = GPIO_CHANEL_GREEN;
    board->led_rgb->blue = GPIO_CHANEL_BLUE;

    board->leds->red = GPIO_LED_RED;
    board->leds->yellow = GPIO_LED_YELLOW;
    board->leds->green = GPIO_LED_GREEN;

    board->keys->left = GPIO_KEY_LEFT;
    board->keys->up = GPIO_KEY_UP;
    board->keys->right = GPIO_KEY_RIGHT;
    board->keys->down = GPIO_KEY_DOWN;
    board->keys->accept = GPIO_KEY_ACCEPT;
    board->keys->cancel = GPIO_KEY_CANCEL;

    return (board_t)board;
}

static void ConfigHardware(board_t board) {
    GpioSetDirection(board->led_rgb->red, true);
    GpioSetDirection(board->led_rgb->green, true);
    GpioSetDirection(board->led_rgb->blue, true);

    GpioSetDirection(board->leds->red, true);
    GpioSetDirection(board->leds->yellow, true);
    GpioSetDirection(board->leds->green, true);

    GpioSetDirection(board->keys->left, false);
    GpioSetDirection(board->keys->up, false);
    GpioSetDirection(board->keys->right, false);
    GpioSetDirection(board->keys->down, false);
    GpioSetDirection(board->keys->accept, false);
    GpioSetDirection(board->keys->cancel, false);
}

/* === Public function implementation ========================================================= */

board_t BoardCreate(void) {
    board_t board;

    BoardSetup();

    board = AssignResources();
    ConfigHardware(board);

    return board;
}

/* === End of documentation ==================================================================== */
