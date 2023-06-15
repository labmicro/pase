import os
from time import sleep
from siru.dut import DUT

config = os.environ.get("TEST_CFG", "test/config/dut_edu_ciaa_nxp.yaml")
dut = DUT(yaml=config)
dut.ate.server.url = f"usb://{os.environ.get('ATE_LOCATION','1-1.1')}"
print(f"Testing DUT {dut.name} with ATE {dut.ate.name} at {dut.ate.server.url}")
dut.monitor.verbose = True
dut.restart()

# OK EDU-CIAA-NXP, FAIL BLUE-PILL
dut.key_left.clear()
dut.wait(0, 200, [dut.led_red.has_falling], dut.key_left.set)
# OK EDU-CIAA-NXP, FAIL BLUE-PILL
dut.key_left.set()
dut.wait(0, 200, [dut.led_red.has_rising], dut.key_left.clear)

# OK EDU-CIAA-NXP
dut.key_rigth.clear()
dut.wait(0, 10000, [dut.led_green.has_falling], dut.key_rigth.set)
# OK EDU-CIAA-NXP
dut.key_rigth.set()
dut.wait(0, 200, [dut.led_green.has_rising], dut.key_rigth.clear)


dut.key_left.clear()
dut.restart()
sleep(0.2)
dut.wait(
    0,
    200,
    [
        dut.led_red.has_falling,
    ],
    dut.key_left.set,
)

"""
# BLUE-PILL
export ATE_LOCATION="1-1.3"
export USB_LOCATION="1-1.1"
export TEST_CFG="test/config/dut_blue_pill.yaml"
export OCD_CFG="muju/external/base/mcu/stm32f103c8/openocd/openocd.cfg"
export DUT_OCD_CFG="muju/external/base/mcu/stm32f103c8/openocd/openocd.cfg"

openocd -c "adapter usb location $USB_LOCATION" -f "$OCD_CFG" -c "init" -c "reset run" -c "shutdown"

# EDU-CIAA-NXP
export ATE_LOCATION="1-1.2"
export USB_LOCATION="1-1.4"
export TEST_CFG="test/config/dut_edu_ciaa_nxp.yaml"
export OCD_CFG="muju/external/base/mcu/lpc4337-m4/openocd/openocd.cfg"
openocd -c "adapter usb location $USB_LOCATION" -f "$OCD_CFG" -c "init" -c "reset run" -c "shutdown"
openocd -c "adapter usb location $ATE_LOCATION" -f "$OCD_CFG" -c "init" -c "reset run" -c "shutdown"
"""
