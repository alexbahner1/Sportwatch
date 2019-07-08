// display libs
#include <SPI.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_PCD8544.h>
// Display intiz set up 
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3); // Clk :7, Din :6, Dc :5, CE :4, RST :3

// Real Time Clock 
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;

// menu control var 

int menuitem = 1;
int page = 1;

volatile boolean up = false;
volatile boolean down = false;
volatile boolean select = false;
volatile boolean back = false;

int downButtonState = 0;
int upButtonState = 0;  
int selectButtonState = 0;
int backButtonState = 0;
           
int downLastButtonState = 0;
int upLastButtonState = 0;
int selectLastButtonState = 0;
int backLastButtonState = 0;

void setup() {
  Serial.begin(9600);
  
  // set up for the display
  display.begin();      
  display.setContrast(57); //Set contrast to 50
  display.clearDisplay(); 
  display.display();

  // Set up for RTC 
  //Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  // Check to see if the RTC is keeping time.  If it is, load the time from your computer.
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // This will reflect the time that your sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }

  // Set buttons
  pinMode(9, INPUT_PULLUP); // Down
  pinMode(10, INPUT_PULLUP); // Back
  pinMode(11, INPUT_PULLUP); // Select
  pinMode(12, INPUT_PULLUP); // Up

}

void loop() {


  drawMenu();

  downButtonState = digitalRead(9);
  selectButtonState = digitalRead(10);
  backButtonState = digitalRead(11);
  upButtonState =   digitalRead(12);

  checkIfDownButtonIsPressed();
  checkIfUpButtonIsPressed();
  checkIfSelectButtonIsPressed();
  checkIfBackButtonIsPressed();

  
  if (up && page == 1 ) {
    up = false;
    menuitem--;
    if (menuitem==0)
    {
      menuitem=3;
    } 
  }  
  
  if (down && page == 1) {
    down = false;
    menuitem++;
    if (menuitem==4) 
    {
      menuitem=1;
    }
  }
}




