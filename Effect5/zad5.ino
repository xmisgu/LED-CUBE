unsigned long previousMillis = 0;
unsigned long previousBlinkMillis = 0;
const long interval = 500;
const long blinkInterval = 5;
int ledCounter = 2;
int ledLevelCounter = 2;
int level = 12;
int counter = 1;
int starter13 = 1;
int starter12 = 1;



void setup() {
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
    if (i > 11) {
      digitalWrite(i, HIGH);
    }
  }
  digitalWrite(11, LOW);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousBlinkMillis >= blinkInterval) {
    previousBlinkMillis = currentMillis;

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      if (counter <= 27) {
        if (ledCounter <= 10) {
          digitalWrite(ledCounter, HIGH);
          ledCounter++;
        } else {
          if(counter < 27){
            ledLevelCounter++;
          }
          if (ledLevelCounter > 10) {
            ledLevelCounter = 2;
            digitalWrite(level, LOW);
            level++;
          }
        }
        counter++;
      } else if (counter > 27 && counter < 54) {

        ledLevelCounter--;
        if (ledLevelCounter < 2) {
          ledLevelCounter = 10;
          digitalWrite(level, HIGH);
          --level;
        }

        if (level == 11) {
          digitalWrite(ledCounter, LOW);
          ledCounter--;
        }


        counter++;
      } else {
        ledCounter = 2;
        ledLevelCounter = 2;
        level = 12;
        counter = 1;
        starter13 = 1;
        starter12 = 1;
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
        digitalWrite(13, HIGH);
        for (int i = 2; i <= 10; i++) {
          digitalWrite(i, LOW);
        }
      }
    }
    if (counter <= 27) {
      if (ledCounter > 10) {
        for (int i = 10; i >= ledLevelCounter; i--) {
          if (digitalRead(i) == HIGH) {
            digitalWrite(i, LOW);
          } else {
            digitalWrite(i, HIGH);
          }
        }
        for (int i = level; i >= 12; i--) {
          if (digitalRead(i) == LOW) {
            digitalWrite(i, HIGH);
          } else {
            digitalWrite(i, LOW);
          }
        }
      }
    } else if (counter > 27 && counter <= 54) {
      if (level > 11) {
        for (int i = 10; i > ledLevelCounter; i--) {
          if (digitalRead(i) == HIGH) {
            digitalWrite(i, LOW);
          } else {
            digitalWrite(i, HIGH);
          }
        }
        if (level == 13 &&starter13 == 1) {
          starter13--;
          digitalWrite(13, HIGH);
        }
        if (level == 12 && starter12 == 1) {
          starter12--;
          digitalWrite(12, HIGH);
        }
        for (int i = level; i >= 12; i--) {
          if (digitalRead(i) == LOW) {
            digitalWrite(i, HIGH);
          } else {
            digitalWrite(i, LOW);
          }
        }
      }
    }

  }


}
