float currentTimer = 0.0;
int sedStatus = 0;
const int IDLE = 0;
const int PLANTING = 1;
const int PLANTED = 2;
const int DEFUSING = 3;
const int DEFUSED = 4;
const int EXPLODED = 5;
float sedTimers[] = {
  0,
  3.0,
  40,
  5.0
};
String sedStatuses[] = {
  "IDLE",
  "PLANTING",
  "PLANTED",
  "DEFUSING",
  "DEFUSED",
  "EXPLODED"
};

void setupSed() {
  blackBtn.attachClick(theVoid);
  // TODO config functions
  greenBtn.setPressTicks(300);
  redBtn.setPressTicks(300);
  greenBtn.attachDuringLongPress(defuseTimer);
  greenBtn.attachLongPressStop(defuseStop);
  redBtn.attachDuringLongPress(plantTimer);
  redBtn.attachLongPressStop(plantStop);
  if (gameStarted) {
    if (sedStatus == IDLE || sedStatus == PLANTING || sedStatus == PLANTED || sedStatus == DEFUSING) {
      if (sedStatus == PLANTED) {
        writeLcd("(G) defuse", "");
        explodeTimer();
      } else {
        writeLcd(" ** " + sedStatuses[sedStatus] + " ** ");
      }
      updateProgressBar(round(currentTimer * 10), round(sedTimers[sedStatus] * 10), 1);
    } else if (sedStatus == DEFUSED) {
      writeLcd("* BOMB DEFUSED *", " ");
    } else if (sedStatus == EXPLODED) {
      writeLcd("* BOMB EXPLODED *", " ");
      bombTone();
    }
  } else {
    // main screen
    writeLcd("(R) plant", " ");
  }
}

void plantTimer() {
  gameStarted = true;
  if (sedStatus == PLANTING && currentTimer >= sedTimers[PLANTING]) {
    sedStatus = PLANTED;
    currentTimer = 0;
  }
  if (sedStatus == IDLE || sedStatus == PLANTING) {
    sedStatus = PLANTING;
    currentTimer = currentTimer + 0.1;
  }
}

void defuseTimer() {
  if (sedStatus == DEFUSING && currentTimer >= sedTimers[DEFUSING]) {
    sedStatus = DEFUSED;
    currentTimer = 0;
  }
  if (sedStatus == PLANTED) {
    currentTimer = 0;
  }
  if (sedStatus == PLANTED || sedStatus == DEFUSING) {
    sedStatus = DEFUSING;
    currentTimer = currentTimer + 0.1;
  }
}

void explodeTimer() {
  if (sedStatus == PLANTED && currentTimer >= sedTimers[PLANTED]) {
    sedStatus = EXPLODED;
    currentTimer = 0;
  }
  if (sedStatus == PLANTED) {
    currentTimer = currentTimer + 0.1;
  }
}

void plantStop() {
  if (sedStatus == PLANTING) {
    sedStatus = IDLE;
    currentTimer = 0;
  }
}

void defuseStop() {
  if (sedStatus == DEFUSING) {
    sedStatus = PLANTED;
    currentTimer = 0;
  }
}