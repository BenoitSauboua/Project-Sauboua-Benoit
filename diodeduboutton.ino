const int del = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(del, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(del, HIGH);   // allumer la led
  delay(1000);              // attendre une seconde
  digitalWrite(del, LOW);    // éteindre la led
  delay(1000);              // attendre une seconde
}
