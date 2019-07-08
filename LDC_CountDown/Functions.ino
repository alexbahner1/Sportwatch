void LcdWriteString(char *characters)
{
  while(*characters) LcdWriteChar(*characters++);
}

void LcdWriteChar(char character)
{
  for(int i=0; i<5; i++) LcdWriteData(ASCII[character - 0x20][i]);
  LcdWriteData(0x00);
}

void LcdWriteData(byte dat)
{
digitalWrite(DC, HIGH); //DC pin is low for commands
digitalWrite(CE, LOW);
shiftOut(DIN, CLK, MSBFIRST, dat); //transmit serial data
digitalWrite(CE, HIGH);
}

void LcdXY(int x, int y)
{
  LcdWriteCmd(0x80 | x); //Column
  LcdWriteCmd(0x40 | y); //Row
}

void LcdWriteCmd(byte cmd)
{
digitalWrite(DC, LOW); //DC pin is low for commands
digitalWrite(CE, LOW);
shiftOut(DIN, CLK, MSBFIRST, cmd); //transmit serial data
digitalWrite(CE, HIGH);
}
