#include <TFT_eSPI.h>

#define PIN_LED_1 22
#define PIN_LED_2 21
#define PIN_LED_3 25
#define PIN_LED_4 15
#define DESTROY 2
#define LEDC_FREQUENCY 1000 // LEDC frequency in Hz
#define LEDC_RESOLUTION 8   // LEDC resolution in bits

#define MIN_THRESHOLD 1800
#define MAX_THRESHOLD 1900
#define MAX_ANALOG_VALUE 4095
#define PIN_ANALOG_IN 26
#define CHAN_LED_1 0
#define CHAN_LED_2 1
#define CHAN_LED_3 2
#define CHAN_LED_4 3

int xyzPins[] = {37, 36, 33}; // x, y, z pins
TFT_eSPI tft;

void setup() {
  Serial.begin(74880);
  pinMode(xyzPins[2], INPUT_PULLUP); // z axis is a button
  pinMode(PIN_LED_1, OUTPUT);
  pinMode(PIN_LED_2, OUTPUT);
  pinMode(PIN_LED_3, OUTPUT);
  pinMode(PIN_LED_4, OUTPUT);
  pinMode(DESTROY, INPUT_PULLUP);
  tft.begin();
  tft.fillScreen(TFT_BLACK); 
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE);
  tft.setRotation(3);

  ledcSetup(CHAN_LED_1, LEDC_FREQUENCY, LEDC_RESOLUTION);
  ledcAttachPin(PIN_LED_1, CHAN_LED_1);

  ledcSetup(CHAN_LED_2, LEDC_FREQUENCY, LEDC_RESOLUTION);
  ledcAttachPin(PIN_LED_2, CHAN_LED_2);

  ledcSetup(CHAN_LED_3, LEDC_FREQUENCY, LEDC_RESOLUTION);
  ledcAttachPin(PIN_LED_3, CHAN_LED_3);

  ledcSetup(CHAN_LED_4, LEDC_FREQUENCY, LEDC_RESOLUTION);
  ledcAttachPin(PIN_LED_4, CHAN_LED_4);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    
    tft.fillScreen(TFT_BLACK);
    
    tft.setCursor(10, 10);
    tft.drawString(data, 50, 50, 2);
  }
  
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);
  int destroyVal = digitalRead(DESTROY);
  int adcVal = analogRead(PIN_ANALOG_IN);

  // Map analog input value to LED brightness
  int pwmVal = map(adcVal, 0, MAX_ANALOG_VALUE, 0, 255);

  int direction;

  if (xVal < MIN_THRESHOLD && yVal > 0 && yVal < MAX_ANALOG_VALUE) {
    direction = 1;
    //LEFT
    ledcWrite(CHAN_LED_2, pwmVal);
    ledcWrite(CHAN_LED_1, 0);
    ledcWrite(CHAN_LED_3, 0);
    ledcWrite(CHAN_LED_4, 0);
  } else if (yVal < 250 && xVal >= 0 && xVal <= MAX_ANALOG_VALUE) {
    direction = 0;
    //UP
    ledcWrite(CHAN_LED_1, pwmVal);
    ledcWrite(CHAN_LED_2, 0);
    ledcWrite(CHAN_LED_3, 0);
    ledcWrite(CHAN_LED_4, 0);
  } else if (yVal >= 3600 && xVal >= 0 && xVal <= 4095) {
    direction = 2;
    //DOWN
    ledcWrite(CHAN_LED_3, pwmVal);
    ledcWrite(CHAN_LED_1, 0);
    ledcWrite(CHAN_LED_2, 0);
    ledcWrite(CHAN_LED_4, 0);
  } else if (xVal > MAX_THRESHOLD && yVal > 0 && yVal < MAX_ANALOG_VALUE) {
    direction = 3;
    //RIGHT
    ledcWrite(CHAN_LED_4, pwmVal);
    ledcWrite(CHAN_LED_1, 0);
    ledcWrite(CHAN_LED_2, 0);
    ledcWrite(CHAN_LED_3, 0);
  } else {
    direction = 4;
    ledcWrite(CHAN_LED_1, 0);
    ledcWrite(CHAN_LED_2, 0);
    ledcWrite(CHAN_LED_3, 0);
    ledcWrite(CHAN_LED_4, 0);
  }

  if (zVal == 0) {
    direction = 5;
    ledcWrite(CHAN_LED_1, 0);
    ledcWrite(CHAN_LED_2, 0);
    ledcWrite(CHAN_LED_3, 0);
    ledcWrite(CHAN_LED_4, 0);
  }
  if (destroyVal == 0) {
    direction = 6;
    ledcWrite(CHAN_LED_1, pwmVal);
    delay(100);
    ledcWrite(CHAN_LED_1, 0);
    delay(100);
    ledcWrite(CHAN_LED_1, pwmVal);
    ledcWrite(CHAN_LED_1, 0);

  }


  Serial.print(direction);
  Serial.print('\n');
  // Serial.printf("X,Y,Z: %d,\t%d,\t%d\n", xVal, yVal, zVal);

  delay(100); // delay
}
