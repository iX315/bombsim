float timerRed;
float timerBlue;
float setupTimeDomination = 15.0;
bool buttonsAttachedDomination = false;
bool buttonsAttachedConfigDomination = false;
bool showConfigDomination = false;

void setupDomination() {
  if (!buttonsAttachedDomination) {
    greenBtn.setPressTicks(300);
    redBtn.setPressTicks(300);
    blackBtn.attachClick(configDomination);
    greenBtn.attachDuringLongPress(greenTimer);
    redBtn.attachDuringLongPress(redTimer);
    timerRed = setupTimeDomination;
    timerBlue = setupTimeDomination;
    buttonsAttachedDomination = true;
  }
  if (showConfigDomination) {
    configDomination();
  } else if (gameStarted) {
    dominationGame();
  } else {
    // main screen
    writeLcd("(G)(R) start", "(B) config");
    delay(100);
  }
}

void configDomination() {
  showConfigDomination = true;
  if (!buttonsAttachedConfigDomination) {
    blackBtn.attachClick(exitConfigDomination);
    greenBtn.attachDuringLongPress(theVoid);
    redBtn.attachDuringLongPress(theVoid);
    greenBtn.attachClick(decreaseSeconds);
    redBtn.attachClick(increaseSeconds);
    buttonsAttachedConfigDomination = true;
  }
  writeLcd(" -(G) [" + String(round(setupTimeDomination)) + "s] (R)+", "(B) back");
  delay(100);
}

void exitConfigDomination() {
  showConfigDomination = false;
  buttonsAttachedDomination = false;
  blackBtn.attachClick(theVoid);
  greenBtn.attachClick(theVoid);
  redBtn.attachClick(theVoid);
}

void decreaseSeconds() {
  if (setupTimeDomination > 1) {
    setupTimeDomination = setupTimeDomination - 1;
  }
}

void increaseSeconds() {
  setupTimeDomination = setupTimeDomination + 1;
}

void dominationGame() {
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
}

void greenTimer() {
  gameStarted = true;
  timerBlue = timerBlue - 0.1;
  writeLcd("   ** GREEN **");
  updateProgressBar(round(timerBlue * 10), round(setupTimeDomination * 10), 1);
}

void redTimer() {
  gameStarted = true;
  timerRed = timerRed - 0.1;
  writeLcd("    ** RED **");
  updateProgressBar(round(timerRed * 10), round(setupTimeDomination * 10), 1);
}