 /*!
  * Copyright	[DFRobot](http://www.dfrobot.com), 2016
  * Copyright	GNU Lesser General Public License
  *
  * @author [yangyang](971326313@qq.com)
  */

#include <Wire.h>
#include <DFRobot_RGBLCD.h>

DFRobot_RGBLCD lcd(16,2);  //16 characters and 2 lines of show

void setup() {
    // initialize
    lcd.init();
}

void loop() {
    // set the cursor to (0,0):
    lcd.setCursor(0, 0);
    // print from 0 to 9:
    for (int thisChar = 0; thisChar < 10; thisChar++){
        lcd.print(thisChar);
        delay(500);
    }

    // set the cursor to (16,1):
    lcd.setCursor(16,1);
    // set the show to automatically scroll:
    lcd.autoscroll();
    // print from 0 to 9:
    for (int thisChar = 0; thisChar < 10; thisChar++){
        lcd.print(thisChar);
        delay(500);
    }
    // turn off automatic scrolling
    lcd.noAutoscroll();

    // clear screen for the next loop:
    lcd.clear();
}

