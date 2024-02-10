#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
#define WAIT 1500
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 160

void setup() {
  tft.init();
  tft.setRotation(1);
}

void moveSadFaceRandomly() {
  tft.fillScreen(TFT_BLACK);
  tft.drawString("      uWu <3 ", 0, 0, 2);
  int x = random(0, SCREEN_WIDTH); // Adjust the width of the ":(" text
  int y = random(1, SCREEN_HEIGHT); // Adjust the height of the ":(" text
  tft.drawString(":(", x, y, 2);
  delay(WAIT);
}

void moveSadFaceEnd() {
  tft.fillScreen(TFT_BLACK);
  tft.drawString("      uWu <3 ", 0, 0, 2);
  int x = random(0, SCREEN_WIDTH/5);
  int y = random(SCREEN_HEIGHT - 10, SCREEN_HEIGHT);
  tft.drawString(":(", x, y, 2);
  delay(WAIT);
}

void loop() {
  tft.setTextSize(2);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("Story Time!", 0, 0, 2);
  delay(WAIT);
  tft.drawString("~~A failed love", 0, 25, 2);
  tft.drawString("story~~", 0, 50, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString(":)", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("Girl walks", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("  :)", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("Girl walks more", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("     :)", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("     :)   :|", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("Gasp, girl sees boy", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("     :o   :|", 0, 0, 2);
  delay(WAIT);


  tft.fillScreen(TFT_BLACK);
  tft.drawString("     ;3   :|", 0, 0, 2);
  delay(WAIT);


tft.fillScreen(TFT_BLACK);
  tft.drawString("Girl flirts", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("      ;3 :| ??", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("Boy confused", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("      ;) <3 :o", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("Girl confessed!", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("      uWu <3 :o", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("      uWu <3 :(", 0, 0, 2);
  delay(WAIT);

  moveSadFaceRandomly();
  // delay(WAIT);
  moveSadFaceRandomly();
  moveSadFaceEnd();


  // tft.drawString("      uWu <3    :(", 0, 0, 2);
  // delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("Boy scared", 0, 0, 2);
  delay(WAIT);

  tft.drawString("Boy run", 0, 25, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("      ;-; </3   ", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("Gurl sad", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("FIN", 0, 0, 2);
  delay(WAIT);
  tft.drawString("Happy Valentines :)",0, 50, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("Sad sad sad", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("Dont look for", 0, 0, 2);
  tft.drawString("love", 0, 25, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("Just sleep", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("PSA: ", 0, 0, 2);
  delay(WAIT);

  tft.drawString("Sleep early today", 0, 25, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("#BeHealthy", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("( _ _) Zzzz", 0, 0, 2);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.drawString("<3 <3 ;))) <3 <3 ", 0, 0, 2);
  delay(WAIT);


}
