#include "receiver.h"

void setup() {
  // put your setup code here, to run once

  Serial.begin(9600);
  receiver_setup();

}

void loop() {
  // put your main code here, to run repeatedly:
  float storage;
  if (receiving(storage))
  {
    Serial.print("It works: "); 
    Serial.print(storage);
    //Serial.println(storage);
  } 
  else
  {
    Serial.print("did not receive value\n");
  }
  delay(100);
  

}
