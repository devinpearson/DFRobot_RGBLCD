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
    // Print a message to the LCD.
    lcd.print("hello, world!");
}

void loop() {
    // Turn off the cursor:
    lcd.noCursor();
    delay(500);
    // Turn on the cursor:
    lcd.cursor();
    delay(500);
}

