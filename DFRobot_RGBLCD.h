/*!
 * @file DFRobot_RGBLCD.h
 * @brief DFRobot's LCD
 * @n High Accuracy Ambient Light Sensor
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2016
 * @copyright	GNU Lesser General Public License
 *
 * @section author [yangyang](971326313@qq.com)
 * @version  V1.0
 * @date  2017-2-10
 */


#ifndef __DFRobot_RGBLCD_H__
#define __DFRobot_RGBLCD_H__

#include <inttypes.h>
#include "Print.h"

/*!
 *  @brief Device I2C Address
 */
#define LCD_ADDRESS     (0x7c>>1) ///< LCD iic address
#define RGB_ADDRESS     (0xc0>>1) ///< RGB light iic address


/*!
 *  @brief color define
 */ 
#define WHITE           0 ///< int value for the color WHITE
#define RED             1 ///< int value for the color RED
#define GREEN           2 ///< int value for the color GREEN
#define BLUE            3 ///< int value for the color BLUE

#define REG_RED         0x04 ///< PWM2
#define REG_GREEN       0x03 ///< PWM1
#define REG_BLUE        0x02 ///< PWM0

#define REG_MODE1       0x00 ///< mode 1 id
#define REG_MODE2       0x01 ///< mode 2 id
#define REG_OUTPUT      0x08 ///< output id

/*!
 *  @brief commands
 */
#define LCD_CLEARDISPLAY 0x01   ///< Command id for clearing the display
#define LCD_RETURNHOME 0x02     ///< Command id for returning home
#define LCD_ENTRYMODESET 0x04   ///< Command id for entry mode set
#define LCD_DISPLAYCONTROL 0x08 ///< Command id for display control
#define LCD_CURSORSHIFT 0x10    ///< Command id for cursor shift
#define LCD_FUNCTIONSET 0x20    ///< Command id for function set
#define LCD_SETCGRAMADDR 0x40   ///< Command id for set CGRAM Address
#define LCD_SETDDRAMADDR 0x80   ///< Command id for set DDRAM Address

/*!
 *  @brief flags for display entry mode
 */
#define LCD_ENTRYRIGHT 0x00           ///< Flag id for LCD_ENTRYRIGHT
#define LCD_ENTRYLEFT 0x02            ///< Flag id for LCD_ENTRYLEFT
#define LCD_ENTRYSHIFTINCREMENT 0x01  ///< Flag id for LCD_ENTRYSHIFTINCREMENT
#define LCD_ENTRYSHIFTDECREMENT 0x00  ///< Flag id for LCD_ENTRYSHIFTDECREMENT

/*!
 *  @brief flags for display on/off control
 */
#define LCD_DISPLAYON 0x04  ///< Flag id for display on
#define LCD_DISPLAYOFF 0x00 ///< Flag id for display off
#define LCD_CURSORON 0x02   ///< Flag id for cursor on
#define LCD_CURSOROFF 0x00  ///< Flag id for cursor off
#define LCD_BLINKON 0x01    ///< Flag id for blink on
#define LCD_BLINKOFF 0x00   ///< Flag id for blink off

/*!
 *  @brief flags for display/cursor shift
 */
#define LCD_DISPLAYMOVE 0x08  ///< Flag id for display move
#define LCD_CURSORMOVE 0x00   ///< Flag id for cursor move
#define LCD_MOVERIGHT 0x04    ///< Flag id for move right
#define LCD_MOVELEFT 0x00     ///< Flag id for move left

/*!
 *  @brief flags for function set
 */
#define LCD_8BITMODE 0x10   ///< Flag id for 8bit mode
#define LCD_4BITMODE 0x00   ///< Flag id for 4bit mode
#define LCD_2LINE 0x08      ///< Flag id for 2 line
#define LCD_1LINE 0x00      ///< Flag id for 1 line
#define LCD_5x10DOTS 0x04   ///< Flag id for 5x10 dots
#define LCD_5x8DOTS 0x00    ///< Flag id for 5x8 dots

/*! 
    @brief  Class that stores state and functions for interacting with DFRobot RGB LCD screen
*/
class DFRobot_RGBLCD : public Print 
{

public:

  /*! 
    @brief  Class that stores state and functions for interacting with DFRobot RGB LCD screen
    @param  lcd_cols
            Number of columns on the LCD screen
    @param  lcd_rows
            Number of rows on the LCD screen
    @param  lcd_Addr
            iic address
    @param  RGB_Addr
            address of the RGB controller
*/
  DFRobot_RGBLCD(uint8_t lcd_cols,uint8_t lcd_rows,uint8_t lcd_Addr=LCD_ADDRESS,uint8_t RGB_Addr=RGB_ADDRESS);
  
  /*!
   *  @brief initialize
   */ 
  void init();
  /*!
   *  @brief clears the display
   */
  void clear();
  /*!
   *  @brief sets the cursor to zero
   */
  void home();

  /*!
   *  @brief Turn the display on/off (quickly)
   */
  void noDisplay();
  /*!
   *  @brief turns on the display
   */
  void display();

