#include "LiquidCrystal.h"
#include <Keypad.h>

#define BUZZER_PIN A2

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {A0, 13, 12, 11};
byte colPins[COLS]  = {10, 9, 8};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// LCD pins
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Function prototypes
void showMessage(String msg);
void beep(int freq, int duration);

void setup() {
  // Set keypad row/col pins as INPUT_PULLUP
  int allPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0};
  for (int pin : allPins) {
    pinMode(pin, INPUT_PULLUP);
  }

  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ready");
}

void loop() {
  char key = keypad.getKey();
  if (!key) return;

  Serial.print("Key pressed: ");
  Serial.println(key);

  switch (key) {
    case '0': beep(450, 1000); showMessage("I need water");    break;
    case '1': beep(900, 1000); showMessage("I want to eat");   break;
    case '2': beep(300, 4000); showMessage("Bathroom");        break;
    case '3': beep(200, 1000); showMessage("Change clothes");  break;
    case '4': beep(700,  600); showMessage("I want to call");  break;
    case '5': beep(600, 1000); showMessage("I am sick");       break;
    case '6': beep(450,  300); showMessage("I want to pray");  break;
    case '7': beep(888, 1000); showMessage("I am sleeping");   break;
    case '8': beep(500, 1000); showMessage("I need help");     break;
    case '9': beep(200,  200); showMessage("Thank you");       break;
    default:  lcd.clear(); lcd.print("---"); delay(200);       break;
  }
}

void showMessage(String msg) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(msg);
  delay(2000);
}

void beep(int freq, int duration) {
  tone(BUZZER_PIN, freq);
  delay(duration);
  noTone(BUZZER_PIN);
  delay(duration);
}
