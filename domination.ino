float timerRed;
float timerBlue;
float setupTime = 5.0;
bool started = false;
bool buttonsAttachedDomination = false;

void setupDomination() {
  if (!buttonsAttachedDomination) {
    blackBtn.attachClick(theVoid);
    greenBtn.attachDuringLongPress(greenTimer);
    redBtn.attachDuringLongPress(redTimer);
    timerRed = setupTime;
    timerBlue = setupTime;
    buttonsAttachedDomination = true;
  }
  if (started) {
    if (timerRed > timerBlue) {
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
    }
    if (timerRed < timerBlue) {
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
    }
    if (timerRed <= 0) {
      // red wins
      gameOver("RED");
    }
    if (timerBlue <= 0) {
      // green wins
      gameOver("GREEN");
    }
    delay(100);
  } else {
    writeLcd("(G)(R) start", "(B) config");
    delay(100);
  }
}

void greenTimer() {
  started = true;
  timerBlue = timerBlue - 0.1;
  writeLcd("   ** GREEN **");
  updateProgressBar(round(timerBlue * 10), round(setupTime * 10), 1);
  delay(100);
}

void redTimer() {
  started = true;
  timerRed = timerRed - 0.1;
  writeLcd("    ** RED **");
  updateProgressBar(round(timerRed * 10), round(setupTime * 10), 1);
  delay(100);
}