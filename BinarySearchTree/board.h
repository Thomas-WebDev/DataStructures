/*******************************************************************
 * Date: 3/21/11
 * Course: CSCI 132
 * Instructor: Royden or King
 * File: board.h
 * Purpose:  Specification of Board class for playing the game of eight
 ***************************************************************************/
#include <iostream>

using namespace std;

class Board {
 public:
   void play(int move);
   int the_winner( void) const;
   bool done(void) const;
   int getTotal(void) const;
   int evaluate() const;
   int worst_case( ) const;
   bool better(int value, int old_value) const;
   void instructions(void);
   bool is_legal(int move) const;
   Board();
 private:
   int moves_done;
   int total;
   int last_move;
};

