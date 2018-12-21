#ifndef _LCDKEYPAD_H_
#define _LCDKEYPAD_H_

#include <LiquidCrystal.h>


// library interface description
#define KEYPAD_RIGHT 0
#define KEYPAD_UP 1
#define KEYPAD_DOWN 2
#define KEYPAD_LEFT 3
#define KEYPAD_SELECT 4

class LCDKeypad : public LiquidCrystal
{
  public:
    LCDKeypad();
    int button();
};

LCDKeypad::LCDKeypad() : LiquidCrystal(8, 9, 4, 5, 6, 7)
{
}

int LCDKeypad::button()
{
  static int NUM_KEYS=5;
  static int adc_key_val[5] ={30, 150, 360, 535, 760};

  int k = 0;
  for (k = 0; k < NUM_KEYS; k++)
  {
    if (analogRead(0) < adc_key_val[k])
    {
      return k;
    }
  }
  if (k >= NUM_KEYS)
  {
    k = -1;     // No valid key pressed
  }
  return k;
}

#endif