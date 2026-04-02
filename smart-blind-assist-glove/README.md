# Smart Blind Assist Glove

> An assistive communication device for visually impaired or non-verbal users — pressing a finger button or keypad key instantly displays a predefined message on an LCD and plays a distinct audio tone.

![Platform](https://img.shields.io/badge/Platform-Arduino%20Uno%20%2F%20Nano-blue)
![Language](https://img.shields.io/badge/Language-Arduino%20C%2B%2B-lightgrey)
![Category](https://img.shields.io/badge/Category-Assistive%20Technology-purple)
![License](https://img.shields.io/badge/License-MIT-yellow)

---

## Overview

The glove allows a user with limited or no speech to communicate basic needs by pressing a button or key. Each input maps to a plain-language message shown on a 16×2 LCD. The keypad variant also plays a distinct buzzer tone per message, giving audio confirmation.

Two firmware variants are included — use whichever suits your hardware build:

| Variant | Input | Audio | File |
|---|---|---|---|
| Keypad | 4×3 matrix keypad (10 messages) | Yes — unique tone per key | `blind_gloves_keypad.ino` |
| Buttons | 10 discrete tactile switches | No | `blind_gloves_buttons.ino` |

---

## Message Mapping

### Keypad Variant

| Key | Message | Tone (Hz) |
|---|---|---|
| `0` | I need water | 450 |
| `1` | I want to eat | 900 |
| `2` | Bathroom | 300 |
| `3` | Change clothes | 200 |
| `4` | I want to call | 700 |
| `5` | I am sick | 600 |
| `6` | I want to pray | 450 |
| `7` | I am sleeping | 888 |
| `8` | I need help | 500 |
| `9` | Thank you | 200 |

### Button Variant

| Button | Message |
|---|---|
| Top thumb | I need water |
| Top index | I want to eat |
| Top middle | Bathroom |
| Top ring | I want to pray |
| Top pinky | Change clothes |
| Low thumb | I want to call |
| Low index | I am sick |
| Low middle | Say it again |
| Low ring | I am sleeping |
| Low pinky | I need help |

---

## Hardware

### Keypad Variant

| Component | Notes |
|---|---|
| Arduino Uno / Nano | Any 5V Arduino compatible |
| 4×3 matrix keypad | 7-pin membrane keypad |
| 16×2 LCD | Standard HD44780-compatible |
| Active buzzer | Connected to A2 |

**Pin Mapping:**

| Signal | Arduino Pin |
|---|---|
| Keypad rows | A0, 13, 12, 11 |
| Keypad cols | 10, 9, 8 |
| LCD RS | 7 |
| LCD EN | 6 |
| LCD D4–D7 | 5, 4, 3, 2 |
| Buzzer | A2 |

### Button Variant

| Component | Notes |
|---|---|
| Arduino Uno / Nano | Any 5V Arduino compatible |
| 10 tactile switches | One per finger position |
| 16×2 LCD | Standard HD44780-compatible |

**Pin Mapping:**

| Finger | Arduino Pin |
|---|---|
| Top thumb | 6 |
| Top index | 7 |
| Top middle | 8 |
| Top ring | 9 |
| Top pinky | 10 |
| Low thumb | 11 |
| Low index | A0 |
| Low middle | A1 |
| Low ring | A2 |
| Low pinky | A3 |

---

## Repository Structure

```
smart-blind-assist-glove/
├── firmware/
│   ├── blind_gloves_keypad/
│   │   └── blind_gloves_keypad.ino   # Keypad + buzzer variant
│   └── blind_gloves_buttons/
│       └── blind_gloves_buttons.ino  # Discrete button variant
├── docs/
│   ├── HARDWARE.md
│   └── SETUP.md
├── .gitignore
├── LICENSE
└── README.md
```

---

## Getting Started

```
1. Open Arduino IDE
2. For keypad variant: install "Keypad" library (Library Manager → search "Keypad" by Mark Stanley)
3. Open the firmware variant you want:
     - firmware/blind_gloves_keypad/blind_gloves_keypad.ino
     - firmware/blind_gloves_buttons/blind_gloves_buttons.ino
4. Wire components per the pin mapping above
5. Upload to your Arduino board
6. Open Serial Monitor at 9600 baud to see key press events
```

---

## Extending the Project

To add or change a message, edit the `switch` block in `blind_gloves_keypad.ino`:

```cpp
case '0': beep(450, 1000); showMessage("I need water"); break;
// Change the message string and/or tone frequency as needed
```

For the button variant, edit the corresponding `if` block in `blind_gloves_buttons.ino`.

---

## License

MIT — see [LICENSE](LICENSE).
