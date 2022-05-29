unsigned long previousMillis = 0;
const long interval = 1000;  

void setup() {
 for(int i = 2; i <=13; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }

  digitalWrite(11, LOW);
}

void loop() {
    unsigned long currentMillis = millis();  
    
    if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (digitalRead(11) == LOW) {
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
    } else if(digitalRead(12) == LOW){
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
    }else if(digitalRead(13) == LOW){
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
        digitalWrite(13, HIGH);
    }
    }

}
