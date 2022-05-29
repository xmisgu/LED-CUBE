unsigned long previousMillis = 0;
const long interval = 5;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(2, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);

}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (digitalRead(2) == HIGH && digitalRead(11) == LOW) {
      digitalWrite(2, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(12, LOW);
    } else if (digitalRead(3) == HIGH && digitalRead(12) == LOW) {
      digitalWrite(3, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(13, LOW);
    } else if (digitalRead(4) == HIGH && digitalRead(13) == LOW) {
      digitalWrite(4, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(11, LOW);
    }

  }
}
