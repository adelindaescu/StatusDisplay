#include <LiquidCrystal.h>
#include <TimedAction.h>
#include <Button.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
//int buttonState = 0;
Button button = Button(12, PULLUP);
int lcdState = 0;
void ButtonState();
TimedAction buttonCheck = TimedAction(1000, ButtonState);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  String val = Serial.readString();
  lcd.clear();
  buttonCheck.check();
  //lcdState = lcdState % 3;
  switch (lcdState) {
    case 0:
      lcd.print("0");
      break;
    case 1:
      lcd.print(1);
      break;
    case 2:
      case2(val);
      break;
    default:
      lcd.print("-1");
    }

}

void case2(String val)
{
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
  for(int i=0; i<6; i++)
  {
    values[i] = val.substring(index, spaceIndex[i]);
    index = spaceIndex[i] + 1;
    lcd.print(values[i]);
    lcd.print(" ");
  }
  
}

void ButtonState()
{
  if(button.stateChanged())
  {
    if(lcdState == 2)
      lcdState = 0;
    else
      lcdState++;
  }
}

