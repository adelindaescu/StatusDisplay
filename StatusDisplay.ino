#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int i;
const int buttonPin = 8;
int buttonState = 0;
int lcdState = 0;
void setup()

{
  Serial.begin(9600);
  lcd.begin(16, 2);
  digitalWrite(11, HIGH);
  pinMode (buttonPin, INPUT);
}

void loop()
{
  
  while (Serial.available() == 0);
  buttonState = digitalRead(buttonPin);
  String val = Serial.readString();
  int spaceIndex[6];
  String values[6];
  spaceIndex[0] = 0;
  int index = 0;
  for(int i=0; i<6; i++)
  {
    spaceIndex[i] = val.indexOf(' ', index);
    index = spaceIndex[i] + 1;
  }
  index = 0;
  for(i=0; i<6; i++)
  {
    values[i] = val.substring(index, spaceIndex[i]);
    index = spaceIndex[i] + 1;
  }
  if(buttonState == HIGH)
  {
    if(lcdState == 0)
    {
      lcdState = 1;
      while(lcdState == 1)
      {
        lcd.clear();
        for(i=0;i<=3;i++)
        {
          lcd.setCursor(0,0);
          //lcd.print("CPU cores:");
          //lcd.setCursor(0,1);
          lcd.print(values[i]);
          lcd.print(" ");
          delay(500);
        } 
      }
    }
  }
  else
  {
    if(lcdState == 1)
    {
      lcdState = 0;
      lcd.clear();
      for(i=4; i<6; i++)
      {
        int ram = values[i].toInt();
        lcd.print(ram);
        lcd.print(" ");
      }
    }
  }
  
//  for(i=0; i<6; i++)
//  //
//  {
//    //lcd.clear();
//    //lcd.print(spaceIndex[i]);
//    lcd.print(values[i]);
//    lcd.print(" ");
//    //if(values[i]>0)
//      //Serial.print(values[i]);
//      //Serial.print(" ");
//  }
//  delay(500);
//  lcd.clear();

}
