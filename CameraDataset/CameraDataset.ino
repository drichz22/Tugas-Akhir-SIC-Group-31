#include <Wire.h>
#include <OV767X.h>

#define SCL_PIN 21
#define SDA_PIN 22
#define VS_PIN 2
#define PCLK_PIN 33
#define MCLK_PIN RX
#define D7_PIN 4
#define D6_PIN 12
#define D5_PIN 13
#define D4_PIN 14
#define D3_PIN 15
#define D2_PIN RX2
#define D1_PIN TX2
#define D0_PIN 27
#define RST_PIN 3.3
#define PWN_PIN GND

OV767X cam;

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);

  if (!cam.begin(QQVGA, RGB565, VS_PIN, PCLK_PIN)) {
    Serial.println("Camera initialization failed");
    while (1);
  }

  pinMode(MCLK_PIN, OUTPUT);
  digitalWrite(MCLK_PIN, LOW);

  Serial.println("Camera initialized");
}

void loop() {
  uint8_t *frame = cam.readFrame();
  if (frame) {
    Serial.write(frame, cam.frameSize());
  }
}
