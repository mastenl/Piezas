#include "Piezas.h"
#include <vector>
#include <iostream>
using namespace std;
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
  turn = X;
  board = {{Blank, Blank, Blank, Blank}, {Blank, Blank, Blank, Blank},{Blank, Blank, Blank, Blank}};
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
  board = {{Blank, Blank, Blank, Blank}, {Blank, Blank, Blank, Blank},{Blank, Blank, Blank, Blank}};
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/
Piece Piezas::dropPiece(int column)
{
  if(column > 3 || column < 0)
  {
    return Invalid; //Out of bounds, invalid input
  }
  for(int i = 0; i < 3; i++)
  {
    if(board[i][column] == Blank)
    {
      board[i][column] = turn;
      if(turn == X)
        turn = O;
      else
        turn = X;
      return Blank; //Open spot found
    }
  }
    return Invalid; //No spot found, column full
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
  if(row < 0 || row > 2 || column > 0  || column > 3) {
    return Invalid; //Out of bounds
  }
  else if(board[row][column] == Blank){
    return Blank;
  }
  else if(board[row][column] == O){
    return O;
  }
  else{
    return X;
  }
}
/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
  int OScore = 0, XScore = 0, player2 = 0, player1 = 0;
  for(int row=0; row<3; row++) {
    for(int col=0; col<4; col++) {
      if(board[row][col] == Blank) {
      return Invalid;
      }
    }
  }

  for(unsigned int row=0; row<board.size(); row++) {
    for(unsigned int col=0; col<board[row].size(); col++) {
      if(board[row][col] == X) {
        player2 = 0;
        player1++;
        if(player1 > XScore) {
          XScore = player1;
        }
      }
      else if(board[row][col] == O) {
        player1 = 0;
        player2++;
        if(player2 > player1) {
          OScore = player2;
      }
    }
  }
}

  for(unsigned int row=0; row<board.size(); row++) {//vert
    for(unsigned int col=0; col<board[row].size(); col++) {
      if(board[row][col] == X) {
        player2 = 0;
        player1++;
        if(player1 > XScore) {
          XScore = player1;
        }
      }
      else if(board[row][col] == O) {
        player1 = 0;
        player2++;
        if(player2 > player1) {
          OScore = player2;
        }
      }
    }
  }



  if(XScore > OScore) {//p1win
    return X;
  }
  else if(XScore < OScore){//p2win
    return O;
  }
  else {//tie
    return Blank;
  }
}
