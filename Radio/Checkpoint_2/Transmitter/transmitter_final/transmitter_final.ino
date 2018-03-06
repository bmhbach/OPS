#include "transmitter.h"

#define switchA 19
#define switchB 17
#define switchC 15

int buttonStateA = 0;
int buttonStateB = 0;
int buttonStateC = 0;
void setup() {
  Serial.begin(9600);
  transmitter_setup();
  pinMode(switchA, INPUT);  
  pinMode(switchB, INPUT);  
  pinMode(switchC, INPUT);  
}

void loop() {
  if (buttonStateA == LOW && digitalRead(switchA) == HIGH) //if previously off, communicate it is on when on
  {
    sending(1.2);
    //Serial.write(1);
    delay(100);
    buttonStateA = HIGH;
  }
  else if (digitalRead(switchA) == LOW) //if previously on, turn off when switch is released
    buttonStateA = LOW;
 
  if (buttonStateB == LOW && digitalRead(switchB) == HIGH)
  {
    sending(2.2);
    //Serial.write(2);
    delay(100);
    buttonStateB = HIGH;
  }
  else if (digitalRead(switchB) == LOW)
    buttonStateB = LOW;
  
  if (buttonStateC == LOW && digitalRead(switchC) == HIGH)
  {
    sending(9.2);
    //Serial.write(3);
    delay(100);
    buttonStateC = HIGH;
  }
  if (digitalRead(switchC) == LOW)
    buttonStateC = LOW;
  
}
