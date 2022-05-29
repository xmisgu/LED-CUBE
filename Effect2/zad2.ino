void setup() {
  for(int i = 2; i <= 13; i++){
    pinMode(i, OUTPUT);
    if(i > 10){
      digitalWrite(i, HIGH);
    }
  }
}

void loop() {
  for(int i = 11; i <= 13; i++){
    digitalWrite(i, LOW);
    for(int j = 2; j <= 10; j++){
      digitalWrite(j, HIGH);
      delay(1000);
      digitalWrite(j, LOW);
    }
    digitalWrite(i, HIGH);
  }
}
