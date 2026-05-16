# 🕹️ ESP32 Retro Pac-Man

Welcome to the **ESP32 Retro Pac-Man** project! This is a completely open-source, DIY hardware port of the classic arcade game running on an ESP32 microcontroller and a 1.3" OLED display.

With sound effects, a fully playable ghost AI, smooth joystick controls, and a custom maze catalog, this project is perfect for makers, retro gaming fans, and anyone looking to learn about game development on embedded systems.

![Pac-Man Arcade](https://img.shields.io/badge/Game-Pac--Man-yellow?style=for-the-badge&logo=game-controller)
![PlatformIO](https://img.shields.io/badge/PlatformIO-ESP32-orange?style=for-the-badge&logo=platformio)
![License](https://img.shields.io/badge/License-MIT-blue?style=for-the-badge)

---

## ✨ Features

- **Classic Gameplay**: Eat dots, avoid the ghost, and clear levels!
- **Smooth Mini-Display Graphics**: Custom sprites rendered on a 128x64 SH110X I2C OLED screen.
- **Dynamic Maze Selection**: Browse multiple built-in mazes right from the start menu.
- **Progressive Difficulty**: The ghost gets faster with every level you clear.
- **Sound Effects**: Integrated buzzer for retro beeps, intro music, and dot-eating sounds.
- **Customizable**: Extremely easy to add your own mazes directly in the code!

---

## 🛠️ Hardware Requirements & Wiring

You'll need a few basic electronic components to build this console:

1. **ESP32** Development Board
2. **1.3" I2C OLED Display** (SH1106G driver)
3. **Analog Joystick Module**
4. **Push Button** (for selections)
5. **Passive Buzzer** (for sound)
6. Breadboard & Jumper Wires

### 🔌 Connection Guide

Wire your components to the ESP32 according to the table below. Note that the button relies on the ESP32's internal pull-up resistor, so you only need to wire the button between the GPIO pin and Ground.

| Component         | Pin on Component | Pin on ESP32 | Notes |
|-------------------|------------------|--------------|-------|
| **OLED Display**  | SDA              | `GPIO 21`    | Standard ESP32 I2C Data |
|                   | SCL              | `GPIO 22`    | Standard ESP32 I2C Clock |
|                   | VCC              | `3.3V`       | |
|                   | GND              | `GND`        | |
| **Joystick**      | VRx (X-Axis)     | `GPIO 34`    | Analog Input |
|                   | VRy (Y-Axis)     | `GPIO 35`    | Analog Input |
|                   | +5V              | `3.3V` or `5V` | Depends on your joystick module |
|                   | GND              | `GND`        | |
| **Push Button**   | Terminal 1       | `GPIO 23`    | |
|                   | Terminal 2       | `GND`        | Triggers `LOW` when pressed |
| **Buzzer**        | Positive (+)     | `GPIO 27`    | |
|                   | Negative (-)     | `GND`        | |

> **Note:** If your joystick movement feels inverted (e.g., Up moves Left), you may need to swap `JOY_X` and `JOY_Y` in the code or physically rotate your joystick module.

---

## 🚀 Installation & Setup

This project uses **PlatformIO**.

1. Install [Visual Studio Code](https://code.visualstudio.com/) and the [PlatformIO IDE extension](https://platformio.org/install/ide?install=vscode).
2. Clone this repository to your local machine.
3. Open the project folder in VS Code. PlatformIO will automatically install all the necessary libraries (`Adafruit GFX`, `Adafruit SH110X`).
4. Connect your ESP32 via USB.
5. Click the **Upload** button (the arrow icon `→` at the bottom of VS Code) to compile and flash the game to your ESP32.

---

## 🎮 How to Play

- **Start Menu**: Use the **Joystick** (Left/Right) to browse through the available mazes. Press **Button 1** to select a maze and start the game!
- **Gameplay**: Use the **Joystick** to guide Pac-Man. Eat all the dots `.` on the map to win the level! Avoid the Ghost `#`, or it's Game Over!
- **Exit to Menu**: At any time during gameplay, press **Button 1** to return to the Maze Selection Menu.

---

## 🏗️ Add Your Own Custom Maze!

We built this project to be completely extensible. You can design your own levels and play them immediately!

To add a new maze:
1. Open `include/maze_list.h`.
2. Find the `MAZE_NAMES` array near the top and add a name for your maze:
   ```cpp
   static const char* const MAZE_NAMES[] = {
     "Classic",
     "Arena",
     "Corridors",
     "Zigzag",
     "Chambers",
     "My Awesome Maze" // <-- Add your name here
   };
   ```
3. Scroll down to the `MAZE_LIST` array and add your maze grid at the bottom (make sure to add a comma `,` after the previous maze block):
   ```cpp
   // ── Maze 6: My Awesome Maze ──
   {
     "################",
     "#..............#",
     "#.##.######.##.#",
     "#.#..........#.#",
     "#.#...####...#.#",
     "#.##.######.##.#",
     "#..............#",
     "################"
   }
   ```
### 📏 Maze Design Rules:
- **Size**: Exactly 16 characters wide and 8 rows tall.
- **Walls**: Use `#` for solid walls. The outer border MUST be solid `#`.
- **Dots/Paths**: Use `.` for eatable dots, or ` ` (space) for empty paths.
- **Spawns**: 
  - Pac-Man spawns at `(X:1, Y:1)` (top-left inside the border). Ensure this is NOT a wall!
  - The Ghost spawns at `(X:14, Y:6)` (bottom-right inside the border). Ensure this is NOT a wall!

Compile and upload the code, and your new maze will automatically show up in the game's start menu!

---

## 🤝 Contributing

This is an open-source project and contributions are welcome! 

Feel free to fork the repository, add your own crazy mazes, optimize the drawing functions, add more ghost AI personalities, or improve the hardware support. Submit a Pull Request and let's build the ultimate mini arcade together.
