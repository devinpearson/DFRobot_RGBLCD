# Grove - LCD RGB Backlight Library [![Build Status](https://travis-ci.org/devinpearson/DFRobot_RGBLCD.svg?branch=master)](https://travis-ci.org/devinpearson/DFRobot_RGBLCD)

This is a library for the DFRobot RGB Backlight display

This library works with the RGB Backlit I2C LCD Display  
    * https://www.dfrobot.com/product-1609.html

### Change Color of Backlight
One of Grove - LCD RGB Backlight's most important feature is changing the backlight color. It's very simple; just use the folowing function:

    void setRGB(int r, int g, int b);


### Clear display

You can clear the display by this function:

    void clear();


### Turn on and turn off display

    void noDisplay();			// turn off display
    void display();				// turn on display

### Blink

    void stopBlink();
    void blink();

### Cursor

    void noCursor();
    void cursor();

### Blink LED Backlight

    void blinkLED();
    void noBlinkLED();

Written by [yangyang](971326313@qq.com) for [DFRobot](http://www.dfrobot.com). GNU Lesser General Public License