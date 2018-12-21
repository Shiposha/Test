#ifndef _CLASSES_FUNC_H_
#define _CLASSES_FUNC_H_

void Menu::pageTypeCheck(byte &menuPos)
{
    if (menuItems[menuPos].type == 0) //booolean
        lcd << (menuItems[menuPos].value ? "on" : "off");
    if (menuItems[menuPos].type == 1) //int
        lcd << (int)menuItems[menuPos].value;
    if (fabs(menuItems[menuPos].type == 2)) //float
    {
        if (fabs(menuItems[menuPos].value) < 0.01)
            lcd << (float)menuItems[menuPos].value;
        else
            lcd.print((float)menuItems[menuPos].value, 1);
    }
}

void Menu::pageControl()
{
    lcd.clear();
    if (!menuEdit)
    {
        if (keyUp)
        {
            if (menuNowPos < menuSize - 1) menuNowPos++;
        }
        if (keyDown)
        {
            if (menuNowPos > 0) menuNowPos--;
        }
        lcd.print(menuItems[menuNowPos].fullName);
        lcd.setCursor(0, 1);
        menu.pageTypeCheck(menuNowPos);
        lcd.setCursor(0, 1); lcd.noBlink();
    }

    if (menuEdit)
    {
        if (keyUp) menuItems[menuNowPos].value += menuItems[menuNowPos].step;
        if (keyDown) menuItems[menuNowPos].value -= menuItems[menuNowPos].step;
        lcd.setCursor(0, 1); lcd.blink();
    }
}

void Menu::pageMain()
{
    lcd.clear();
    for (byte i = 0; i < menuSize; i++)
    {
        if (i == 1)
            lcd.setCursor(8, 0);
        if (i == 2)
            lcd.setCursor(0, 1);
        if (i == 3)
            lcd.setCursor(8, 1);

        lcd << menuItems[i].shortName << " ";
        menu.pageTypeCheck(i);
    }
}

void Menu::pageInfo()
{
    lcd.clear();
    lcd << "Spot Welder Ship";
    lcd.setCursor(0,1);
    lcd << VERSION;
}

float MenuItem::up()
{
    value += step;
    return value = ((int)value > maxValue) ? minValue : value;
}

float MenuItem::down()
{
    value -= step;
    return value = ((int)value < minValue) ? maxValue : value;
}

#endif