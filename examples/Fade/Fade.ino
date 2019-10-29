 /*!
  * Copyright	[DFRobot](http://www.dfrobot.com), 2016
  * Copyright	GNU Lesser General Public License
  *
  * @author [yangyang](971326313@qq.com)
  */

#include <Wire.h>
#include <DFRobot_RGBLCD.h>

DFRobot_RGBLCD lcd(16,2);  //16 characters and 2 lines of show

void breath(unsigned char color){
    for(int i=0; i<255; i++){
        lcd.setPWM(color, i);
        delay(5);
    }

    delay(500);
    for(int i=254; i>=0; i--){
        lcd.setPWM(color, i);
        delay(5);
    }

    delay(500);
}

void setup() {
    // initialize
    lcd.init();
    // Print a message to the LCD.
    lcd.print("fade demo");

}

void loop() {
    breath(REG_RED);
    breath(REG_GREEN);
    breath(REG_BLUE);
}

