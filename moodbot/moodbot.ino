#include <Arduino_LED_Matrix.h>

ArduinoLEDMatrix matrix;

uint8_t frame[8][12] = {0};

// Robot emoji
void robotlefteye(){
  frame[1][3] = 1;
  frame[1][4] = 1;
  frame[2][3] = 1;
  frame[2][4] = 1;
}


void robotrighteye(){
  frame[1][7] = 1;
  frame[1][8] = 1;
  frame[2][7] = 1;
  frame[2][8] = 1;
}

void lefteyeclosed(){
  frame[1][3] = 0;
  frame[1][4] = 0;
  frame[2][3] = 1;
  frame[2][4] = 1;
}


void righteyeclosed(){
  frame[1][7] = 0;
  frame[1][8] = 0;
  frame[2][7] = 1;
  frame[2][8] = 1;
}

void robotmouth(){
  frame[4][3] = 0;
  frame[4][4] = 0;
  frame[4][5] = 0;
  frame[4][6] = 0;
  frame[4][7] = 0;
  frame[4][8] = 0;

  frame[5][3] = 1;
  frame[5][4] = 1;
  frame[5][5] = 1;
  frame[5][6] = 1;
  frame[5][7] = 1;
  frame[5][8] = 1;

  frame[6][3] = 1;
  frame[6][4] = 1;
  frame[6][5] = 1;
  frame[6][6] = 1;
  frame[6][7] = 1;
  frame[6][8] = 1;
}

void robotmouthsmile(){
  frame[4][3] = 1;
  frame[4][4] = 0;
  frame[4][5] = 0;
  frame[4][6] = 0;
  frame[4][7] = 0;
  frame[4][8] = 1;

  frame[5][3] = 1;
  frame[5][4] = 0;
  frame[5][5] = 0;
  frame[5][6] = 0;
  frame[5][7] = 0;
  frame[5][8] = 1;

  frame[6][3] = 1;
  frame[6][4] = 1;
  frame[6][5] = 1;
  frame[6][6] = 1;
  frame[6][7] = 1;
  frame[6][8] = 1;
}

void robotmouthsad(){

  frame[4][3] = 1;
  frame[4][4] = 1;
  frame[4][5] = 1;
  frame[4][6] = 1;
  frame[4][7] = 1;
  frame[4][8] = 1;

  frame[5][3] = 1;
  frame[5][4] = 0;
  frame[5][5] = 0;
  frame[5][6] = 0;
  frame[5][7] = 0;
  frame[5][8] = 1;

  frame[6][3] = 1;
  frame[6][4] = 0;
  frame[6][5] = 0;
  frame[6][6] = 0;
  frame[6][7] = 0;
  frame[6][8] = 1;
}

void robotmouthsuprise(){
  frame[4][3] = 1;
  frame[4][4] = 1;
  frame[4][5] = 1;
  frame[4][6] = 1;
  frame[4][7] = 1;
  frame[4][8] = 1;

  frame[5][3] = 1;
  frame[5][4] = 0;
  frame[5][5] = 0;
  frame[5][6] = 0;
  frame[5][7] = 0;
  frame[5][8] = 1;

  frame[6][3] = 1;
  frame[6][4] = 1;
  frame[6][5] = 1;
  frame[6][6] = 1;
  frame[6][7] = 1;
  frame[6][8] = 1;
}

void loop() {
  matrix.loadFrame(LEDMATRIX_EMOJI_BASIC);
  // Neutral robot face
  robotmouth();
  robotlefteye();
  robotrighteye();
  matrix.renderBitmap(frame, 8, 12);

  // Right eye wink robot face
  delay(1000);
  righteyeclosed();
  matrix.renderBitmap(frame, 8, 12);

  // Smile robot face
  delay(1000);
  robotlefteye();
  robotrighteye();
  robotmouthsmile();
  matrix.renderBitmap(frame, 8, 12);

  // Sleep robot face
  delay(1000);
  lefteyeclosed();
  righteyeclosed();
  robotmouth();
  matrix.renderBitmap(frame, 8, 12);

  // Sad robot face
  delay(1000);
  robotrighteye();
  robotlefteye();
  robotmouthsad();
  matrix.renderBitmap(frame, 8, 12);

  // Suprise robot face
  delay(1000);
  robotrighteye();
  robotlefteye();
  robotmouthsuprise();
  matrix.renderBitmap(frame, 8, 12);
  delay(1000);
}