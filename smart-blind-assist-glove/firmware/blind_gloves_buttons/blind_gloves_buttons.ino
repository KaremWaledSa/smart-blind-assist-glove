#include "LiquidCrystal.h"

// ── Finger button pin mapping ──────────────────────────────────────────────
// Top row  = upper side of each finger (active-LOW with pull-up)
// Low row  = lower side of each finger (active-LOW with pull-up)
#define TOP_THUMB           6
#define TOP_FIRST_FINGER    7
#define TOP_SECOND_FINGER   8
#define TOP_THIRD_FINGER    9
#define TOP_FOURTH_FINGER   10
#define LOW_THUMB           11
#define LOW_FIRST_FINGER    A0
#define LOW_SECOND_FINGER   A1
#define LOW_THIRD_FINGER    A2
#define LOW_FOURTH_FINGER   A3

// ── LCD pins ───────────────────────────────────────────────────────────────
const int rs = 13, en = 12, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void showMessage(String msg);

void setup() {
  int buttonPins[] = {
    TOP_THUMB, TOP_FIRST_FINGER, TOP_SECOND_FINGER, TOP_THIRD_FINGER, TOP_FOURTH_FINGER,
    LOW_THUMB, LOW_FIRST_FINGER, LOW_SECOND_FINGER, LOW_THIRD_FINGER, LOW_FOURTH_FINGER
  };
  for (int pin : buttonPins) {
    pinMode(pin, INPUT_PULLUP);
  }

  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ready");
}

void loop() {
  if      (digitalRead(TOP_THUMB)           == LOW) { showMessage("I need water"); }
  else if (digitalRead(TOP_FIRST_FINGER)    == LOW) { showMessage("I want to eat"); }
  else if (digitalRead(TOP_SECOND_FINGER)   == LOW) { showMessage("Bathroom"); }
  else if (digitalRead(TOP_THIRD_FINGER)    == LOW) { showMessage("I want to pray"); }
  else if (digitalRead(TOP_FOURTH_FINGER)   == LOW) { showMessage("Change clothes"); }
  else if (digitalRead(LOW_THUMB)           == LOW) { showMessage("I want to call"); }
  else if (digitalRead(LOW_FIRST_FINGER)    == LOW) { showMessage("I am sick"); }
  else if (digitalRead(LOW_SECOND_FINGER)   == LOW) { showMessage("Say it again"); }
  else if (digitalRead(LOW_THIRD_FINGER)    == LOW) { showMessage("I am sleeping"); }
  else if (digitalRead(LOW_FOURTH_FINGER)   == LOW) { showMessage("I need help"); }
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("---");
    delay(50);
  }
}

void showMessage(String msg) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(msg);
  delay(3000);
}
