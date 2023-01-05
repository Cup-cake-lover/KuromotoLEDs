#include <FastLED.h>
#include <math.h>

/*The following code is to run 64 LEDs in a fractal node form for reference visit : https://youtu.be/99a2kWJhOM8*/

/* Initializing LED pins */
#define NUM_LEDS  8
#define LED_PIN_1   6
#define LED_PIN_2   8
#define LED_PIN_3   7
#define LED_PIN_4   9
#define LED_PIN_5   10
#define LED_PIN_6   3
#define LED_PIN_7   4
#define LED_PIN_8   5

/* Initializing Fastled */

CRGB leds_1[NUM_LEDS];
CRGB leds_2[NUM_LEDS];
CRGB leds_3[NUM_LEDS];
CRGB leds_4[NUM_LEDS];

CRGB leds_5[NUM_LEDS];
CRGB leds_6[NUM_LEDS];
CRGB leds_7[NUM_LEDS];
CRGB leds_8[NUM_LEDS];



/*Some constants to use*/
double mtime;
double mtimeOld=0;
double dt;
double omega = 1;
double cycleCutoff=0;
long pi = 3.14159;
double K = 0.05;
const int N = 8;
double thetas[N];
double thetadots[N];
int writeNum = 0;

/*Summation Indices*/

int i;
int j;


/*Initialization*/
void setup(){
  Serial.begin(115200);
  FastLED.addLeds<WS2812B, LED_PIN_1, GRB>(leds_1, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_PIN_2, GRB>(leds_2, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_PIN_3, GRB>(leds_4, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_PIN_4, GRB>(leds_4, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_PIN_5, GRB>(leds_5, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_PIN_6, GRB>(leds_6, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_PIN_7, GRB>(leds_7, NUM_LEDS);
  FastLED.addLeds<WS2812B, LED_PIN_8, GRB>(leds_8, NUM_LEDS);
  
  FastLED.setBrightness(5);
  for (i = 0; i < N; i++) {
    thetas[i] = random(-pi, pi);
  }

}

/*Main loop*/
void loop(){
  mtime = millis()/1000.0;
  dt=mtime-mtimeOld;
  mtimeOld=mtime;
  mtime = mtime*omega;

  for (i=0;i<N; i++){
    float sums = 0;
    for (j=0;j<N;j++){
      /*Euler Scheme*/
      sums += (K/N)*sin(thetas[j]-thetas[i]); 
      //thetas[i] = thetas[i] + (thetadots[i]*dt);
      //Serial.println(thetadots[i]);
    }
    thetadots[i] = omega + sums;
    Serial.println(thetadots[i]*dt);
    thetas[i] += (thetadots[i]*dt);
    writeNum = 0;
    if(i<8){
      if(sin(mtime+thetas[i])>cycleCutoff){
      //writeNum +=2;
      leds_1[i] = CRGB(255,0,0);
      FastLED.show();
      }
      else{
        //writeNum +=4;
        leds_1[i] = CRGB(0,0,0);
        FastLED.show();
    }
    }
    if(i<8){
      if(sin(mtime+thetas[i])>cycleCutoff){
      //writeNum +=2;
      leds_2[i] = CRGB(255,0,0);
      FastLED.show();
      }

      else{
        //writeNum +=4;
        leds_2[i] = CRGB(0, 0, 0);
        FastLED.show();
    }
    }
    if(i<8){
      if(sin(mtime+thetas[i])>cycleCutoff){
      //writeNum +=2;
      leds_3[i] = CRGB(255,0,0);
      FastLED.show();
      }

      else{
        //writeNum +=4;
        leds_3[i] = CRGB(0, 0, 0);
        FastLED.show();
    }
    }
    if(i<8){
      if(sin(mtime+thetas[i])>cycleCutoff){
      //writeNum +=2;
      leds_4[i] = CRGB(255,0,0);
      FastLED.show();
      }

      else{
        //writeNum +=4;
        leds_4[i] = CRGB(0, 0, 0);
        FastLED.show();
    }
    }
    if(i<8){
      if(sin(mtime+thetas[i])>cycleCutoff){
      //writeNum +=2;
      leds_5[i] = CRGB(255,0,0);
      FastLED.show();
      }

      else{
        //writeNum +=4;
        leds_5[i] = CRGB(0, 0, 0);
        FastLED.show();
    }
    }
    
    if(i<8){
      if(sin(mtime+thetas[i])>cycleCutoff){
      //writeNum +=2;
      leds_6[i] = CRGB(255,0,0);
      FastLED.show();
      }

      else{
        //writeNum +=4;
        leds_6[i] = CRGB(0, 0, 0);
        FastLED.show();
    }
    }
    if(i<8){
      if(sin(mtime+thetas[i])>cycleCutoff){
      //writeNum +=2;
      leds_7[i] = CRGB(255,0,0);
      FastLED.show();
      }

      else{
        //writeNum +=4;
        leds_7[i] = CRGB(0, 0, 0);
        FastLED.show();
    }
    }
    

    if(i<8){
      if(sin(mtime+thetas[i])>cycleCutoff){
      //writeNum +=2;
      leds_8[i] = CRGB(255,0,0);
      FastLED.show();
      }

      else{
        //writeNum +=4;
        leds_8[i] = CRGB(0, 0, 0);
        FastLED.show();
    }
    }    
    
    }
  }
}
