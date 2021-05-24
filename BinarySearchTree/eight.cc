/*******************************************************************
* Name: Kevin Thomas Kehoe
* Date: 10/31/2016 
* Course: CSCI 132
* Assignment: Lab 6
* Program: eight.cc
* Purpose:  Game of eights. This program excutes the game of eights,
* prompting the player for a value and then executing the look_ahead
* function to determine the computer's value. It then determines if
* there is a winner and declares it if so and prompts user again if not.
***************************************************************************/
#include <iostream>
#include "board.h"

using namespace std;

int look_ahead(Board &, int, int &);

int main(void) {
  Board gameBoard;              //Board for playing game
  int user_move, computer_move; //Moves made by computer or user
  int depth = 8;                //depth of look ahead by computer

  gameBoard.instructions();

  while(!gameBoard.done()) {        //Play until the game is finished
     cout << "Please enter a number:  ";
     cin >> user_move;
     while (!gameBoard.is_legal(user_move)) {    
        cout << "That move is not legal, choose another number: ";
        cin >> user_move;
     } //Until a legal move is entered.

     cout << "You have chosen the number " << user_move << "." << endl;
     gameBoard.play(user_move);      //Make user's move
     cout << "The total score is " << gameBoard.getTotal() << "."
	  << endl << endl;

     if (!gameBoard.done()) {
        look_ahead(gameBoard, depth, computer_move);    //Choose computer's move
        cout << "The computer chooses the number " << computer_move << "."
	     << endl;
        gameBoard.play(computer_move);
        cout << "The total score is " << gameBoard.getTotal() << "."
	     << endl << endl;
     } //end if game not done
  } //end while the game is on

  cout << "The game is over. ";
  if (gameBoard.the_winner() == 1)   //Ties are not possible in this game
     cout << "You win!" << endl;
  else 
     cout << "The computer wins!" << endl;

  return 0;
} //end main

int look_ahead(Board &game, int depth, int &recommended) {
/* Look ahead to end of game or number of levels given by depth 
   to choose next move.
   Pre: game has been established and depth >=0
   Post: value of best option is returned, best move is stored in recommended */

  if (game.done( ) || depth == 0)
    return game.evaluate( );
  else {

    int value, best_value = game.worst_case( );

    //for loop counter (try_it = 1..3)
    for (int try_it = 1; try_it <=3; try_it++) {        
      //check if try_it is legal
      if (game.is_legal(try_it)){
	int reply;
	Board new_game = game;
	new_game.play(try_it);
	value = look_ahead(new_game, depth-1, reply);
	if (game.better(value, best_value)) {
	  // try_it is the best move yet found
	  best_value = value;
	  recommended = try_it;
	} //if this move is better
      } //if legal ends
    } //for loop ends
      return best_value;
  }//else
} //end look_ahead
