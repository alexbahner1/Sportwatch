//Display libs
//#include "U8glib.h"
#include <SPI.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_PCD8544.h>

//boolean backlight = true;
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3); // Clk :7, Din :6, Dc :5, CE :4, RST :3
//#define backlight 11
// SPI Com: ClK = 13, DIN = 11, CE = 10, DC = 9, Reset = 8
//U8GLIB_PCD8544 u8g(13, 11, 10, 9, 8);
//RTC libs
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;

void setup() {
  // put your setup code here, to run once:
//  u8g.setFont(u8g_font_10x20); // Sets fonts
//  u8g.setPrintPos(2, 15);
  Serial.begin(9600);
  display.begin();      
  display.setContrast(57); //Set contrast to 50
  display.clearDisplay(); 
  display.display();
  
  //Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  // Check to see if the RTC is keeping time.  If it is, load the time from your computer.
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // This will reflect the time that your sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}

void loop() {
  //call and Draw function for the clock  
//  u8g.firstPage();
//  do {  
//    drawTime();
//  } while( u8g.nextPage() );
  
  drawTime();
  //delay(1000);
  
//  display.setTextSize(1);
//  display.setTextColor(BLACK);
//  display.setCursor(0,0);
   display.println("fucking YASSSS!");
   display.display();
//  delay(2000);
//  display.clearDisplay();
//  
  delay(1000);
  display.clearDisplay();
   
  
}
