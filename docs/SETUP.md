# Setup Guide

## Requirements

| Tool | Notes |
|---|---|
| Arduino IDE 2.x | https://www.arduino.cc/en/software |
| Keypad library | Only for keypad variant — Library Manager search: "Keypad" by Mark Stanley and Alexander Brevig |
| LiquidCrystal | Pre-installed with Arduino IDE |

## Flash Steps

```
1. Open Arduino IDE
2. For keypad variant only:
     Sketch → Include Library → Manage Libraries → search "Keypad" → Install
3. Open the firmware:
     firmware/blind_gloves_keypad/blind_gloves_keypad.ino
     OR
     firmware/blind_gloves_buttons/blind_gloves_buttons.ino
4. Select board: Arduino Uno (or Nano with correct processor)
5. Select COM port
6. Upload
```

## Test Without Full Hardware

Open Serial Monitor at **9600 baud**. For the keypad variant, each keypress prints:
```
Key pressed: 1
```

For the button variant, keep only the LCD and one button connected to verify basic operation before mounting everything on the glove.

## Troubleshooting

| Issue | Fix |
|---|---|
| LCD shows nothing | Check contrast pot, verify RS/EN/D4–D7 wiring |
| Keypad not responding | Verify row/col pin order matches `rowPins[]` and `colPins[]` |
| Buzzer always on | Confirm `BUZZER_PIN` is set to OUTPUT and pulled LOW in setup |
| Compile error in button variant | Ensure pin names use capitals: `TOP_THUMB`, `LOW_THUMB`, etc. |
