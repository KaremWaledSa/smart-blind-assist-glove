# Hardware Reference

## Keypad Variant

```
Arduino Uno / Nano
│
├── D2  ──► LCD D7
├── D3  ──► LCD D6
├── D4  ──► LCD D5
├── D5  ──► LCD D4
├── D6  ──► LCD EN
├── D7  ──► LCD RS
├── D8  ──► Keypad COL3
├── D9  ──► Keypad COL2
├── D10 ──► Keypad COL1
├── D11 ──► Keypad ROW4
├── D12 ──► Keypad ROW3
├── D13 ──► Keypad ROW2
├── A0  ──► Keypad ROW1
└── A2  ──► Buzzer (+)
     GND ──► LCD VSS, LCD RW, Buzzer (-)
     5V  ──► LCD VDD
     10kΩ pot (or fixed resistors) ──► LCD V0 (contrast)
```

## Button Variant

```
Arduino Uno / Nano
│
├── D2–D5  ──► LCD D7–D4
├── D6     ──► LCD EN
├── D13    ──► LCD RS
├── D6–D10 ──► Top thumb / index / middle / ring / pinky
├── D11    ──► Low thumb
└── A0–A3  ──► Low index / middle / ring / pinky
```

All button pins use `INPUT_PULLUP`. Buttons connect pin to GND when pressed (active-LOW logic).

## LCD Contrast

Connect a 10kΩ potentiometer between 5V and GND, with the wiper to LCD V0 (pin 3). Alternatively use a fixed 1–2kΩ resistor from V0 to GND for a reasonable default contrast.
