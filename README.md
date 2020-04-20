![digiQuack logo](/images/logo.png)

# digiQuack
digiQuack is an easy DuckyScript to DigiSpark payload converter based on C++. It contains various features including full DuckyScript language support, execution limiter, DigiSpark memory optimizations and more. Note though that currently support of foreign keyboard layouts (not english ones) is rather spotty, so try it out and see if it works out for yourself. The code is well documented with comments so feel free to take a look for yourself.


## Instructions - Online (Recommended) 🌐
You can use digiQuack by visiting the [converter website](https://cedarctic.github.io/digiQuack/).

## Instructions - Local 💻
![screenshot](/images/screenshot.png)

Just download one of the releases or download the source (digiQuack.cpp) and compile it yourself.

>Linux/Mac OS users: use ./digiQuack in the terminal to run and follow the prompt.

>Windows users: Run the digiQuack.exe. Drag and drop the txt file with the payload you want to convert and follow the prompt.

The converted file will be placed in the scripts' directory (or for macOS under the user directory) and will be named converted.txt. You can then follow seytonic's tutorial (in the credits) to install it on your digispark.

## Video Tutorial on using the tool locally:

[![Convert Ducky Scripts to Digispark](https://img.youtube.com/vi/YXWxEzLHXuw/0.jpg)](https://www.youtube.com/watch?v=YXWxEzLHXuw)

## Downloads

See the releases page to get the latest version: https://github.com/CedArctic/digiQuack/releases/ 

## Digispark Scripts

In case you want to play around with some of my Digispark scripts, you can find them here:
>https://github.com/CedArctic/DigiSpark-Scripts

## Convert to Python Scripts

Want to convert Ducky Scripts to Python applications? Check out ducky2python:
>https://github.com/CedArctic/ducky2python

## Credits/Resources
- Keyboard usage IDs: www.usb.org/developers/hidpage/Hut1_12v2.pdf
- Seytonic's tutorial: https://www.youtube.com/watch?v=fGmGBa-4cYQ
- Kevin Mitnik for pointing out the 'F' improvement: https://www.youtube.com/watch?v=IRSK_DNYL8Q
- hak5darren for the USB Rubber Ducky Documentation: https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Duckyscript
- Digistump for the DigiSpark and their documentation: https://github.com/digistump/DigisparkArduinoIntegration/blob/master/libraries/DigisparkKeyboard/DigiKeyboard.h
- AntyStewie for optimizations
