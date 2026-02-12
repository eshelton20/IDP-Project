#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//screen size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1


#define OLED_I2C_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void drawWelcomeScreen()
{
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 10);
  display.println("Welcome to the");

  display.setCursor(0, 22);
  display.println("Home Audio System");

  display.setCursor(0, 34);
  display.println("Project");

  display.display();
}

void drawCreditsAtY(int yOffset)
{
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, yOffset + 0);
  display.println("Designed by");

  display.setCursor(0, yOffset + 12);
  display.println("Matt Tran");

  display.setCursor(0, yOffset + 24);
  display.println("Evan Shelton");

  display.display();
}

void slideInCredits()
{

  for (int y = -24; y <= 20; y += 2)
  {
    drawCreditsAtY(y);
    delay(25);
  }
}

void setup()
{
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS))
  {
    Serial.println("SSD1306 init failed");
    while (true)
    {
    }
  }

  drawWelcomeScreen();
  delay(2500);

  slideInCredits();
  delay(2000);
}

void loop()
{
}
