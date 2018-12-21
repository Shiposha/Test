#ifndef _INIT_H_
#define _INIT_H_

int keyUp, keyDown, keySelect;

uint8_t menuNowPos = 0; //текущий пункт меню
uint8_t menuEdit = 0;   //если не ноль то редактируемое поле

MenuItem menuItems[] =
    {
        MenuItem("Pulse Time", "Pt", 40, 5.1, 2, 2000, 0),
        MenuItem("Pulses Number", "Pn", 10, 1, 1, 1, 0),
        MenuItem("Pulse Pause", "Pp", 2, 1.09, 1, 10, 0),
        MenuItem("PreWeld", "Pw", 0, 1, 0, 1, 0)
    };
uint8_t menuSize = sizeof(menuItems)/sizeof(menuItems[0]);


Menu menu;
LCDKeypad lcd;


#endif