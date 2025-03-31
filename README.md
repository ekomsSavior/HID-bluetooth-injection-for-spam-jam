# HID-Bluetooth keyboard injection

✨✨✨ an ekoms and m0usem0use bluetooth production in conjuction with the makers of Jam_fi your scariest wifi fren ✨✨✨

 Bluetooth HID keyboard injection for GeeekPi nRF52840 USB Dongle

The GeeekPi nRF52840 USB Dongle is actually a great choice for Bluetooth HID injection. It’s based on the Nordic nRF52840 chip,
WHICH:

Can emulate Bluetooth HID devices like keyboards and mice

Step-by-Step Setup

✅Step 1: Install Arduino IDE (install on your host machine if you're running a vm linux)

If you don’t have it yet:

bash-

sudo apt update

sudo apt install arduino

💻 Or grab it from https://www.arduino.cc/en/software

✅ Step 2: insert nRF52840 dongle into usb 2.0 port 

✅ Step 3: 

Open Preferences

Go to:

File > Preferences

Additional Board URLs

Make sure this exact line is there:

[https://www.adafruit.com/package_adafruit_index.json](https://adafruit.github.io/arduino-board-index/package_adafruit_index.json
)

Restart Arduino IDE

✅ Step 4: Install the Board Package

In Arduino IDE go to:

Tools > Board > Boards Manager

In the search bar, type:

nrf52

You’ll see “Adafruit nRF52 by Adafruit”.

Click Install ✅

Go to: 

Tools > Board > Adafruit Feather nRF52840 Express

Find com port:

Go to:

Tools > Port

choose com3 

paste your choice of sketch found in main page of repository into arduino 

go to:

sketch tab  

choose 

upload 

-----------------------------------------------

After upload, it should advertise as: SpamJam_HID

On your phone or test PC:

Pair with SpamJam_HID

It will type: Hello from Spam Jam! and press Enter

Next Steps for this project:

Once you confirm it types stuff when paired: ✅

customize the payload (PowerShell commands, downloaders, fake login prompts, etc.)

let user choose payload type windows, mac or linux.

Add a menu in Spam Jam to let the user trigger attacks from Kali 









