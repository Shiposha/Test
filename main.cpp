#define DEBUG
#define VERSION "v1.0"
// #define LCD16x2
#define LCDKEYPADSHIELD

#include <Arduino.h>
#include <Streaming.h>

#ifdef LCDKEYPADSHIELD
    #include"lcdkeypad.h"
#endif

#include "classes.h"
#include "init.h"
#include "classes_func.h"
#ifdef DEBUG
    #include "debug.h"
#endif

//////////////////////////////////////////////////////////////////////////////
//Setup
void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);
    menu.pageInfo();
    delay(1000);
    menu.pageMain();
    
}


//////////////////////////////////////////////////////////////////////////////
//Loop
void loop()
{
#ifdef DEBUG
    serialRead();
#endif
}