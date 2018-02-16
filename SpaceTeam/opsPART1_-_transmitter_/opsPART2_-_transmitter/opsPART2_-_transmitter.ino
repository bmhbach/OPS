#define switchA 19

int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(switchA, INPUT);  
}

void loop() {
  buttonState = digitalRead(switchA);
  if (buttonState == HIGH)
  {
    Serial.write(1);
    delay(1000);
  }
}
