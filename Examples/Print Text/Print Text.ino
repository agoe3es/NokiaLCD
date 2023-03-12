
#include <NokiaLCD.h>

// Font sizes
#define SMALL 0
#define MEDIUM 1
#define LARGE 2

// Booleans
#define NOFILL 0
#define FILL 1

// 12-bit color definitions
#define WHITE 0xFFF
#define BLACK 0x000
#define RED 0xF00
#define GREEN 0x0F0
#define BLUE 0x00F
#define CYAN 0x0FF
#define MAGENTA 0xF0F
#define YELLOW 0xFF0
#define BROWN 0xB22
#define ORANGE 0xFA0
#define PINK 0xF6A

NokiaLCD lcd;

void setup()
{
  // Init serial comunication and the LCD display
  Serial.begin(9600);
  Serial.println("Starting");
  DDRD |= B01111100;   // Set SPI pins as output 
  PORTD |= B01111100;  // Set SPI pins HIGH
  lcd.lcd_init();
  delay(500);
  Serial.println("Done setting up the LCD");
}

void loop()
{
    /*
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    Serial.print("INPUT= ");
    Serial.println(inByte);
    rotate(inByte);
  }
  */
  // Write the title with red color on top of a blue background
  Serial.println("Printing the title");
  char text [50];
  lcd.draw_color_bar(); 
  delay(2000);
  lcd.clear(BLACK,0,0,131,131);
  lcd.PutStr("LCD6610",            5, 40, LARGE,  YELLOW,  BLACK);
  lcd.PutStr("132X132",           20, 40, LARGE,  CYAN,    BLACK);
  lcd.PutStr("Color Graphic LCD", 37, 17, SMALL,  CYAN,    BLACK);
  lcd.PutStr("www.adarshtp.googlepages.com",  50,  2, LARGE,  RED,     WHITE);
  lcd.PutStr("SMALL GREEN",       70, 37, SMALL,  GREEN,   BLACK);
  lcd.PutStr("MEDIUM BLUE",       81, 25, MEDIUM, BLUE,    BLACK);
  lcd.PutStr("LARGE PINK",        90, 27, LARGE,  PINK,    BLACK);
  lcd.PutStr("MEDIUM MAGENTA",   107, 12, MEDIUM, MAGENTA, BLACK);
  lcd.PutStr("SMALL ORANGE",     119, 30, SMALL,  ORANGE,  BLACK);
  delay(2000);
  lcd.clear(BLACK,0,0,131,131);
  lcd.SetLine(120, 10, 120, 50, YELLOW);     // Draw Line Create Rectangle
  lcd.SetLine(120, 50, 80, 50, YELLOW);
  lcd.SetLine(80, 50, 80, 10, YELLOW);
  lcd.SetLine(80, 10, 120, 10, YELLOW);
  lcd.SetLine(120, 85, 80, 105, YELLOW);     // Draw Line Create X
  lcd.SetLine(80, 85, 120, 105, YELLOW);    
  lcd.SetCircle(62, 65, 20, RED);            // Draw Circle 
  lcd.SetRect(5, 5, 125, 125, NOFILL, BLUE); // Draw box with no fill
  lcd.SetRect(10, 10, 40, 40, FILL, PINK);   // Draw box with fill
  lcd.SetRect(10, 90, 40, 120, FILL, GREEN);
  delay(2000);
  lcd.clear(BLACK,0,0,131,131);
}
