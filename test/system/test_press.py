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
import serial.tools.list_ports

from pytest import fixture
from siru.dut import DUT
from siru.preat import Result


@fixture(scope="module", autouse=True)
def fixture():
    global dut

    dut = DUT(yaml="test/config/dut_edu_ciaa_nxp.yaml")
    location = os.environ.get("ATE_LOCATION", None)
    ports = serial.tools.list_ports.comports()
    print(
        f"List of USB ports: "
        + ",".join([f"{port.device}: {port.location}" for port in ports])
    )
    ports = [port.device for port in ports if str(port.location).startswith(location)]
    print(
        f"List of filtered ports: "
        + ",".join([f"{port.device}: {port.location}" for port in ports])
    )
    if ports:
        dut.ate.url = ports[0]
    print(f"Using ATE at {dut.ate.url}")


def exectute(result):
    assert result == Result.NO_ERROR


def test_turn_on_red_led_on_press_left_key():
    exectute(dut.key_left.clear())
    exectute(dut.wait(0, 200, [dut.led_green.has_falling], dut.key_rigth.set))


def test_turn_on_red_led_on_release_left_key():
    exectute(dut.key_left.set())
    exectute(dut.wait(0, 200, [dut.led_green.has_rising], dut.key_rigth.clear))
