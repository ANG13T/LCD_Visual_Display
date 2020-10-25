# Customizable Visual Sign

This projects allows you to write your own custom message on a LCD display. The visual display consists of scrolling letters and colorful LEDS. Plus the display can be controlled by a remote controller!

## Materials

- Breadboard
- 2 LEDS
- 1 220ohm resistors
- Arduino Uno
- I2C LCD display
- IR sensor
- Joystick
- Push Button
- Around 20 - 30 jumper wires

## Schematic (excluding LCD and Joystick)

![design image](https://github.com/angelina-tsuboi/Object_Detector_Arduino/blob/main/images/design.png)

The CAD I was using didn't have the LCD (I2C) and Joystick. Wiring those two components should be pretty simple as long as you look over the source code.

## How It Works

Since this project contains many components, I will describe the functionalties of each component individually.

### Push Button Mechanism

 The digital pins of the Arduino detect the presence or abscence of voltage on a pin. The **digitalRead** function tells your program whether the pin is HIGH (5 volts) or LOW (0 volts). Sometimes circuits include pull up resistors (like in this case) that adjust the voltage that is sensed by digitalRead. For this project, the button is used to change the letter of a particular slot on the LCD. For example, lets assume the cursor is on slot (1, 2) of the LCD. If the letter on that slot is *A* we should get *B* when we press the button. A button contains a sealed mechanism which connects a small metal spring and a wire when it is pressed. This allows electricity to flow through the legs of the button. In this case, the Arduino detects the new presence of voltage and runs some code.

### IR Sensor

An IR sensor detects infared radiation within its vicinity. Infared Radiation cannot be seen with the human eye because its wavelengths are longer than than that of visible light. Anything that emits heat from its source gives off infared raditaion. For this project, the IR sensor is used to detect the infared radiation emitted from the remote controller to toggle the edit and view functions of the sketch.

### LCD Display Functionality

A Liquid Crystal Display or LCD for short is a flat panel display usually uses millions of tiny pixels which can either be red, blue or green that can be turned on and off very quickly in order to produce rapid/moving images (ie. TV, computers, phones, etc). In this case, we are controlling a very compact LCD (16 x 2) with only which only uses the color black. The LCD contains liquid crystal sandwiched between glass that reacts with the current applied to display specific characters. In this tutorial, I used a I2C LCD in order to make the wiring and programming easier. For this project, the functionality of the LCD is to act as a sign that scrolls letters (like the LED signs you see outside of stores). The text can also be customized as well!

### JoyStick

The goal of the joystick is to indicate a 2D motion to the Arduino. In order to accomplish this, the joystick includes 1 10K potentiometer for each axis that uses voltage dividers to communicate the 2 axis analog input. The Joystick uses a  [gimbal mechanism](https://core-electronics.com.au/tutorials/use-lcd-arduino-uno.html) to figure out the 2D axis. The analog input for each axis can range from 0 to 1023. Using this information, the sketch is able to change the position of the cursor based on the particular 2D input.

## Completed Project

![project photo](https://github.com/angelina-tsuboi/Object_Detector_Arduino/blob/main/images/photo.jpg)