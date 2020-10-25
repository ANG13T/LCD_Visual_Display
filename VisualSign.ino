#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremoteInt.h>
#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
const int buttonPin = 3; //button input pin
const int IRpin = 4;
const int lightsPin = 5;

int cursorX = 0;
int cursorY = 0;

boolean lightsOn = false;

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4);

IRrecv receiver(IRpin);
decode_results results;

char codeArray[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
char topRow[16];
char bottomRow[16];


void setup() {
  // put your setup code here, to run once:
  pinMode(SW_pin, INPUT); //joystick inout
  pinMode(buttonPin, INPUT);//button input
  pinMode(lightsPin, OUTPUT);
  digitalWrite(lightsPin, LOW);
  digitalWrite(SW_pin, HIGH);
  receiver.enableIRIn();
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  intitializeBoard();

}

void loop() {
  lcd.setCursor(cursorX, cursorY); // Set the cursor on the first column and first row.
  lcd.blink();
  if(lightsOn){
    digitalWrite(lightsPin, HIGH);
  }else{
    digitalWrite(lightsPin, LOW);
  }
  int joyStickDirection = getJoystickValue(analogRead(X_pin), analogRead(Y_pin));
  moveCursor(joyStickDirection);
  if (digitalRead(buttonPin) == HIGH) {
    Serial.println("clicked button");
    setNextLetter(cursorY, cursorX);
  }

  if (receiver.decode(&results)) {
    Serial.println(results.value, HEX);
    lightsOn = !lightsOn;
    receiver.resume();
  }
  delay(200);
}

int getJoystickValue(int xValue, int yValue) {
  if (yValue >= 900) return 0; //up
  if (yValue <= 10) return 1; //down
  if (xValue <= 10) return 2; //left
  if (xValue >= 900) return 3; //right
  return 4;
}

void moveCursor(int direction) {
  switch (direction) {
    //UP
    case 0:
      Serial.println("UP");
      if (cursorY - 1 >= 0) {
        cursorY--;
      }
      break;

    //DOWN
    case 1:
      Serial.println("DOWN");
      if (cursorY + 1 < 2) {
        cursorY++;
      }
      break;

    //LEFT
    case 2:
      Serial.println("LEFT");
      if (cursorX - 1 >= 0) {
        cursorX--;
      }
      break;

    //RIGHT
    case 3:
      Serial.println("RIGHT");
      if (cursorX + 1 < 16) {
        cursorX++;
      }
      break;

    //MIDDLE
    case 4:
      break;
  }
}


void intitializeBoard() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 16; j++) {
      lcd.setCursor(i, j);
      lcd.print("");
    }
  }
  lcd.setCursor(0, 0);
}

void setNextLetter(int row, int index) {
  char currentLetter;
  int letterIndex;
  lcd.setCursor(index, row);
  if (row == 0) {
    currentLetter = topRow[index];
  } else {
    currentLetter = bottomRow[index];
  }

  letterIndex = getLetterIndex(currentLetter);
  int result;
  if (letterIndex + 1 < sizeof(codeArray)) {
    result = letterIndex + 1;
  } else {
    result = 0;
  }

  lcd.print(codeArray[result]);
  if (row == 0) {
    topRow[index] = codeArray[result];
  } else {
    bottomRow[index] = codeArray[result];
  }
}

int getLetterIndex(char letter) {
  for (int i = 0; i < sizeof(codeArray); i++) {
    if (codeArray[i] == letter) {
      return i;
    }
  }
  return 26;
}
