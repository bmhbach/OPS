#include "transmitter.h"

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
transmitter_setup();

}

void loop() {
  // put your main code here, to run repeatedly:
  sending(3.3);
}
