void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  analogWrite(LED_BUILTIN, 0);  
  delay(500);
  
  analogWrite(LED_BUILTIN, 50);  
  delay(500);
  
  analogWrite(LED_BUILTIN, 100);  
  delay(500);
  
  analogWrite(LED_BUILTIN, 150);  
  delay(500);     

  analogWrite(LED_BUILTIN, 255);   
  delay(500); 
}
