byte code = 0;
#define RED 12
#define GREEN 11
#define YELLOW 10

int redState = LOW;
int greenState = LOW;
int yellowState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);

}

void loop() {
  code = 0;
  if(Serial.available() > 0)
   {
      code = Serial.read();
   }

   switch(code)
   {
      case 1: redState = HIGH; break;
      case 2: redState = LOW; break;
      case 3: greenState = HIGH; break;
      case 4: greenState = LOW; break;
      case 5: yellowState = HIGH; break;
      case 6: yellowState = LOW; break;
    
   }
    
    digitalWrite(RED, redState);
    digitalWrite(GREEN, greenState);
    digitalWrite(YELLOW, yellowState);
    






   

}
