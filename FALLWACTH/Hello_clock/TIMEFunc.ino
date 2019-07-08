

void drawTime() {
  DateTime now = RTC.now();
  int hrs = now.hour();
  int mnt = now.minute();
  int sec = now.second();
  //u8g.setFont(u8g_font_profont11);  // select font
  u8g.setFont(u8g_font_10x20);
  u8g.setPrintPos(2, 15);
  u8g.print(hrs); u8g.print(":"); u8g.print(mnt); u8g.print(":"); u8g.print(sec);
}
