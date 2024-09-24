The repository contains Circuit diagrams and source code for the Kuramoto LED model, To watch a video explanation on this and to see the working:
Visit : - https://youtu.be/99a2kWJhOM8
or (A shorter video) : - https://youtube.com/shorts/dwHn6gCumkY?feature=share

cite this work - `Prasad, S.V.H., Thapar, V. & Ramaswamy, R. Digital Fireflies. Reson 29, 765–777 (2024). https://doi.org/10.1007/s12045-024-0765-2`



# Coupled LEDs and Brightness plotting

This project consists of a Python script for plotting the brightness data from the synchronous LED fractal node setup, as well as an Arduino sketch to control the LEDs.

## Contents

- `led_fractal_node.ino`: Arduino sketch for controlling the LED fractal node.
- `brightness_plotter.py`: Python script for plotting the brightness data in real-time.
- `requirements.txt`: Python dependencies required for running the plotter script.
- `README.md`: This file.

## Arduino Sketch: `led_fractal_node.ino`

### Description

The Arduino sketch is used to run 64 LEDs in a fractal node form. The LEDs are controlled using the FastLED library and simulate a fractal pattern based on synchronized oscillators.

### Hardware Setup

- Circuit diagrams can be found in /Design_topolgies.
- Arduino board.
- Connect the LED strips to the specified pins on the Arduino.

### Pin Configuration

```c++
#define NUM_LEDS 8
#define LED_PIN_1 6
#define LED_PIN_2 8
#define LED_PIN_3 7
#define LED_PIN_4 9
#define LED_PIN_5 10
#define LED_PIN_6 3
#define LED_PIN_7 4
#define LED_PIN_8 5
```


### Installation

1. Install the [FastLED library](https://github.com/FastLED/FastLED) via Arduino Library Manager.
2. Upload the `led_fractal_node.ino` sketch to your Arduino board.

### Usage

The sketch will automatically run and control the LED strips to create a fractal node pattern. 

## Python Script: Brightness_synchrony_finder.py

Can be accessed in /OpenCV_files

### Description

The Python script reads brightness data from a temporary CSV file (`file.csv`) and plots it in real-time using `realtime_brightness_plotter.py`.

### Installation

1. Ensure you have Python installed on your system.
2. Install the required Python libraries by running:

pip install -r requirements.txt


### Example usage

python Brightness_synchrony_finder.py --b <Threshold Value>  --f '/path/to/file.mp4'



### Dependencies
- pandas
- numpy
- matplotlib
- opencv
- shutup
- csv 
- imutils

