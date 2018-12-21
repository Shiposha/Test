#ifndef _CLASSES_H_
#define _CLASSES_H_

class MenuItem
{
  public:
    const char *fullName;
    const char *shortName;
    float value;
    float step;
    uint8_t type; //0 - boolean, 1 - int, 2 - float
    int maxValue;
    int minValue;
    // void (*handler)();

    // MenuItem(char *fullName, char *shortName, int value, float step, uint8_t type, int maxValue, int minValue, void (*handler)()) :
    // fullName(fullName), shortName(shortName), value(value), step(step), type(type), maxValue(maxValue), minValue(minValue), handler(handler)
    // {
    // }
    MenuItem(const char *fullName, char *shortName, int value, float step, uint8_t type, int maxValue, int minValue) : 
    fullName(fullName), shortName(shortName), value(value), step(step), type(type), maxValue(maxValue), minValue(minValue)
    {
    }

    float up();
    float down();
};

class Menu
{
    public:
    void pageInfo();
    void pageMain();
    void pageControl();
    void pageTypeCheck(byte &);
};

#endif