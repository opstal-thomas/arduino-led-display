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

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(X, Y, PIN,
                            NEO_MATRIX_TOP      + NEO_MATRIX_LEFT +
                            NEO_MATRIX_ROWS     + NEO_MATRIX_ZIGZAG,
                            NEO_GRB             + NEO_KHZ800);

const PROGMEM int row1[20] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
const PROGMEM int row2[20] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
const PROGMEM int row3[20] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1};
const PROGMEM int row4[20] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1};
const PROGMEM int row5[20] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1};

const PROGMEM int row6[20] = {1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1};
const PROGMEM int row7[20] = {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1};
const PROGMEM int row8[20] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
const PROGMEM int row9[20] = {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1};
const PROGMEM int row10[20] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1};

const PROGMEM int row11[20] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1};
const PROGMEM int row12[20] = {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1};
const PROGMEM int row13[20] = {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
const PROGMEM int row14[20] = {1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1};
const PROGMEM int row15[20] = {1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

const PROGMEM int row16[20] = {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1};
const PROGMEM int row17[20] = {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1};
const PROGMEM int row18[20] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
const PROGMEM int row19[20] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1};
const PROGMEM int row20[20] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

//Level Data
const uint8_t levelOne[] PROGMEM = {
  0xff, 0xff, 0xf0,
  0x80, 0x0, 0x10,
  0xff, 0x3f, 0xd0,
  0xff, 0xff, 0xd0,
  0x80, 0xc0, 0x50,
  0xbc, 0xc0, 0x50,
  0xbf, 0xc0, 0x50,
  0x80, 0x0, 0x10,
  0xbf, 0xc0, 0x70,
  0x80, 0x40, 0x70,
  0xff, 0x40, 0x70,
  0x81, 0x40, 0x70,
  0xbd, 0x7f, 0xf0,
  0x9d, 0x7f, 0xd0,
  0x9c, 0x0, 0x10,
  0x9f, 0xf9, 0xf0,
  0xbf, 0xff, 0x10,
  0x80, 0x0, 0x10,
  0xff, 0xff, 0x10,
  0xff, 0xff, 0xf0
};

//Input
const int UP = 2;
const int DOWN = 4;
const int LEFT = 7;
const int RIGHT = 8;

int playerHorizontalPosition = 1;
int playerVerticalPosition = 1;

int enemyOneHorizontalPosition = 18;
int enemyOneDir = -1;
const int enemyOneStepCount = 15;
int enemyOneCurrentStepCount = 0;

int enemyTwoVerticalPosition = 4;
int enemyTwoDir = 1;
const int enemyTwoStepCount = 7;
int enemyTwoCurrentStepCount = 0;

int enemyThreeVerticalPosition = 11;
int enemyThreeDir = -1;
const int enemyThreeStepCount = 7;
int enemyThreeCurrentStepCount = 0;

int enemyFourVerticalPosition = 11;
int enemyFourDir = 1;
const int enemyFourStepCount = 6;
int enemyFourCurrentStepCount = 0;

int enemyFiveHorizontalPosition = 18;
int enemyFiveDir = -1;
const int enemyFiveStepCount = 9;
int enemyFiveCurrentStepCount = 0;

bool keyOneCollected = false;
bool keyTwoCollected = false;

int keys[2][2] = {
  {7, 5},
  {18, 13},
};

int enemies[5][2] = {
  {18, 1},
  {15, 4},
  {12, 11},
  {18, 14},
  {1, 11},
};

void UpdateEnemys() {
  UpdateEnemyOne();
  UpdateEnemyTwo();
  UpdateEnemyThree();
  UpdateEnemyFour();
  UpdateEnemyFive();
}

void setup() {
  Serial.begin(9600);

  pinMode(UP, INPUT);
  pinMode(DOWN, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);

  matrix.begin();
  matrix.setBrightness(Brightness);
}

void loop() {
  matrix.fillScreen(0);
  MovePlayer();
  UpdateEnemys();
  PlayerCollisionDetection();
  DrawPlayer();
  DrawLevelOne();
  DrawKeys();
  DrawEnemies();

  if (keyOneCollected && keyTwoCollected)
    DrawDoor();

  matrix.show();

  delay(100);
}

void PlayerCollisionDetection() {
  for (int i = 0; i < 5; i++) {
    if (playerHorizontalPosition == enemies[i][0] && playerVerticalPosition == enemies[i][1])
      playerHorizontalPosition = 1;
    playerVerticalPosition = 1;
  }

  if ((playerHorizontalPosition == keys[0][0]) && (playerVerticalPosition == keys[0][1]))
    keyOneCollected = true;

  if ((playerHorizontalPosition == keys[1][0]) && (playerVerticalPosition == keys[1][1]))
    keyTwoCollected = true;
}

void MovePlayer() {
  if (digitalRead(2) == HIGH) {
    if (GetRow(playerHorizontalPosition, playerVerticalPosition - 1) != 1)
      playerVerticalPosition--;
  }

  if (digitalRead(4) == HIGH) {
    Serial.println("DOWN");
    if (GetRow(playerHorizontalPosition, playerVerticalPosition + 1) != 1)
      playerVerticalPosition++;
  }

  if (digitalRead(7) == HIGH) {
    Serial.println("RIGHT");
    if (GetRow(playerHorizontalPosition + 1, playerVerticalPosition) != 1)
      playerHorizontalPosition++;
  }

  if (digitalRead(8) == HIGH) {
    Serial.println("LEFT");
    if (GetRow(playerHorizontalPosition - 1, playerVerticalPosition) != 1)
      playerHorizontalPosition--;
  }
}

void DrawPlayer() {
  matrix.drawPixel(playerHorizontalPosition, playerVerticalPosition, WHITE);
}

void UpdateEnemyOne() {
  if (enemyOneCurrentStepCount != enemyOneStepCount) {
    enemyOneCurrentStepCount = enemyOneCurrentStepCount + 1;
    if (enemyOneDir == -1)
      enemyOneHorizontalPosition = enemyOneHorizontalPosition - 1;
    else
      enemyOneHorizontalPosition = enemyOneHorizontalPosition + 1;
  } else {
    enemyOneCurrentStepCount = 0;

    if (enemyOneDir == -1)
      enemyOneDir = 1;
    else
      enemyOneDir = -1;
  }

  enemies[0][0] = enemyOneHorizontalPosition;
}

void UpdateEnemyTwo() {
  if (enemyTwoCurrentStepCount != enemyTwoStepCount) {
    enemyTwoCurrentStepCount = enemyTwoCurrentStepCount + 1;
    if (enemyTwoDir == -1)
      enemyTwoVerticalPosition = enemyTwoVerticalPosition - 1;
    else
      enemyTwoVerticalPosition = enemyTwoVerticalPosition + 1;
  } else {
    enemyTwoCurrentStepCount = 0;

    if (enemyTwoDir == -1)
      enemyTwoDir = 1;
    else
      enemyTwoDir = -1;
  }

  enemies[1][1] = enemyTwoVerticalPosition;
}

void UpdateEnemyThree() {
  if (enemyThreeCurrentStepCount != enemyThreeStepCount) {
    enemyThreeCurrentStepCount = enemyThreeCurrentStepCount + 1;
    if (enemyThreeDir == -1)
      enemyThreeVerticalPosition = enemyThreeVerticalPosition - 1;
    else
      enemyThreeVerticalPosition = enemyThreeVerticalPosition + 1;
  } else {
    enemyThreeCurrentStepCount = 0;

    if (enemyThreeDir == -1)
      enemyThreeDir = 1;
    else
      enemyThreeDir = -1;
  }

  enemies[2][1] = enemyThreeVerticalPosition;
}

void UpdateEnemyFour() {
  if (enemyFourCurrentStepCount != enemyFourStepCount) {
    enemyFourCurrentStepCount = enemyFourCurrentStepCount + 1;
    if (enemyFourDir == -1)
      enemyFourVerticalPosition = enemyFourVerticalPosition - 1;
    else
      enemyFourVerticalPosition = enemyFourVerticalPosition + 1;
  } else {
    enemyFourCurrentStepCount = 0;

    if (enemyFourDir == -1)
      enemyFourDir = 1;
    else
      enemyFourDir = -1;
  }

  enemies[3][1] = enemyFourVerticalPosition;
}

void UpdateEnemyFive() {
  if (enemyFiveCurrentStepCount != enemyFiveStepCount) {
    enemyFiveCurrentStepCount = enemyFiveCurrentStepCount + 1;
    if (enemyFiveDir == -1)
      enemyFiveHorizontalPosition = enemyFiveHorizontalPosition - 1;
    else
      enemyFiveHorizontalPosition = enemyFiveHorizontalPosition + 1;
  } else {
    enemyFiveCurrentStepCount = 0;

    if (enemyFiveDir == -1)
      enemyFiveDir = 1;
    else
      enemyFiveDir = -1;
  }

  enemies[4][0] = enemyFiveHorizontalPosition;
}

void DrawEnemies() {
  matrix.drawPixel(enemyOneHorizontalPosition, 1, RED);
  matrix.drawPixel(15, enemyTwoVerticalPosition, RED);
  matrix.drawPixel(11, enemyThreeVerticalPosition, RED);
  matrix.drawPixel(1, enemyFourVerticalPosition, RED);
  matrix.drawPixel(enemyFiveHorizontalPosition, 14, RED);
}

void DrawKeys() {
  if (!keyOneCollected)
    matrix.drawPixel(7, 5, BLUE);

  if (!keyTwoCollected)
    matrix.drawPixel(18, 13, BLUE);
}

void DrawDoor() {
  matrix.fillRect(17, 16, 2, 3, YELLOW);
}

void DrawLevelOne() {
  matrix.drawBitmap(0, 0, levelOne, 20, 20, GREEN);
}

int GetRow(int horizontal, int vertical) {
  switch (vertical) {
    case 0:
      return row1[horizontal];
    case 1:
      return row2[horizontal];
    case 2:
      return row3[horizontal];
    case 3:
      return row4[horizontal];
    case 4:
      return row5[horizontal];
    case 5:
      return row6[horizontal];
    case 6:
      return row7[horizontal];
    case 7:
      return row8[horizontal];
    case 8:
      return row9[horizontal];
    case 9:
      return row10[horizontal];
    case 10:
      return row11[horizontal];
    case 11:
      return row12[horizontal];
    case 12:
      return row13[horizontal];
    case 13:
      return row14[horizontal];
    case 14:
      return row15[horizontal];
    case 15:
      return row16[horizontal];
    case 16:
      return row17[horizontal];
    case 17:
      return row18[horizontal];
    case 18:
      return row19[horizontal];
    case 19:
      return row20[horizontal];
  }
}
