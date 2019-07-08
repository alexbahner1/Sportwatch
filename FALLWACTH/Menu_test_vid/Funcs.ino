void checkIfDownButtonIsPressed()
  {
    if (downButtonState != lastDownButtonState) 
  {
    if (downButtonState == 0) 
    {
      down=true;
    }
    delay(50);
  }
   lastDownButtonState = downButtonState;
  }

void checkIfUpButtonIsPressed()
{
  if (upButtonState != lastUpButtonState) 
  {
    if (upButtonState == 0) {
      up=true;
    }
    delay(50);
  }
   lastUpButtonState = upButtonState;
}

void checkIfSelectButtonIsPressed()
{
   if (selectButtonState != lastSelectButtonState) 
  {
    if (selectButtonState == 0) {
      middle=true;
    }
    delay(50);
  }
   lastSelectButtonState = selectButtonState;
}

  
  void drawMenu()
  {
    
  if (page==1) 
  {    
    display.setTextSize(1);
    display.clearDisplay();
    display.setTextColor(BLACK, WHITE);
    display.setCursor(15, 0);
    display.print("MAIN MENU");
    display.drawFastHLine(0,10,83,BLACK);
    display.setCursor(0, 15);
   
    if (menuitem==1) 
    { 
      display.setTextColor(WHITE, BLACK);
    }
    else 
    {
      display.setTextColor(BLACK, WHITE);
    }
    display.print(">Contrast");
    display.setCursor(0, 25);
   
    if (menuitem==2) 
    {
      display.setTextColor(WHITE, BLACK);
    }
    else 
    {
      display.setTextColor(BLACK, WHITE);
    }    
    display.print(">Light: ");
    
    if (backlight) 
    {
      display.print("ON");
    }
    else 
    {
      display.print("OFF");
    }
    display.display();
    
    if (menuitem==3) 
    { 
      display.setTextColor(WHITE, BLACK);
    }
    else 
    {
      display.setTextColor(BLACK, WHITE);
    }  
    display.setCursor(0, 35);
    display.print(">Reset");
    display.display();
  }
    
 
  else if (page==2) 
  {
    
    display.setTextSize(1);
    display.clearDisplay();
    display.setTextColor(BLACK, WHITE);
    display.setCursor(15, 0);
    display.print("CONTRAST");
    display.drawFastHLine(0,10,83,BLACK);
    display.setCursor(5, 15);
    display.print("Value");
    display.setTextSize(2);
    display.setCursor(5, 25);
    display.print(contrast);
 
    display.setTextSize(2);
    display.display();
  }
  
  }

  void resetDefaults()
  {
    contrast = 50;
    setContrast();
    backlight = true;
    turnBacklightOn();
  }

  void setContrast()
  {
    display.setContrast(contrast);
    display.display();
  }

  void turnBacklightOn()
  {
    digitalWrite(7,LOW);
  }

    void turnBacklightOff()
  {
    digitalWrite(7,HIGH);
  }
