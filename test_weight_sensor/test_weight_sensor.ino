
// Tutorial
// https://circuitdigest.com/microcontroller-projects/arduino-weight-measurement-using-load-cell

// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPL7tAOt3GO"
#define BLYNK_DEVICE_NAME "Input Output"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD
//#define USE_TTGO_T7
//#define USE_ESP32C3_DEV_MODULE
#define USE_ESP32S2_DEV_KIT

#include "BlynkEdgent.h"
BLYNK_WRITE(V5){
  if (param.asInt()==HIGH){
    digitalWrite(14,LOW);
  }
  else{
    digitalWrite(14,HIGH);
  }
}
void setup()
{
  Serial.begin(115200);
  delay(100);
  pinMode(14,OUTPUT);
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  int buttonState = digitalRead(14);
  Serial.println(buttonState);
}
