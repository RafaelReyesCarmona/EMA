<img src="img/electric-meter.png" width=48 height=48 align="right">

# ACS712_Hall #

[![Library: ACS712](https://img.shields.io/badge/Library-ACS712_Hall-red?style=for-the-badge&logo=Arduino)](README.md)
[![Version: v0.1](https://img.shields.io/badge/Version-v0.1-blue?style=for-the-badge&logo=v)]()

Arduino library for ACS Current Sensor Hall Effect- 5A, 20A and 30A models.
## Installation ##

### Arduino IDE ###

For a tutorial on how to install new libraries for use with the Arduino
development environment please refer to the following website:
http://www.arduino.cc/en/Reference/Libraries

--- or ---

1. Download the ZIP file from the page [releases](https://github.com/RafaelReyesCarmona/ACS712_Hall/releases) to your machine.
<p align=center>
<img src="img/Download_latest.png" alt="Download latest version of library" width=600>
</p>

2. In the Arduino IDE, choose Sketch/Include Library/Add Zip Library.
<p align=center>
<img src="img/Add_library.png" alt="Add library Arduino IDE" width=600>
</p>

3. Navigate to the ZIP file, and click Open.

### PlatformIO ###

How to use the library in PlatformIO see [documentation](https://docs.platformio.org/en/latest/librarymanager/index.html) of Library Manager.

The only one simple step is to define dependencies in “platformio.ini” (Project Configuration File). For example,

```
# platformio.ini – project configuration file

[env:my_build_env]
platform = atmelavr
framework = arduino
lib_deps =
  # RECOMMENDED
  # Accept new functionality in a backwards compatible manner and patches
  rafaelreyescarmona/ACS712_Hall @ ^0.1

  # Accept only backwards compatible bug fixes
  # (any version with the same major and minor versions, and an equal or greater patch version)
  rafaelreyescarmona/ACS712_Hall @ ~0.1

  # The exact version
  rafaelreyescarmona/ACS712_Hall @ 0.1
```

For Manual installation in PlatformIO Core:

1. Run a terminal and type for search the library: 
```
pio lib search ACS712_Hall
```
<p align=center>
<img src="img/PlatformIO_3.png" alt="PlatformIO Search command" width=600>
</p>

2. Type for install:
```
pio lib install 12212
```

--- or ---

1. Search "ACS712\_Hall" in search box of _Libraries_ of panel.
<p align=center>
<img src="img/PlatformIO_1.png" alt="PlatformIO Search screen" width=600>
</p>

2. Click _Add to project_ button. Library will be included in the project and "platformio.ini" updated.
<p align=center>
<img src="img/PlatformIO_2.png" alt="PlatformIO Add library" width=600>
</p>

## How to use the library ##

In Arduino IDE, Choose Sketch/Include Library/Scroll and select "ACS712_Hall".
<p align=center>
<img src="img/Using_library_1.png" alt="Using library in Arduino IDE" width=600>
</p>

There are a two examples files with the library. In the Arduino IDE, choose File/Examples/ACS712_Hall, and you can see "ACS712_Hall".

<p align=center>
<img src="img/Arduino_examples.png" alt="Examples files" width=600>
</p>

--- or ---

Example of use:

```C++
/**
 * Example sketch for the ACS712_Hall library.
 */

 #include <ACS712_Hall.h>

 ACS712 sensor(A0, ACS712_05B,5.051);
 //ACS712 sensor1(A0, ACS712_05B,5.051);

 void setup(void){
   Serial.begin(57600);
 //  sensor.setADC(4096);
 //  sensor.analogRef(INTERNAL4V096);      //analogReference(INTERNAL4V096);

 //  sensor.setADC(4096);
 //  analogReadResolution(11);             // Only work with analogRead().
 
 //  sensor.setADC(512);
 //  analogReadResolution(9);             // Only work with analogRead().
 }

 void loop(void){
   float current_lowNoise = sensor.getCurrent_DC_LowNoise();
   Serial.print("Sensor (LowNoise)- current is ");
   Serial.print(current_lowNoise);
   Serial.println(" mA.");
   delay(250);
/*
   float current = sensor1.getCurrent_DC();
   Serial.print("Sensor (AnalogRead)- current is ");
   Serial.print(current);
   Serial.println(" mA.");
   delay(250);
 */
}
```

## License ##

This file is part of ACS712_Hall Library.

ACS712_Hall Library is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

ACS712_Hall Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with ACS712_Hall Library.  If not, see <https://www.gnu.org/licenses/>.

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](LICENSE)

## Authors ##

Copyright © 2021 Francisco Rafael Reyes Carmona.
Contact me: rafael.reyes.carmona@gmail.com

## Credits ##

Electric meter icon at the beginning is from [Flaticon.es](https://www.flaticon.es) designed by [DinosoftLabs
](https://www.flaticon.com/authors/dinosoftlabs)
and licensed by [free license](img/license-37862535.pdf).
