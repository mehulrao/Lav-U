#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting Up...");
  if (! drv.begin()) {
    Serial.println("Could not find DRV2605");
    while (1) delay(10);
  }
 
  drv.selectLibrary(1);
  
  // I2C trigger by sending 'go' command 
  // default, internal trigger when sending GO command
  drv.setMode(DRV2605_MODE_INTTRIG); 
}

void loop() {

  // set the effect to play
  drv.setWaveform(0, 82);
  drv.setWaveform(1, 16);
  drv.setWaveform(2, 16);
  drv.setWaveform(3, 16);
  drv.setWaveform(4, 16);
  drv.setWaveform(5, 16);
  drv.setWaveform(6, 16);
  drv.go();
  delay(5000);
  drv.setWaveform(0, 70);
  drv.setWaveform(1, 0);
  drv.go();
  delay(5000);
}
