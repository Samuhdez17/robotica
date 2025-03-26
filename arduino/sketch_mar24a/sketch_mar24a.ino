int led = LED_BUILTIN;

int on  = HIGH;
int off = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, on);
  delay(1000);
  digitalWrite(led, off);
  delay(1000);

}
