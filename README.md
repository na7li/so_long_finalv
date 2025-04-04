# 🕹️ so_long

> A 2D game project from the 1337/42 Common Core curriculum — built with C and the MiniLibX graphics library.

## 📌 Project Overview

**so_long** is a simple 2D game where the player navigates a maze-like map, collects items, avoids enemies (optional), and reaches the exit. The goal of the project is to practice working with **file parsing**, **game loops**, and **graphics rendering** using **MiniLibX**, a minimal graphics library provided by 42.

---

## 🎯 Objectives

- Parse and validate a `.ber` map file
- Load and render the map using graphical assets
- Handle player input and movement
- Count moves and display them in the terminal
- End the game when the player collects all collectibles and reaches the exit

---

## 🧱 Mandatory Features

✅ Load a `.ber` map file  
✅ Render walls, floor, player, collectibles, and exit  
✅ Use **MiniLibX** for 2D rendering  
✅ Handle keyboard input to move the player  
✅ Track and display the number of moves  
✅ Detect map errors (not rectangular, wrong symbols, unreachable items, etc.)

---

## 🗺️ Map Rules

- Must be rectangular  
- Must have **1 player**, **1 exit**, and **at least 1 collectible**  
- Surrounded by walls (`1`)  
- Only valid characters: `01CEP`  
  - `0`: empty space  
  - `1`: wall  
  - `C`: collectible  
  - `E`: exit  
  - `P`: player

---

## 🎮 Controls

| Key        | Action       |
|------------|--------------|
| W / ↑      | Move Up      |
| A / ←      | Move Left    |
| S / ↓      | Move Down    |
| D / →      | Move Right   |
| ESC        | Exit Game    |

---

## 🛠️ How to Compile and Run

### 1. Clone the repository
```bash
git clone https://github.com/na7li/so_long_finalv
cd so_long_finalv
```

2. Compile
```bash
make
```

### 3. Run the game
```bash
./so_long maps/map1.ber
```

---

## 📷 Screenshot
![Push_Swap Visualizer](https://github.com/na7li/so_long_finalv/blob/master/so_long_record.gif)

---

## ⚙️ Tools & Libraries

🧠 Language: C
🎨 Graphics: MiniLibX
🗺️ Map input: .ber files
🧰 Compiler: gcc, make

## 👨‍💻 Author
Mohamed – 1337 Coding School
🔗 github.com/na7li/so_long_finalv
