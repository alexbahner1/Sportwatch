

#define RST 8
#define CE 10
#define DC 9
#define DIN 11
#define CLK 13
#include "font.h";
int Buzz = 3; 
float d = 10;
char string[8];

void setup()
{
pinMode(Buzz, OUTPUT);
digitalWrite(Buzz, LOW); 
pinMode(RST, OUTPUT);
pinMode(CE, OUTPUT);
pinMode(DC, OUTPUT);
pinMode(DIN, OUTPUT);
pinMode(CLK, OUTPUT);
digitalWrite(RST, LOW);
digitalWrite(RST, HIGH); LcdWriteCmd(0x21); // LCD extended commands
LcdWriteCmd(0xB8); // set LCD Vop (contrast)
LcdWriteCmd(0x04); // set temp coefficent
LcdWriteCmd(0x14); // LCD bias mode 1:40
LcdWriteCmd(0x20); // LCD basic commands
LcdWriteCmd(0x0C); // LCD Normal video

for(int i=0; i<504; i++) LcdWriteData(0x00);//clear LCD

LcdXY(22,2); //X axis 0 to 80
LcdWriteString("Ready?!");
delay(1000);
for(int i=0; i<504; i++) LcdWriteData(0x00);//clear LCD
LcdXY(39,2);
LcdWriteString(dtostrf(d,5,2,string));
for(int n = 0; n <= 10; n++){
  LcdXY(40,2);
  LcdWriteString(dtostrf(d,5,2,string));
  d--;
  delay (1000);
  }
  digitalWrite(Buzz, HIGH);
}


void loop(){
}
