/*******************************************************************
* Name: Kevin Thomas Kehoe
* Date: 10/31/2016
* Course: CSCI 132
* Assignment: Lab 6
* Program: board.cc
* Purpose: Implementation of board class
***************************************************************************/
#include "board.h"

Board :: Board() {
/* Post: Board is created and all variables initialized to zero */
    total = 0;
    moves_done = 0;
    last_move = 0;
} //Board constructor

int Board::evaluate( ) const {
/* Post: If player 1 wins, returns a value of 9 minus the number of moves taken,
   If player 2 wins, returns a value of -9 plus the number of moves taken. 
   If no winner yet, returns zero. */
  if (the_winner() == 1)
      return (9 - moves_done);
  else if (the_winner() == 2)
    return (-9 + moves_done);
  else 
    return 0;
} //evaluate

bool Board::better(int value, int old_value) const {
/* Post: Returns true if value is better than old_value for the current player */
  if (moves_done % 2 == 0){
    return value > old_value;
  } else
    return value < old_value;
} //better

int Board::worst_case( ) const {
/* Post: Returns the worst case value for the current player */
  if (moves_done % 2 == 0)
    return -9;
  else  
    return 9;
} //worst_case

bool Board :: is_legal(int move) const {
/* Post: Returns true if proposed move is legal, false otherwise */
  if ((1 <= move) && (move <= 3)){
      if(move != last_move)
	return true;
    }
  return false;
} //is_legal

void Board::play(int move) {
/* Post: If move is legal, increments total by move, sets last_move to move and
	increments moves_done.  If move is not legal, it prints out an error message.*/
  if (is_legal(move)) {
    total += move;
    last_move = move;
    moves_done++;
  } //try the move
  else
    cout << "Not a legal move! " << endl; 
} //play


int Board::the_winner() const {
/* Post: Returns 1 if player 1 has won, 2 if player 2 has won, 
         and 0 if no winner yet */
   if (!done())
      return 0;
   else if (total > 8) 
      return moves_done%2 + 1;
   else 
      return 2 - moves_done%2;
} //the winner

bool Board::done() const {
/* Post: Returns true if the game is over, false otherwise */
  if (total >= 8)
    return true;
  else
    return false;
} //done

int Board::getTotal( ) const {
/* Post: Returns total score so far. */
  return total;
} //getTotal

void Board::instructions() {
/* Post: Prints out the instructions for the game. */
   cout << "Welcome to the game of eight!" << endl;
   cout << "In this game the players take turns choosing a number, 1, 2 or 3." 
        << endl;
   cout << "You may not choose the last number chosen. " << endl;
   cout << "A running total of the numbers is kept." << endl;
   cout << "If a player chooses a number to make the total equal to eight, " 
        << endl << "that player wins." << endl;
   cout << "If a player chooses a number to make the total greater than eight, "
        << endl << "that player loses." << endl << endl;
} //instructions

