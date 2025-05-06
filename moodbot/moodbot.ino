#include <Arduino_LED_Matrix.h>
#include <Modulino.h>

ArduinoLEDMatrix matrix;
ModulinoKnob knob;
ModulinoPixels leds;

ModulinoColor red(255, 0, 0);
ModulinoColor purple(128, 0, 128);
ModulinoColor yellow(255, 165, 0);
ModulinoColor blue(0, 0, 255); 
ModulinoColor green(0, 255, 0); 

int valueSetKnob = 50;
int zeroSetValue = 0;
int brightness = 25;
bool wasPressed = false;

void setup() {
  Serial.begin(115200);
  matrix.begin();
  Modulino.begin();
  knob.begin();
  leds.begin();

  zeroSetValue = knob.get();
}

uint8_t frame[8][12] = {0};

// Robot eye function 
void setEye(int row, int col, bool closed = false){
  frame[row][col] = closed ? 0 : 1;
  frame[row][col + 1] = closed ? 0 : 1;
  frame[row + 1][col] = 1;
  frame[row + 1][col + 1] = 1;
}

void robotlefteye(){
  setEye(1, 3);
}

void robotrighteye(){
  setEye(1, 7);
}

void lefteyeclosed(){
  setEye(1, 3, true);
}

void righteyeclosed(){
  setEye(1, 7, true);
}

void drawMouth(const uint8_t mouth[3][6]){
  for (int row = 0; row < 3; row ++){
    for(int col = 0; col < 6; col++){
      frame[4 + row][3 + col] = mouth[row][col];
    }
  }
}

const uint8_t mouthNeutral[3][6] = {
  {0, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1}
};

const uint8_t mouthSmile[3][6] = {
  {1, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1}
};

const uint8_t mouthSad[3][6] = {
  {1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 1}
};

const uint8_t mouthSuprise[3][6] = {
  {1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1}
};

void loop() {
  // Check knob click
  bool click = knob.isPressed();

  // Read knob position
  int currentValue = knob.get();
  int knobValue = currentValue - zeroSetValue;
  zeroSetValue = currentValue;
  
  valueSetKnob += knobValue;

  // Set range 0, 100
  valueSetKnob = constrain(valueSetKnob, 0, 100);

  // Reset everything on click
  if (click && !wasPressed){
    valueSetKnob = 50;
    zeroSetValue = knob.get();
    Serial.println("Knob reset to center.");
  }
  wasPressed = click;


  // Map knob value to delay range
  int animationDelay = map(valueSetKnob, 0, 100, 1000, 100);
  animationDelay = constrain(animationDelay, 100, 1000); 


  // LED dislay for speed of animations
  leds.clear();
  int numLeds = 0;
  ModulinoColor color = blue;
  int blinkTimes = 0;
  int blinkDelay = 0;

  if(animationDelay <= 100){
    numLeds = 8;
    color = red;
    blinkTimes = 3;
    blinkDelay = 100;
  } else if(animationDelay <= 200){
    numLeds = 7;
    color = purple;
    blinkTimes = 2;
    blinkDelay = 150;
  } else if (animationDelay <= 400){
    numLeds = 6;
    color = yellow;
    blinkTimes = 1;
    blinkDelay = 200;
  } else if (animationDelay <= 600){
    numLeds = 4;
  } else if (animationDelay <= 800){
    numLeds = 2;
    color = green;
  } else {
    numLeds = 1;
    color = green;
  }

if (blinkTimes > 0) {
  for (int b = 0; b < blinkTimes; b++) {
    for (int i = 0; i < numLeds; i++) {
      leds.set(i, color);
    }
    leds.show();
    delay(blinkDelay);

    // Turn LEDs OFF
    leds.clear();
    leds.show();
    delay(blinkDelay);
  }
} else {
  for (int i = 0; i < numLeds; i++) {
    leds.set(i, color);
  }
  leds.show();
}

  Serial.println("Knob: ");
  Serial.println(valueSetKnob);
  Serial.println("Delay: ");
  Serial.println(animationDelay);

  // Neutral robot face
  drawMouth(mouthNeutral);
  robotlefteye();
  robotrighteye();
  matrix.renderBitmap(frame, 8, 12);

  // Right eye wink robot face
  delay(animationDelay);
  righteyeclosed();
  matrix.renderBitmap(frame, 8, 12);

  // Smile robot face
  delay(animationDelay);
  robotlefteye();
  robotrighteye();
  drawMouth(mouthSmile);
  matrix.renderBitmap(frame, 8, 12);

  // Sleep robot face
  delay(animationDelay);
  lefteyeclosed();
  righteyeclosed();
  drawMouth(mouthNeutral);
  matrix.renderBitmap(frame, 8, 12);

  // Sad robot face
  delay(animationDelay);
  robotrighteye();
  robotlefteye();
  drawMouth(mouthSad);
  matrix.renderBitmap(frame, 8, 12);

  // Suprise robot face
  delay(animationDelay);
  robotrighteye();
  robotlefteye();
  drawMouth(mouthSuprise);
  matrix.renderBitmap(frame, 8, 12);
  delay(animationDelay);

  zeroSetValue - currentValue;
}
