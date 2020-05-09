/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
#include <iostream>

using namespace std;

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};


TEST(PiezasTest, dropOnFill)
{
  Piezas game;
  game.dropPiece(0);
  game.dropPiece(0);
  game.dropPiece(0);
  if(game.dropPiece(0) == Blank) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}

TEST(PiezasTest, tieGame)
{
  Piezas game;
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      game.dropPiece(i);
    }
  }
  if(game.gameState() == X) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}

TEST(piezasTest, Xwins)
{
  Piezas game;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < cols; j++) {
      game.dropPiece(j);
      game.dropPiece(0);
    }
  }
  bool check = false;
  if(game.gameState() == X) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}

TEST(piezasTest, Owins)
{
  Piezas game;
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      game.dropPiece(0);
      game.dropPiece(j);
    }
  }
  bool check = false;
  if(game.gameState() == O) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}

TEST(PiezasTest, reset)
{
  Piezas game;
  game.dropPiece(1);
  game.reset();
  if(game.gameState() == ' ') {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}

TEST(PiezasTest, invalidThing)
{
  Piezas game;
  if(game.dropPiece(90) == Invalid) {
    ASSERT_TRUE(true);
  }
  else {
    ASSERT_TRUE(false);
  }
}
