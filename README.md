# SMART-HOME-AUTOMATION-SYSTEM
# 8051 UART-Based Home Automation with LCD Display

##  Project Overview
This project demonstrates **home automation using an 8051 microcontroller**.  
It controls **four devices** (Fan, Light, Television, Machine) via **UART commands**.  
The status of each device is displayed on a **16x2 LCD**.

---

## 🚀 Features
- Control devices using **serial commands (UART)**.
- Displays device status (`FAN ON`, `LIGHT OFF`, etc.) on LCD.
- Shows **WELCOME** message at startup.
- Supports **individual ON/OFF** and **ALL ON/OFF** commands.

---

## 🛠 Hardware Requirements
- AT89C51 Microcontroller
- 16x2 LCD Display
- 4 Loads (Fan, Light, TV, Machine)
- Crystal Oscillator: 11.0592 MHz
- MAX232 (for UART)
- Power Supply (5V)

---

## 🔗 UART Command Table
| Command | Action           |
|---------|------------------|
| `1`     | Fan ON          |
| `2`     | Fan OFF         |
| `3`     | Light ON        |
| `4`     | Light OFF       |
| `5`     | TV ON           |
| `6`     | TV OFF          |
| `7`     | Machine ON      |
| `8`     | Machine OFF     |
| `9`     | All Devices ON  |
| `0`     | All Devices OFF |

---

##  Working Principle
1. **Power ON:** LCD shows `WELCOME`.
2. **Send Command:** Through UART (Virtual Terminal or PC COM Port).
3. **8051 Action:** Turns ON/OFF the respective device.
4. **LCD Updates:** Displays the current status (e.g., `FAN ON`).

---

##  Baud Rate Settings
- **Crystal:** 11.0592 MHz
- **Mode:** Serial Mode 1 (8-bit UART)
- **Baud Rate:** 9600
- **TH1:** `-3` (Timer 1 in Mode 2, auto-reload)

---

##  Repository Contents
- `home_automation.c` → Complete Embedded C program
- `README.md` → Documentation

---

##  How to Use
1. Compile the `home_automation.c` file using **Keil uVision** or any 8051 compiler.
2. Generate the HEX file.
3. Load HEX file into **Proteus 8 Professional** for simulation.
4. Connect a **Virtual Terminal** in Proteus for UART commands.
5. Run simulation → Send commands (`0`–`9`) → Observe LCD & device response.

---

##  Example LCD Messages
- **WELCOME** (at startup)
- **FAN ON**, **FAN OFF**
- **LIGHT ON**, **LIGHT OFF**
- **TV ON**, **TV OFF**
- **MC ON**, **MC OFF**
- **ALL ON**, **ALL OFF**

---

##  Future Enhancements
- Add Bluetooth or Wi-Fi control
- Integrate sensors for automation
- Voice control with speech recognition

---
