//Display libs
#include "U8glib.h"
#define backlight 11
// SPI Com: ClK = 13, DIN = 11, CE = 10, DC = 9, Reset = 8
// RTC wire up 
U8GLIB_PCD8544 u8g(13, 11, 10, 9, 8);
//RTC libs
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;

void setup() {
  // put your setup code here, to run once:
  u8g.setFont(u8g_font_10x20); // Sets fonts
  u8g.setPrintPos(2, 15);
  Serial.begin(9600);
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
  u8g.firstPage();
  do {  
    drawTime();
  } while( u8g.nextPage() );
  
  delay(1000);
   
  
}
  
