#!/usr/bin/env python3
# -*- coding: utf-8 -*-

##################################################################################################
# Copyright (c) 2022-2023, Laboratorio de Microprocesadores
# Facultad de Ciencias Exactas y Tecnología, Universidad Nacional de Tucumán
# https://www.microprocesadores.unt.edu.ar/
#
# Copyright (c) 2022-2023, Esteban Volentini <evolentini@herrera.unt.edu.ar>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
# associated documentation files (the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge, publish, distribute,
# sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all copies or substantial
# portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
# NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
# OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2023, Esteban Volentini <evolentini@herrera.unt.edu.ar>
##################################################################################################

import os

from pytest import fixture
from siru.dut import DUT
from siru.preat import Result
from dut_utils import create_dut
from time import sleep


@fixture(scope="module", autouse=True)
def fixture():
    global dut
    dut = create_dut()


def execute(result):
    assert result == Result.NO_ERROR


def test_turn_led_on_first_key_press():
    execute(dut.key_rigth.clear())
    dut.restart()
    sleep(0.2)

    execute(
        dut.wait(
            0,
            200,
            [
                dut.led_green.has_falling,
            ],
            dut.key_rigth.set,
        )
    )


def test_turn_led_off_second_key_press():
    execute(dut.key_rigth.clear())
    dut.restart()
    sleep(0.2)

    execute(dut.key_rigth.set())
    sleep(0.2)
    execute(dut.key_rigth.clear())

    execute(dut.key_rigth.clear())
    execute(
        dut.wait(
            0,
            200,
            [
                dut.led_green.has_rising,
            ],
            dut.key_rigth.set,
        )
    )
