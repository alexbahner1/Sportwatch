void drawTime() {
  DateTime now = RTC.now();
  int hrs = now.hour();
  int mnt = now.minute();
  int sec = now.second();
  //u8g.setFont(u8g_font_profont11);  // select font
//  u8g.setFont(u8g_font_10x20);
//  u8g.setPrintPos(2, 15);
//  u8g.print(hrs); u8g.print(":"); u8g.print(mnt); u8g.print(":"); u8g.print(sec);
  Serial.print(hrs);
  Serial.print(":");
  Serial.print(mnt);
  Serial.print(":");
  Serial.println(sec);
  
  display.setTextSize(1);
  display.clearDisplay();
  display.setTextColor(BLACK);
  display.setCursor(0, 0);
  
  //display.print("MAIN MENU");
  display.print(hrs);
  display.print(":");
  display.print(mnt);
  display.print(":");
  display.println(sec);
    display.display();
  //display.drawFastHLine(0,10,83,BLACK);
  //display.setCursor(0, 15);
}
