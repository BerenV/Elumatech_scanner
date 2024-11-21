#include <MouseAbsolute.h>
#include "Keyboard.h"


#define START_X 31000
#define START_Y 28500
#define STOP_X 27800
#define STOP_Y 28500

float length = 0.0;
int angleL = 45;
int angleR = 45;

void setup() {
  Serial1.begin(115200);  // barcode scanner port... pin 2 (GPIO 1) is RX
  Keyboard.begin();
  MouseAbsolute.begin();  // 211,158 screen w,h in mm
}

void loop() {
  if (Serial1.available() > 0) {
    // read incoming serial data:
    length = Serial1.parseFloat();
    if (length > 400) {
      pressStop();
      delay(1500);
      Keyboard.print(length);
      Keyboard.write(KEY_RETURN);
      delay(500);
      pressStart();
    }
  }
  delay(10);
}

void pressStart() {
  MouseAbsolute.move(START_X, START_Y);
  delay(10);
  MouseAbsolute.click();
}
void pressStop() {
  MouseAbsolute.move(STOP_X, STOP_Y);
  delay(10);
  MouseAbsolute.click();
}