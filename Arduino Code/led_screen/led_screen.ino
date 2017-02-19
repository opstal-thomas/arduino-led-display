#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
#define PSTR
#endif

#define PIN 6
#define X 20
#define Y 20
#define Brightness 100

// Color definitions
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(X, Y, PIN,
  NEO_MATRIX_TOP      + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS     + NEO_MATRIX_ZIGZAG,
  NEO_GRB             + NEO_KHZ800);

//Level Data
const uint8_t levelOne[] PROGMEM= {
  0xff,0xff,0xf0,
  0x80,0x0,0x10,
  0xff,0x3f,0xd0,
  0xff,0xff,0xd0,
  0x80,0xc0,0x50,
  0xbc,0xc0,0x50,
  0xbf,0xc0,0x50,
  0x80,0x0,0x10,
  0xbf,0xc0,0x70,
  0x80,0x40,0x70,
  0xff,0x40,0x70,
  0x81,0x40,0x70,
  0xbd,0x7f,0xf0,
  0x9d,0x7f,0xd0,
  0x9c,0x0,0x10,
  0x9f,0xf9,0xf0,
  0xbf,0xff,0x10,
  0x80,0x0,0x10,
  0xff,0xff,0x10,
  0xff,0xff,0xf0
};

  
void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(Brightness);

}

void loop() {
    gameController();
    matrix.show();
}

void gameController(){
    drawLevelOne();
    drawObjectsOne();
    drawPlayerOne();
  }

void drawPlayerOne(){
    matrix.drawPixel(1,1,WHITE);
  }
void drawLevelOne(){
    matrix.drawBitmap(0,0,levelOne,20,20,BLUE);
  }
void drawObjectsOne(){
//Keys
    matrix.drawPixel(7,5,YELLOW);
    matrix.drawPixel(18,13,YELLOW);
//Door
    matrix.fillRect(17,16,2,3,RED);
  }
void drawEnemysOne(){}




