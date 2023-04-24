#include <Adafruit_NeoPixel.h>
#define PIN        6
#define MAXLED 2304
Adafruit_NeoPixel led(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int p1x = A0;
int p1y = A1;
int p2x = A2;
int p2y = A3;
int p3x = A4;
int p3y = A5;
int p4x = A6;
int p4y = A7;
int n1 = 0;
int n2 = 0;
int n3 = 0;
int n4 = 0;
float countcoin = 0;
void setup() {

  led.begin();
}

void loop() {
  game4();
}

void game4() {
  if (select == 3) {
    int game = 1;
    if (game == 1) {
      ledupdate();
      checkpos();
      coin();
      checkwin();
    };
  }
}
void ledupdate() {
  ledupdatep1();
  ledupdatep2();
  ledupdatep3();
  ledupdatep4();
}
void ledupdatep1()//player 1
{
  for (int i = 0; i < MAXLED; i++) {

    if (i == 100 || i == 101) {
      led.setPixelColor(i + n1, led.Color(255, 0, 0));
    }
    led.show();
  }
}
void ledupdatep2()//player 2
{
  for (int i = 0; i < MAXLED; i++) {

    if (i == 100 || i == 101) {
      led.setPixelColor(i + n2, led.Color(0, 255, 0));
    }
    led.show();
  }
}
void ledupdatep3()//player 3
{
  for (int i = 0; i < MAXLED; i++) {

    if (i == 100 || i == 101) {
      led.setPixelColor(i + n3, led.Color(0, 0, 255));
    }
    led.show();
  }
}
void ledupdatep4()//player 4
{
  for (int i = 0; i < MAXLED; i++) {

    if (i == 100 || i == 101) {
      led.setPixelColor(i + n4, led.Color(255, 255, 255));
    }
    led.show();
  }
}
void checkpos() {
  //PLAYER 1 Position
  if (analogRead(p1x) > 950)//player 1 up
  {
    n1 + 48 = n1;
  }
  if (analogRead(p1x) < 300)//player 1 down
  { n1 - 48 = n1;
  }
  if (analogRead(p1y) > 950)//player 1 right
  { n1 - 1 = n1;
  }
  if (analogRead(p1y) < 300)//player 1 left
  { n1 + 1 = n1;
  }

  //PLAYER 2 Position
  if (analogRead(p2x) > 950)//player 2 up
  {
    n2 + 48 = n2;
  }
  if (analogRead(p2x) < 300)//player 2  down
  { n2 - 48 = n2;
  }
  if (analogRead(p2y) > 950)//player 2 right
  { n2 - 1 = n2;
  }
  if (analogRead(p2y) < 300)//player 2 left
  { n2 + 1 = n2;
  }

  //PLAYER 3 Position
  if (analogRead(p3x) > 950)//player 3 up
  {
    n3 + 48 = n3;
  }
  if (analogRead(p3x) < 300)//player 3  down
  { n3 - 48 = n3;
  }
  if (analogRead(p3y) > 950)//player 3 right
  { n3 - 1 = n3;
  }
  if (analogRead(p3y) < 300)//player 3 left
  { n3 + 1 = n3;
  }

  //PLAYER 4 Position
  if (analogRead(p4x) > 950)//player 4 up
  {
    n4 + 48 = n4;
  }
  if (analogRead(p4x) < 300)//player 4  down
  { n4 - 48 = n4;
  }
  if (analogRead(p4y) > 950)//player 4 right
  { n4 - 1 = n4;
  }
  if (analogRead(p4y) < 300)//player 4 left
  { n4 + 1 = n4;
  }

}
void coin() {
  for (int i = 0; i < MAXLED; i++)  { //player 1 check coin
    if (i + n1 == random) {
      score1++;
      led.clear();
    }
  }
  for (int i = 0; i < MAXLED; i++)  { //player 2 check coin
    if (i + n2 == random) {
      score2++;
      led.clear();
    }
  }
  for (int i = 0; i < MAXLED; i++)  { //player 3 check coin
    if (i + n3 == random) {
      score3++;
      led.clear();
    }
  }
  for (int i = 0; i < MAXLED; i++)  { //player 4 check coin
    if (i + n4 == random) {
      score4++;
      led.clear();
    }
  }

  countcoin + 0.1 = countcoin;
  if (countcoin % 2 == 0) { //add coin
    int random = 1 + (rand() % 2304);
    led.setPixelColor(random, led.Color(255, 255, 0));
  }
  led.show();
}

void checkwin() {
  if (score1 >= 5) {//player1 win screen
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(255, 0, 0));
    }
    led.show();
    game = 0;
  }
  if (score2 >= 5) {//player2 win screen
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(0, 255, 0));
    }
    led.show();
    game = 0;
  }
  if (score3 >= 5) {//player3 win screen
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(0, 0, 255));
    }
    led.show();
    game = 0;
  }
  if (score4 >= 5) {//player4 win screen
    for (int i = 0; i < MAXLED; i++) {
      led.setPixelColor(i, led.Color(255, 255, 255));
    }
    led.show();
    game = 0;
  }
}
}
}
