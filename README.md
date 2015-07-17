dual-l293d-motor-arduino
========================
An Arduino-based dual L293d motor module communicating through i2c protocol.

Hardware
--------
- Arduino motor control shield V1
- Arduino Pro Mini

### Pin-Pin map
Shield|Arduino
-------|------
GND|GND
RESET|RESET
DIR_LATCH|12
DIR_EN|7
DIR_CLK|4
DIR_SER|8
PWM0A|6
PWM0B|5
PWM1A|9
PWM1B|10
PWM2A|11
PWM2B|3

Arduino Library
--------------

download from [AFMotor](https://github.com/adafruit/Adafruit-Motor-Shield-library/zipball/master)

1. Uncompress the ZIP file onto your desktop
2. Rename the uncompressed folder AFMotor
3. Check that inside AFMotor is AFMotor.cpp and AFMotor.h files. If not, check the steps above
4. Place the AFMotor folder into your arduinosketchfolder/libraries folder. For Windows, this will probably be something like MY Documents/Arduino/libraries for Mac it will be something likeDocuments/arduino/libraries. If this is the first time you are installing a library, you'll need to create the libraries folder. Make sure to call it libraries exactly, no caps, no other name.
5. Check that inside the libraries folder there is the AFMotor folder, and inside AFMotor isAFMotor.cpp AFMotor.h and some other files
6. Quit and restart the IDE. You should now have a submenu called File->Examples->AFMotor->MotorParty

Usage
-----

Connect i2c wire to Arduino, configure your device as i2c master, then you are ready to go.

i2c address: 0x10

make a write call and write 4 byte [reg, direction, speed high byte, speed low byte]
