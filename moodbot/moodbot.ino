#include <Arduino_LED_Matrix.h>

ArduinoLEDMatrix matrix;

void setup() {
  Serial.begin(115200);
  matrix.begin();
}

void loop() {
  matrix.loadFrame(LEDMATRIX_EMOJI_BASIC);
}
