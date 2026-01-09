# Arduino-Based Diwali Safety Timer

## Project Overview
This is an Arduino-based Diwali safety timer with buzzer, LED, and relay. It allows safe, remote demonstration of timed activation. Press the button to start a countdown; buzzer beeps every second, last 3 seconds beep faster, and relay + LED activate for 3 seconds. Automatic reset makes it ready for reuse.

**Note:** Some help was taken from an AI model as I am a beginner. I will further improve it after exams.

---

## Materials / Components
- Arduino UNO
- Push Button
- Single-channel Relay Module
- Buzzer
- LED + 220Ω resistor
- Jumper wires
- Breadboard
- USB Cable

---

## Pin Mapping

| Component   | Arduino Pin | Notes |
|------------|------------|-------|
| Push Button | D2         | Start timer (INPUT_PULLUP) |
| Relay IN    | D8         | Activate relay output |
| Buzzer      | D9         | Audio countdown / end alert |
| Timer LED   | D13        | Timer running indicator |
| Relay LED   | Built-in   | Shows relay ON automatically |

---

## How It Works
1. **Start Timer:** Press the push button → Arduino detects and starts countdown.
2. **Countdown & Alerts:** Timer runs for 10 seconds; buzzer beeps every second. Last 3 seconds beep faster (300ms intervals). Timer LED optional.
3. **Timer Complete:** LED + relay ON for 3 seconds; buzzer continuous / repeated beep.
4. **Automatic Reset:** After 3 seconds, LED & relay turn OFF. Ready for next use.

---

## Simulation / Demo
- Wokwi / Tinkercad used for safe simulation.
- Relay output simulated with LED + resistor.
- Buzzer visualized via repeated tone in emulator.


## Learning Outcomes
- Using Arduino for timed events
- Controlling relay modules safely
- Generating audio-visual alerts
- Implementing button input with debounce
- Beginner-friendly project workflow for GitHub & Hack Club Blueprint


## GitHub Repository
All project files including Arduino code, simulation screenshots, and notes are in this repo.
