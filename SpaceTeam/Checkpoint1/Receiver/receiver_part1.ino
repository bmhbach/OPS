byte code = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  code = 0;
  if(Serial.available() > 0)
   {
      code = Serial.read();
   }
   if(code == 1)
   {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println(code);
    delay(1000);
   }
   else
   {
    digitalWrite(LED_BUILTIN, LOW);
   }

}
