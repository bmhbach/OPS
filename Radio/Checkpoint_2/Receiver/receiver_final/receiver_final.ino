#include "receiver.h"

bool waitingForInput = false;
#define RED 12
#define GREEN 11
#define YELLOW 10

byte randomSequence[50];
int sequenceLength = 0;
int sequencePosition = 0;
//byte code = 0;
float floatCode;
int code = 0;

void flashRed();
void flashGreen();

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  randomSeed(analogRead(0));
  receiver_setup();
}

void loop() {
  if(!waitingForInput)
  {
    waitingForInput = true;
    int r = random(1, 4);
    randomSequence[sequenceLength] = r;
    sequenceLength++;
    for(int i = 0; i < sequenceLength; i++)
    {
      switch(randomSequence[i])
       {
         case 1: digitalWrite(RED, HIGH); delay(500); digitalWrite(RED, LOW); delay(500); break;
         case 2: digitalWrite(GREEN, HIGH); delay(500); digitalWrite(GREEN, LOW); delay(500); break;
         case 3: digitalWrite(YELLOW, HIGH); delay(500); digitalWrite(YELLOW, LOW); delay(500); break;
       }
    }
  }

  else if(receiving(floatCode) && sequencePosition < sequenceLength)
  {
    //code = Serial.read();
    if(floatCode == -13107)
      code = 2;
    else if(floatCode == 13107)
      code = 3;
    else if(floatCode == -26124)
      code = 1;
    delay(100);
    if(code == randomSequence[sequencePosition])
    {
      switch(code)
       {
         case 1: digitalWrite(RED, HIGH); delay(500); digitalWrite(RED, LOW); delay(500); break;
         case 2: digitalWrite(GREEN, HIGH); delay(500); digitalWrite(GREEN, LOW); delay(500); break;
         case 3: digitalWrite(YELLOW, HIGH); delay(500); digitalWrite(YELLOW, LOW); delay(500); break;
       }
       sequencePosition++;
    }
    else
       flashRed();
  }

  else if(sequencePosition == sequenceLength)  //at end of one round
  {
    sequencePosition = 0;
    waitingForInput = false;
    flashGreen();
  }
}

void flashRed() //when player goes wrong, game is done
{
  for(int i = 0; i < 10; i++)
  {
    digitalWrite(RED, HIGH); 
    delay(50); 
    digitalWrite(RED, LOW);
    delay(50); 
  }
   sequenceLength = 0;
   sequencePosition = 0;
   code = 0;
   delay(1000);
   waitingForInput = false;
}

void flashGreen() //when player finishes round correctly, green flashes one before next sequence
{
  for(int i = 0; i < 10; i++)
  {
    digitalWrite(GREEN, HIGH); 
    delay(50); 
    digitalWrite(GREEN, LOW);
    delay(50); 
  }
  delay(500);
}

