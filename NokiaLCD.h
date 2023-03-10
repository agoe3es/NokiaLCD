/*
  NokiaLCD.h - Library for a Nokia LCD with the epson driver.
  Created by Thomas Jespersen, July 2009 (Originally Arduino Sketch by Gravitech.us)
  Released into the public domain.
*/
#ifndef NokiaLCD_h
#define NokiaLCD_h

#include <Arduino.h>

class NokiaLCD
{
  public:
    void init();
    void draw_color_bar();
    void clear(uint16_t color, byte x0, byte y0, byte x1, byte y1);
    void PutStr(char *pString, int x, int y, int Size, int fColor, int bColor);
    void PutChar(char c, int x, int y, int size, int fColor, int bColor);
	void SetLine(int x0, int y0, int x1, int y1, int color);
	void SetRect(int x0, int y0, int x1, int y1, unsigned char fill, int color);
	void SetCircle(int x0, int y0, int radius, int color);
	void SetPixel(byte x, byte y, int color);
	void SetXY(byte x, byte y);

  private:
    void shiftBits(byte data);
    void sendData(byte data);
    void sendCMD(byte data);
};

#endif
