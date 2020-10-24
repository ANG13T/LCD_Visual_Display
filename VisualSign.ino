#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
const int buttonPin = 3; //button input pin

int cursorX = 0;
int cursorY = 0;

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

char codeArray[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '.', '!'};
 char message[] = "Hello";


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
  Serial.print("cursor: ");
  Serial.print(cursorX);
  Serial.print(" , ");
  Serial.print(cursorY);
  Serial.println();
  lcd.setCursor(cursorX, cursorY); // Set the cursor on the first column and first row.
  lcd.blink();
//  lcd.print("Hello World!");
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
    int joyStickDirection = getJoystickValue(analogRead(X_pin), analogRead(Y_pin));
    moveCursor(joyStickDirection);
    delay(400);
}

int getJoystickValue(int xValue, int yValue){
  if(yValue>=900) return 0; //up
  if(yValue<=10) return 1; //down
  if(xValue<=10) return 2; //left
  if(xValue>=900) return 3; //right  
  return 4;
}

void moveCursor(int direction){
  switch(direction){
      //UP
      case 0: 
      Serial.println("UP");
      if(cursorY - 1 >= 0){
        cursorY--;
      }
      break; 

      //DOWN
      case 1:
      Serial.println("DOWN");
      if(cursorY + 1 < 2){
        cursorY++;
      }
      break; 

      //LEFT
      case 2:
      Serial.println("LEFT");
      if(cursorX - 1 >= 0){
        cursorX--;
      }
      break; 

      //RIGHT
      case 3:
      Serial.println("RIGHT");
      if(cursorX + 1 < 16){
        cursorX++;
      }
      break; 

      //MIDDLE
      case 4:
      break;
   }
}
