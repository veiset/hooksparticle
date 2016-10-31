const int buttonPin = 2;
const int ledPin = 7;
int buttonState = 0;

int ledOn(String param) {
    digitalWrite(ledPin, HIGH);
    return 0;
}

int ledOff(String param) {
    digitalWrite(ledPin, LOW);
    return 0;
}

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
    Particle.function("ledon", ledOn);
    Particle.function("ledoff", ledOff);
}

void loop() {
  delay(300);
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
        Particle.publish("button-clicked", "clicked", PRIVATE);
  }
}
