# MoodBot

## Project description

This is simple Arduino project that animates a series of robot emoji faces on the 
Arduino UNO R4 Wifi's built-in 12x8 LED matrix. It uses a **Modulino Knob** to control 
the animation speed in real time and a **Modulino Pixel** LED strip to visually reflect
that speed level using both **colors** and **blinking effects**.

This project focuses on:
- Manual pixel animation using 2D arrays (no external emoji libraries)
- Real-time interaction using a rotary encoder with a button
- Dynamic feedback using colorful LED animations

---

## Hardware Used

- Arduino UNO R4 Wifi + on-board 12x8 LED Matrix
- Modulino Knob(rotary encoder with button)
- Modulino Pixel(LED strip)

---

## Features

### 1. 🎭 Multiple custom robot faces:
- Neutral face
- Right eye wink
- Smiling face
- Sleeping face
- Sad face
- Suprised face
    
Each face is created manually using a custom pixel array and displayed in sequence.

---

### 2. 🎛️ Knob rotation = Controls Speed
- Rotate **right**: Faster animation 
- Rotate **left**: Slower animation
- Speed range from **1000ms(slowest)** to **100ms(fastest)**
- The knob value is clamped between `0` and `100`

---

### 3. 🌈 LEDs Strip = Visual speed level feedback

The number of **active LEDs**, **color**, and **blinking behavior** change based on the
current animation speed:

| Animation Delay | Speed Level     | LEDs ON | LED Color | Blinks |
|-----------------|------------------|---------|-----------|--------|
| ≤ 100 ms        | Ultra Fast       | 8       | 🔴 Red     | 3      |
| ≤ 200 ms        | Very Fast        | 7       | 🟣 Purple  | 2      |
| ≤ 400 ms        | Fast             | 6       | 🟡 Yellow  | 1      |
| ≤ 600 ms        | Moderate         | 4       | 🔵 Blue    | —      |
| ≤ 800 ms        | Slow             | 2       | 🟢 Green   | —      |
| > 800 ms        | Very Slow        | 1       | 🟢 Green   | —      |

- **Blink intensity increases** with speed (faster = more blinks)

---

### 4. 🔄 Button press = speed reset
- Pressing the knob resets the speed to the **midpoint value**

---
