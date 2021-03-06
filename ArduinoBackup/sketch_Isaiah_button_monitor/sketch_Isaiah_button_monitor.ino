/*
 * Project: Using OneButton library
 * Description: Introduct Students to OneButton Library using 2 buttons
 * Author: Brian A Rashap
 * Date: 13-Dec-2019
 */

#include <OneButton.h>

// Setup OneButton on pin 23 and pin 16
OneButton button1(23, false); 

// LED pin configure
int ledPin = 5;

int buttonState = LOW;
int flash = LOW;





void setup() {
Serial.begin(9600);
  while (!Serial); 

  pinMode(ledPin, OUTPUT);

  // link the button 1 functions.
  button1.attachClick(click1);
  button1.attachDoubleClick(doubleclick1);
  button1.attachLongPressStart(longPressStart1);
  button1.attachLongPressStop(longPressStop1);
  //button1.attachDuringLongPress(longPress1);
  button1.setClickTicks(250);
  button1.setPressTicks(2000);

  if(Serial) Serial.println("Starting oneButtonLED...");

}

void loop() {
  // keep watching the push buttons:
  button1.tick();

    if (buttonState == LOW) {
      digitalWrite(ledPin, LOW);
    }
      else {
        digitalWrite(ledPin, HIGH);
      }
    }
    
} 


// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time
void click1() {
  Serial.println("Button 1 click.");
  buttonState = !buttonState;
  Serial.print("buttonState = ");
  Serial.println(buttonState);
  
} // click1


// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() {
  Serial.println("Button 1 doubleclick.");
  flash = !flash;
  Serial.print("flash = ");
  Serial.println(flash);
} // doubleclick1


// This function will be called once, when the button1 is pressed for a long time.
void longPressStart1() {
  Serial.println("Button 1 longPress start");
} // longPressStart1


// This function will be called often, while the button1 is pressed for a long time.
void longPress1() {
  Serial.println("Button 1 longPress...");
} // longPress1


// This function will be called once, when the button1 is released after beeing pressed for a long time.
void longPressStop1() {
  Serial.println("Button 1 longPress stop");
} // longPressStop1
