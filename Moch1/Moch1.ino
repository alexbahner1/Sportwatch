//Display libs
#include <SPI.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_PCD8544.h>
// Clk :7, Din :6, Dc :5, CE :4, RST :3, BL :8
//RTC libs
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;

// base setting for display
boolean backlight = true;
int BLpin = 8;
int contrast=50;

int menuitem = 1;
int page = 1;

volatile boolean up = false;
volatile boolean down = false;
volatile boolean select = false;
volatile boolean back = false;

int downButtonState = 0;
int upButtonState = 0;  
int selectButtonState = 0; 
int Back          
int lastDownButtonState = 0;
int lastSelectButtonState = 0;
int lastUpButtonState = 0;

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3); // Clk :7, Din :6, Dc :5, CE :4, RST :3

void setup() {
  // setup for buttons
  pinMode(2, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
  pinMode(BLpin, OUTPUT);
  // more base setting for display
  digitalWrite(BLpin, LOW); //Turn Backlight ON
  
  Serial.begin(9600);
  
  display.begin();      
  display.setContrast(contrast); //Set contrast to 50
  display.clearDisplay(); 
  display.display();   
}
  


void loop() {
  // put your main code here, to run repeatedly:

}
