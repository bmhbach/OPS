#define switchA 19
#define switchB 17
#define switchC 15

int buttonStateA = 0;
int buttonStateB = 0;
int buttonStateC = 0;

void setup() {
  Serial.begin(9600);
  pinMode(switchA, INPUT);  
  pinMode(switchB, INPUT);  
  pinMode(switchC, INPUT);  
}

void loop() {
  buttonStateA = digitalRead(switchA);
  buttonStateB = digitalRead(switchB);
  buttonStateC = digitalRead(switchC);
  if (buttonStateA == HIGH)
    Serial.write(1);
  if (buttonStateA == LOW)
    Serial.write(2);  
  if (buttonStateB == HIGH)
    Serial.write(3);
  if (buttonStateB == LOW)
    Serial.write(4);  
  if (buttonStateC == HIGH)
    Serial.write(5);
  if (buttonStateC == LOW)
    Serial.write(6); 
  
  


  
}
