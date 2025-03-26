# HID-injection-for-spam-jam

✨✨✨ an ekoms and m0usem0use bluetooth production in conjuction with the makers of Jam_fi your scariest wifi fren ✨✨✨

 Bluetooth HID Injection for spam jam and GeeekPi nRF52840 USB Dongle

The GeeekPi nRF52840 USB Dongle is actually a great choice for Bluetooth HID injection. It’s based on the Nordic nRF52840 chip,
WHICH:

Fully supports Bluetooth Low Energy (BLE)

Can emulate Bluetooth HID devices like keyboards and mice

Is compatible with Adafruit's CircuitPython, nRF Connect SDK, and ZMK / Zephyr OS

Has existing support for HID over GATT (HoG) — which is how those stealthy keyboard injections work!

✅ Step 1: Install Adafruit Bootloader
📦 Needed Tools:

Zadig for USB driver installation (Windows only)

nrfutil for flashing

The Adafruit nRF52 Bootloader .zip from here:

https://github.com/adafruit/Adafruit_nRF52_Bootloader/releases

🧪 Instructions :

1. Hold down the reset button and plug the dongle in (it should appear as "DFU mode" or "Unknown USB").

2. Use Zadig to replace the driver with libusb-win32 or WinUSB.

3. Flash the Adafruit bootloader:

nrfutil dfu usb-serial -pkg adafruit_nrf52_bootloader.zip -p COMX

(Replace COMX with the correct port shown in Device Manager)

Once successful, the dongle should reboot and appear as a USB mass storage device.

✅ Step 2: Load a HID Payload in CircuitPython

1. Once you have CircuitPython installed on the dongle (shows up as CIRCUITPY), create this file:

# code.py

import time
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode

kbd = Keyboard(usb_hid.devices)

time.sleep(2)
kbd.send(Keycode.WINDOWS, Keycode.R)
time.sleep(0.5)
kbd.write("notepad\n")
time.sleep(0.5)
kbd.write("HACK THE PLANET 💻✨🌍\n")

2. Save it, eject the drive, and plug the dongle into a test machine with Bluetooth HID support (can test wired first).

NEXT WE WILL :

✅ Confirm the Adafruit bootloader was flashed

✅ Confirm CircuitPython is working

✅ Test HID injection (wired or Bluetooth, depending on available firmware)

If this works, we’ll move on to BLE HID injection using nrf Connect SDK or a custom SoftDevice-based payload. Our final goal is:

🎯 Spam Jam Feature Goal:

A menu to detect compatible nRF52840 dongles

Flash + inject HID BLE payloads wirelessly

Choose from payloads (Notepad, reverse shell, browser macros, emoji spam 💖)

Toggle BLE keyboard mode inside Spam Jam




