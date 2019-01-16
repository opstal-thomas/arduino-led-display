#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
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

//Input
#define UP 2
#define DOWN 4
#define LEFT 7
#define RIGHT 8

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(X, Y, PIN,
                            NEO_MATRIX_TOP      + NEO_MATRIX_LEFT +
                            NEO_MATRIX_ROWS     + NEO_MATRIX_ZIGZAG,
                            NEO_GRB             + NEO_KHZ800);

const int levelOneArr[20][20] = {
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

int playerHorizontalPosition = 1;
int playerVerticalPosition = 1;

//[0]horizontal - [1]vertical - [3]dir (0) = vert - (1) = hor
int enemies[5][3] = {
  {18, 1, 1},
  {15, 4, 0},
  {12, 11, 0},
  {18, 14, 1},
  {1, 11, 0},
};

unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
const long interval = 500;

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(Brightness);

  pinMode(UP, INPUT);
  pinMode(DOWN, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
}

void loop() {
  currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    UpdateEnemies();
  }

  MovePlayer();
  PlayerCollisionDetection();
  DrawPlayer();
  DrawEnemies();
  DrawLevelOne();
  
  matrix.show();
}

void UpdateEnemies() {
  for (int i = 0; i < 5; i++) {
    if (enemies[i][3] == 1) {
      //Horizontal
      if (enemies[i][2] == 1) {
        //right
        if (levelOneArr[enemies[i][0] + 1][enemies[i][1]] != 1) {
          enemies[i][0] = enemies[i][0] + 1;
        } else {
          enemies[i][2] = -1;
        }
      } else {
        //left
        if (levelOneArr[enemies[i][0] - 1][enemies[i][1]] != 1) {
          enemies[i][0] = enemies[i][0] - 1;
        } else {
          enemies[i][2] = 1;
        }
      }
    } else {
      //Vertical
      if (enemies[i][2] == 1) {
        //down
        if (levelOneArr[enemies[i][0]][enemies[i][1] + 1] != 1) {
          enemies[i][1] = enemies[i][1] + 1;
        } else {
          enemies[i][2] = -1;
        }
      } else {
        //up
        if (levelOneArr[enemies[i][0]][enemies[i][1] - 1] != 1) {
          enemies[i][1] = enemies[i][1] - 1;
        } else {
          enemies[i][2] = 1;
        }
      }
    }
  }
}

void PlayerCollisionDetection() {
  for (int i = 0; i < 5; i++) {
    if (playerHorizontalPosition == enemies[i][0] && playerVerticalPosition == enemies[i][1])
      playerHorizontalPosition = 1;
    playerVerticalPosition = 1;
  }
}

void MovePlayer() {
  if (UP) {
    if (levelOneArr[playerHorizontalPosition][playerVerticalPosition - 1] != 1)
      playerVerticalPosition = playerVerticalPosition - 1;
  }

  if (DOWN) {
    if (levelOneArr[playerHorizontalPosition][playerVerticalPosition + 1] != 1)
      playerVerticalPosition = playerVerticalPosition + 1;
  }

  if (RIGHT) {
    if (levelOneArr[playerHorizontalPosition + 1][playerVerticalPosition] != 1)
      playerVerticalPosition = playerVerticalPosition + 1;
  }

  if (LEFT) {
    if (levelOneArr[playerHorizontalPosition - 1][playerVerticalPosition] != 1)
      playerVerticalPosition = playerVerticalPosition - 1;
  }
}

void DrawPlayer() {
  matrix.drawPixel(playerHorizontalPosition, playerVerticalPosition, WHITE);
}

void DrawEnemies() {
  for (int i = 0; i < 5; i++) {
    matrix.drawPixel(enemies[i][0], enemies[i][1], RED);
  }
}

void DrawLevelOne() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (levelOneArr[i][j] == 1) {
        matrix.drawPixel(i, j, GREEN);
      }
    }
  }
}
