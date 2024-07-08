#include <FastLED.h>
#include <math.h>

/* The following code is to run 64 LEDs in a fractal node form.
   For reference visit: https://youtu.be/99a2kWJhOM8 */

// Initializing LED pins
#define NUM_LEDS 8
#define LED_PIN_1 6
#define LED_PIN_2 8
#define LED_PIN_3 7
#define LED_PIN_4 9
#define LED_PIN_5 10
#define LED_PIN_6 3
#define LED_PIN_7 4
#define LED_PIN_8 5

// Initializing FastLED
CRGB leds_1[NUM_LEDS];
CRGB leds_2[NUM_LEDS];
CRGB leds_3[NUM_LEDS];
CRGB leds_4[NUM_LEDS];
CRGB leds_5[NUM_LEDS];
CRGB leds_6[NUM_LEDS];
CRGB leds_7[NUM_LEDS];
CRGB leds_8[NUM_LEDS];

// Some constants to use
double mtime;
double mtimeOld = 0;
double dt;
double omega = 1;
double cycleCutoff = 0;
const double pi = 3.14159;
double K = 0.05;
const int N = 8;
double thetas[N];
double thetadots[N];
int writeNum = 0;

// Summation Indices
int i;
int j;

// Initialization
void setup() {
  Serial.begin(115200);

  // Adding LED strips
  FastLED.addLeds<WS2812B, LED_PIN_1, GRB>(leds_1, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_PIN_2, GRB>(leds_2, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_PIN_3, GRB>(leds_3, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_PIN_4, GRB>(leds_4, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_PIN_5, GRB>(leds_5, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_PIN_6, GRB>(leds_6, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_PIN_7, GRB>(leds_7, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_PIN_8, GRB>(leds_8, NUM_LEDS);
  
  FastLED.setBrightness(5);

  // Initialize thetas with random values between -pi and pi
  for (i = 0; i < N; i++) {
    thetas[i] = random(-pi, pi);
  }
}

// Main loop
void loop() {
  mtime = millis() / 1000.0; // Current time in seconds
  dt = mtime - mtimeOld; // Time difference from last loop
  mtimeOld = mtime;
  mtime = mtime * omega; // Adjusted time for omega

  // Iterate through each LED
  for (i = 0; i < N; i++) {
    double sums = 0;

    // Summation over all LEDs
    for (j = 0; j < N; j++) {
      // Euler Scheme for thetadots
      sums += (K / N) * sin(thetas[j] - thetas[i]); 
    }
    
    // Update thetadots and thetas
    thetadots[i] = omega + sums;
    Serial.println(thetadots[i] * dt);
    thetas[i] += (thetadots[i] * dt);
    
    // Update LEDs based on thetas
    if (sin(mtime + thetas[i]) > cycleCutoff) {
      leds_1[i] = CRGB(255, 0, 0); // Red color
    } else {
      leds_1[i] = CRGB(0, 0, 0); // Off
    }
    FastLED.show();
    
    if (sin(mtime + thetas[i]) > cycleCutoff) {
      leds_2[i] = CRGB(255, 0, 0);
    } else {
      leds_2[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
    
    if (sin(mtime + thetas[i]) > cycleCutoff) {
      leds_3[i] = CRGB(255, 0, 0);
    } else {
      leds_3[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
    
    if (sin(mtime + thetas[i]) > cycleCutoff) {
      leds_4[i] = CRGB(255, 0, 0);
    } else {
      leds_4[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
    
    if (sin(mtime + thetas[i]) > cycleCutoff) {
      leds_5[i] = CRGB(255, 0, 0);
    } else {
      leds_5[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
    
    if (sin(mtime + thetas[i]) > cycleCutoff) {
      leds_6[i] = CRGB(255, 0, 0);
    } else {
      leds_6[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
    
    if (sin(mtime + thetas[i]) > cycleCutoff) {
      leds_7[i] = CRGB(255, 0, 0);
    } else {
      leds_7[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
    
    if (sin(mtime + thetas[i]) > cycleCutoff) {
      leds_8[i] = CRGB(255, 0, 0);
    } else {
      leds_8[i] = CRGB(0, 0, 0);
    }
    FastLED.show();
  }
}
