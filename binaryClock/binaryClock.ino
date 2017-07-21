// binary clock
// a clock that uses 8 led lights to display the seconds passed
// since reset has been pressed
// author: yicheng wang

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  int t = millis() / 1000; // time in seconds

  for (int i = 0 ; i < 8 ; i++) {
    if (t % 2 == 1) {
      digitalWrite(i, HIGH);
    }
    else {
      digitalWrite(i, LOW);
    }

    t /= 2;
  }

  delay(1000);
}

