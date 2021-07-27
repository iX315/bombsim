void writeLcd(String firstLine = "", String secondLine = "") {
  if (firstLine != "") {
    lcd.setCursor(0, 0);
    printLine(firstLine);
  }
  if (secondLine != "") {
    lcd.setCursor(0, 1);
    printLine(secondLine);
  }
}

void theVoid() {}

void printLine(String line) {
  line = line.substring(0, LCD_WIDTH);
  int rest = LCD_WIDTH - line.length();
  String fill = "";
  for (size_t i = 0; i < rest; i++) {
    fill += " ";
  }
  lcd.print(line + fill);
}

void updateProgressBar(unsigned long count, unsigned long totalCount, int lineToPrintOn) {
  double factor = totalCount / 80.0;          
  int percent = (count+1) / factor;
  int number = percent / 5;
  int remainder = percent % 5;
  if (number > 0) {
    for(int j = 0; j < number; j++){
      lcd.setCursor(j, lineToPrintOn);
      lcd.write(5);
    }
  }
  lcd.setCursor(number, lineToPrintOn);
  lcd.write(remainder); 
  if (number < LCD_WIDTH) {
    for(int j = number+1; j <= LCD_WIDTH; j++) {
      lcd.setCursor(j, lineToPrintOn);
      lcd.write(0);
    }
  }  
}

void gameOver(String squad) {
  blackBtn.attachClick(theVoid);
  greenBtn.attachDuringLongPress(theVoid);
  redBtn.attachDuringLongPress(theVoid);
  writeLcd("   " + squad + " WINS", " ***  ***  ***");
  blinkAll();
  theGodFather();
}

void setupLeds() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void blinkAll() {
  for (size_t i = 0; i < 20; i++) {
    digitalWrite(RED_LED, HIGH);
    delay(50);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    delay(50);
    digitalWrite(GREEN_LED, LOW);
    delay(50);
  }
}