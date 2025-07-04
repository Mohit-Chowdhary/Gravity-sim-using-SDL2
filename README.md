# sdl2-gravity-box

> 🧲 A basic gravity simulation using SDL2 in C++. A red box falls under gravity and collides with the floor, demonstrating real-time physics and rendering.

---

## 🎮 Overview

This project simulates a single box falling under gravity inside an SDL2 window. It demonstrates:

- Continuous motion using velocity integration
- Simple collision detection with the floor
- Real-time rendering with `SDL_Renderer`
- Reset functionality via spacebar

---

## 🛠️ Technologies Used

- **C++**
- **SDL2** (Simple DirectMedia Layer)

---

## 🔧 How It Works

- Gravity is applied every frame:
  ```cpp
  velocity += GRAVITY;
  boxY += velocity;
  ```
When the box hits the floor:

cpp
```
if (boxY >= FLOOR_Y) {
    boxY = FLOOR_Y;
    velocity = 0;
}
```
Pressing Space resets the box to the top.

▶️ Controls
Key	Action
Space	Reset the falling box
Esc / ❌	Quit the program

🧪 What I Learned
Using SDL2 for rendering and window management

Applying basic physics (gravity & velocity)

Handling keyboard input and frame timing

Simulating and rendering simple real-time motion
