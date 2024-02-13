#include <TFT_eSPI.h> 
#include <esp_sleep.h>

TFT_eSPI tft = TFT_eSPI();
#define WAIT 1500
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 160
#define WAKE_UP_INTERVAL_SECONDS 420 //Have display sleep for 7 minutes

const char *emojis[] = {"ZzZzzZZ", "Watch \n Gordon Ramsay", "~_~ Zzzz", "SLEEP NOW", "^@__@^ \n You are eepy \n ^@__@^", "Rockabye baby \n in the treetops~", "Mama's gonna buy \n you a mockingbird"};


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
  int y = random(50, SCREEN_HEIGHT);
  tft.drawString(":(", x, y, 2);
  delay(WAIT);
}

void displayRandomEmoji() {
  tft.fillScreen(TFT_BLACK);
  
  int randomIndex = random(0, sizeof(emojis) / sizeof(emojis[0]));
  const char *randomEmoji = emojis[randomIndex];
  
  int x = random(0, SCREEN_WIDTH);
  int y = random(0, SCREEN_HEIGHT-120);

  uint16_t color = tft.color565(random(256), random(256), random(256));
  
  tft.setTextWrap(true);
  tft.setTextSize(3);
  tft.setTextColor(color);
  tft.setCursor(x, y);
  tft.println(randomEmoji);
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
  tft.drawString("<3 <3 ;))) <3 <3 ", 0, 0, 2);
  tft.drawString("Love yourself", 0, 25, 2);
  tft.drawString("Love your sleep", 0, 75, 2);
  tft.drawString("schedule", 0, 100, 2);
  delay(WAIT);


  displayRandomEmoji();
  displayRandomEmoji();
  displayRandomEmoji();
  displayRandomEmoji();
  displayRandomEmoji();
  delay(WAIT);
  delay(WAIT);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(2);
  tft.drawString("( _ _) Zzzz", 0, 0, 2);
  tft.drawString("Nap Time!", 0, 50, 2);
  delay(WAIT);

  

  esp_sleep_enable_timer_wakeup(WAKE_UP_INTERVAL_SECONDS * 1000000); // Convert seconds to microseconds
  esp_deep_sleep_start();


}
