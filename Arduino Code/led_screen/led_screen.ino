#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <avr/wdt.h>
#ifndef PSTR
#define PSTR
#endif

#define PIN 6
#define X 20
#define Y 20
#define Brightness 5

// Color definitions
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define YELLOW   0xFFE0
#define WHITE    0xFFFF

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(X, Y, PIN,
                            NEO_MATRIX_TOP      + NEO_MATRIX_LEFT +
                            NEO_MATRIX_ROWS     + NEO_MATRIX_ZIGZAG,
                            NEO_GRB             + NEO_KHZ800);

//Level One Data
const int levelOneData[20][20] PROGMEM = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
  {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
  {1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

const int keys[2][2] = {
  {8, 5},
  {18, 13},
};

int playerHorizontalPosition = 1;
int playerVerticalPosition = 1;

bool keyOneCollected = false;
bool keyTwoCollected = false;

int enemyData[5][6] = {
  {18, 1, 1, -1, 15, 0},
  {15, 4, -1, 1, 7, 0},
  {12, 11, -1, -1, 7, 0},
  {18, 14, 1, -1, 9, 0},
  {1, 11, -1, 1, 6, 0},
};

void setup() {
  MCUSR = 0;

  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);

  matrix.begin();
  matrix.setBrightness(Brightness);
}

void loop() {
  matrix.fillScreen(0);

  PlayerCollisionDetection();
  UpdateEnemies();
  MovePlayer();

  DrawEnemies();
  DrawPlayer();
  DrawLevel();
  DrawKeys();

  if (keyOneCollected && keyTwoCollected)
    DrawDoor();

  matrix.show();
  delay(100);
}

void UpdateEnemies() {
  for (int i = 0; i < 5; i++) {
    if (enemyData[i][2] == 1) {
      //Horizontal
      if (enemyData[i][3] == 1) {
        //Right
        if (enemyData[i][5] != enemyData[i][4]) {
          enemyData[i][0] = enemyData[i][0] + 1;
          enemyData[i][5] = enemyData[i][5] + 1;
        } else {
          enemyData[i][0] = enemyData[i][0] - 1;
          enemyData[i][3] = -1;
          enemyData[i][5] = 1;
        }
      } else {
        //Left
        if (enemyData[i][5] != enemyData[i][4]) {
          enemyData[i][0] = enemyData[i][0] - 1;
          enemyData[i][5] = enemyData[i][5] + 1;
        } else {
          enemyData[i][0] = enemyData[i][0] + 1;
          enemyData[i][3] = 1;
          enemyData[i][5] = 1;
        }
      }
    } else {
      //Vertical
      if (enemyData[i][3] == 1) {
        //Up
        if (enemyData[i][5] != enemyData[i][4]) {
          enemyData[i][1] = enemyData[i][1] + 1;
          enemyData[i][5] = enemyData[i][5] + 1;
        } else {
          enemyData[i][1] = enemyData[i][1] - 1;
          enemyData[i][3] = -1;
          enemyData[i][5] = 1;
        }
      } else {
        //Down
        if (enemyData[i][5] != enemyData[i][4]) {
          enemyData[i][1] = enemyData[i][1] - 1;
          enemyData[i][5] = enemyData[i][5] + 1;
        } else {
          enemyData[i][1] = enemyData[i][1] + 1;
          enemyData[i][3] = 1;
          enemyData[i][5] = 1;
        }
      }
    }
  }
}

void DrawEnemies() {
  for (int i = 0; i < 5; i++) {
    matrix.drawPixel(enemyData[i][0], enemyData[i][1], RED);
  }
}

void PlayerCollisionDetection() {
  for (int i = 0; i < 5; i++) {
    if (playerHorizontalPosition == enemyData[i][0] && playerVerticalPosition == enemyData[i][1]) {
      playerHorizontalPosition = 1;
      playerVerticalPosition = 1;
    }
  }

  if ((playerHorizontalPosition == keys[0][0]) && (playerVerticalPosition == keys[0][1]))
    keyOneCollected = true;

  if ((playerHorizontalPosition == keys[1][0]) && (playerVerticalPosition == keys[1][1]))
    keyTwoCollected = true;

  if (keyOneCollected && keyTwoCollected) {
    if ((playerHorizontalPosition == 17 && playerVerticalPosition == 18) || (playerHorizontalPosition == 17 && playerVerticalPosition == 17) || (playerHorizontalPosition == 17 && playerVerticalPosition == 16)) {
      wdt_enable(WDTO_15MS);

      for (;;) {

      }
    }
  }
}

void MovePlayer() {
  uint16_t readValue;

  if (digitalRead(2) == HIGH) {
    readValue = pgm_read_word(&levelOneData[playerVerticalPosition - 1][playerHorizontalPosition]);

    if (readValue != 1)
      playerVerticalPosition--;
  }

  if (digitalRead(4) == HIGH) {
    readValue = pgm_read_word(&levelOneData[playerVerticalPosition + 1][playerHorizontalPosition]);

    if (readValue != 1)
      playerVerticalPosition++;
  }

  if (digitalRead(7) == HIGH) {
    readValue = pgm_read_word(&levelOneData[playerVerticalPosition][playerHorizontalPosition + 1]);

    if (readValue != 1)
      playerHorizontalPosition++;
  }

  if (digitalRead(8) == HIGH) {
    readValue = pgm_read_word(&levelOneData[playerVerticalPosition][playerHorizontalPosition - 1]);

    if (readValue != 1)
      playerHorizontalPosition--;
  }
}

void DrawPlayer() {
  matrix.drawPixel(playerHorizontalPosition, playerVerticalPosition, WHITE);
}

void DrawKeys() {
  if (!keyOneCollected)
    matrix.drawPixel(8, 5, BLUE);

  if (!keyTwoCollected)
    matrix.drawPixel(18, 13, BLUE);
}

void DrawDoor() {
  matrix.fillRect(17, 16, 2, 3, YELLOW);
}

void DrawLevel() {
  uint16_t readValue;

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      readValue = pgm_read_word(&levelOneData[j][i]);

      if (readValue == 1) {
        matrix.drawPixel(i, j, GREEN);
      }
    }
  }
}
