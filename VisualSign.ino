#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
const int buttonPin = 3; //button input pin

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

void setup() {
  // put your setup code here, to run once:
  pinMode(SW_pin, INPUT); //joystick inout
  pinMode(buttonPin, INPUT);//button input
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  
  lcd.setCursor(0, 0); // Set the cursor on the first column and first row.
  lcd.print("Hello World!");
  // put your main code here, to run repeatedly:
//  Serial.print("Switch:  ");
//  Serial.print(digitalRead(SW_pin));
//  Serial.print("\n");
//  Serial.print("X-axis: ");
//  Serial.print(analogRead(X_pin));
//  Serial.print("\n");
//  Serial.print("Y-axis: ");
//  Serial.println(analogRead(Y_pin));
//  Serial.print("\n\n");
//  delay(500);
    Serial.println(digitalRead(buttonPin));
}
