#include "Arduino.h"
#include "Switch.h"
              
Switch::Switch(byte _pin, byte PinMode, bool polarity, int debouncePeriod, int longPressPeriod, int doubleClickPeriod, int deglitchPeriod): 
pin(_pin), polarity(polarity), deglitchPeriod(deglitchPeriod), debouncePeriod(debouncePeriod), longPressPeriod(longPressPeriod), doubleClickPeriod(doubleClickPeriod) 
{ pinMode(pin, PinMode); 
  switchedTime = millis();
  debounced = digitalRead(pin);
}
 
bool Switch::poll()
{ input = digitalRead(pin);
  return process();
} 

bool Switch::process()
{ deglitch(); 
  debounce();
  calcDoubleClick();
  calcLongPress();
  return _switched;	
}

void inline Switch::deglitch()
{ ms = millis();
  if(input == lastInput) equal = 1;
  else
  { equal = 0;
    deglitchTime = ms;
  }
  if(equal & ((ms - deglitchTime) > deglitchPeriod)) // max 50ms, disable deglitch: 0ms
  { deglitched = input; 
    deglitchTime = ms;
  }
  lastInput = input;  
}

void inline Switch::debounce()
{ ms = millis();
  _switched = 0;
  if((deglitched != debounced) & ((ms - switchedTime) >= debouncePeriod)) 
  { switchedTime = ms;
    debounced = deglitched;
    _switched = 1;
    longPressDisable = false; 
  }
}

void inline Switch::calcDoubleClick()
{ _doubleClick = false;
  if(pushed())
  { _doubleClick = (ms - pushedTime) < doubleClickPeriod; // pushedTime of previous push
    pushedTime = ms; 
  } 
}

void inline Switch::calcLongPress()
{ _longPress = false;
  if(!longPressDisable)
  { _longPress = on() && ((ms - pushedTime) > longPressPeriod); // true just one time between polls
    longPressDisable = _longPress; // will be reset at next switch   
  }  
}

bool Switch::switched()
{ return _switched;
}

bool Switch::on()
{ return !(debounced^polarity);
}

bool Switch::pushed() 
{ return _switched && !(debounced^polarity); 
} 

bool Switch::released() 
{ return _switched && (debounced^polarity); 
} 

bool Switch::longPress() 
{ return _longPress;
} 

bool Switch::doubleClick() 
{ return _doubleClick;
} 



