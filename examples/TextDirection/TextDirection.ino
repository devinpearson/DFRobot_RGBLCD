 /*!
  * Copyright	[DFRobot](http://www.dfrobot.com), 2016
  * Copyright	GNU Lesser General Public License
  *
  * @author [yangyang](971326313@qq.com)
  */

#include <Wire.h>
#include <DFRobot_RGBLCD.h>

int thisChar = 'a';

DFRobot_RGBLCD lcd(16,2);  //16 characters and 2 lines of show

void setup() {
    // initialize
    lcd.init();
    // turn on the cursor:
    lcd.cursor();
}

void loop() {
    // reverse directions at 'm':
    if (thisChar == 'm') {
        // go right for the next letter
        lcd.rightToLeft();
    }
    // reverse again at 's':
    if (thisChar == 's') {
        // go left for the next letter
        lcd.leftToRight();
    }
    // reset at 'z':
    if (thisChar > 'z') {
        // go to (0,0):
        lcd.home();
        // start again at 0
        thisChar = 'a';
    }
    // print the character
    lcd.write(thisChar);
    // wait a second:
    delay(1000);
    // increment the letter:
    thisChar++;
}

