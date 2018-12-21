#ifndef _DEBUG_H_
#define _DEBUG_H_

void debugVarPrint()
{
    Serial << "menuNowPos = " << menuNowPos << endl;
    Serial << "menuEdit = " << menuEdit << endl;
}

void serialRead()
{

    switch (Serial.read())
    {
    case 'w':
        keyUp = true;
        // debugVarPrint();
        break;
    case 's':
        keyDown = true;
        // debugVarPrint();
        break;
    // case 'a':
    //     // keyLeft();
    //     // debugVarPrint();
    //     break;
    // case 'd':
    //     // keyRight();
    //     // debugVarPrint();
    //     break;
    case 'q':
        // keySelect = true;
        menu.pageControl();
        // debugVarPrint();
        break;
    case 'e':
        menu.pageMain();
        // debugVarPrint();
        break;
        // case 'z':
        //     if (menuNowPos > 0) menuNowPos--;
        //     menu.pageControl();
        //     // debugVarPrint();
        //     break;
        // case 'x':
        //     if (menuNowPos < menuSize-1) menuNowPos++;
        //     menu.pageControl();
        //     debugVarPrint();
        //     break;
        case 'c':
            menuEdit = true;
            // menu.pageControl();
            debugVarPrint();
            break;
        case 'v':
            menuEdit = false;
            // menu.pageControl();
            debugVarPrint();
            break;
    }
    keyUp = false;
    keyDown = false;
    // keySelect = false;
}

#endif