  /*!
   *  @brief Turn on and off the blinking showCursor
   */
  void stopBlink();
  /*!
   *  @brief blink the cursor
   */
  void blink();

  /*!
   *  @brief Turns the underline showCursor on/off
   */
  void noCursor();
  /*!
   *  @brief turns on the underline cursor
   */
  void cursor();

  /*!
   *  @brief These commands scroll the display without changing the RAM
   */
  void scrollDisplayLeft();
  /*!
   *  @brief scrolls the text right
   */
  void scrollDisplayRight();
 
  /*!
   *  @brief This is for text that flows Left to Right
   */
  void leftToRight();
 
  /*!
   *  @brief This is for text that flows Right to Left
   */
  void rightToLeft();

  /*!
   *  @brief This will 'left justify' text from the showCursor
   */
  void noAutoscroll();
 
  /*!
   *  @brief This will 'right justify' text from the showCursor
   */
  void autoscroll();
   
  /*!
   *  @brief Allows us to fill the first 8 CGRAM locations
   *		 with custom characters
   */
  void customSymbol(uint8_t, uint8_t[]);
  /*!
   *  @brief sets the cursor location
   */
  void setCursor(uint8_t, uint8_t);  
  
  /*!
   *  @brief sets the rgb colour of the backlight
   *  @param r
   *  @param g
   *  @param b
   */
  void setRGB(uint8_t r, uint8_t g, uint8_t b);               // set rgb
  /*!
   *  @brief sets the pwm value for the color
   *  @param color
   *  @param pwm
   */
  void setPWM(uint8_t color, uint8_t pwm){setReg(color, pwm);}      // set pwm 
  /*!
   *  @brief sets the color of the backlight
   *  @param color
   */
  void setColor(uint8_t color);
  /*!
   *  @brief resets the color
   */
  void setColorAll(){setRGB(0, 0, 0);}
  /*!
   *  @brief sets the color to white
   */
  void setColorWhite(){setRGB(255, 255, 255);}

  /*!
   *  @brief blink the LED backlight
   */
  void blinkLED(void);
  /*!
   *  @brief turns off blinking of the LED backlight
   */
  void noBlinkLED(void);

  /*!
   *  @brief send data
   *  @param value
   *  @return size_t
   */
  virtual size_t write(uint8_t value);
  
  /*!
   *  @brief send command
   */
  void command(uint8_t);
  
  /*!
   *  @brief blink() alias compatibility API function aliases
   */
  void blink_on();						// alias for blink()
  /*!
   *  @brief noBlink() alias compatibility API function aliases
   */
  void blink_off();       					// alias for noBlink()
  /*!
   *  @brief cursor() alias compatibility API function aliases
   */
  void cursor_on();      	 					// alias for cursor()
  /*!
   *  @brief noCursor() alias compatibility API function aliases
   */
  void cursor_off();      					// alias for noCursor()
  /*!
   *  @brief backlight() and nobacklight alias compatibility API function aliases
   *  @param new_val
   */
  void setBacklight(uint8_t new_val);				// alias for backlight() and nobacklight()
  /*!
   *  @brief createChar() alias compatibility API function aliases
   *  @param char_num
   *  @param rows
   */
  void load_custom_character(uint8_t char_num, uint8_t *rows);	// alias for createChar()
  /*!
   *  @brief alias compatibility API function aliases
   */
  void printstr(const char[]);
  
  /*!
   *  @brief Unsupported API functions (not implemented in this library)
   *  @return uint8_t
   */
  uint8_t status();
  /*!
   *  @brief unsupported
   *  @param new_val
   */
  void setContrast(uint8_t new_val);
  /*!
   *  @brief unsupported
   *  @return uint8_t
   */
  uint8_t keypad();
  /*!
   *  @brief unsupported
   */
  void setDelay(int,int);
  /*!
   *  @brief unsupported
   */
  void on();
  /*!
   *  @brief unsupported
   */
  void off();
  /*!
   *  @brief unsupported
   *  @param graphtype
   *  @return uint8_t
   */
  uint8_t init_bargraph(uint8_t graphtype);
  /*!
   *  @brief unsupported
   *  @param row
   *  @param column
   *  @param len
   *  @param pixel_col_end
   */
  void draw_horizontal_graph(uint8_t row, uint8_t column, uint8_t len,  uint8_t pixel_col_end);
  /*!
   *  @brief unsupported
   *  @param row
   *  @param column
   *  @param len
   *  @param pixel_col_end
   */
  void draw_vertical_graph(uint8_t row, uint8_t column, uint8_t len,  uint8_t pixel_col_end);
  
  using Print::write;
  
private:
  void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);
  void send(uint8_t *data, uint8_t len);
  void setReg(uint8_t addr, uint8_t data);
  uint8_t _showfunction;
  uint8_t _showcontrol;
  uint8_t _showmode;
  uint8_t _initialized;
  uint8_t _numlines,_currline;
  uint8_t _lcdAddr;
  uint8_t _RGBAddr;
  uint8_t _cols;
  uint8_t _rows;
  uint8_t _backlightval;
};

#endif
