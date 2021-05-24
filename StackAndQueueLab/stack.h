/*******************************************************************
 * Date: 2/14/14
 * Course: CSCI 132
 * Instructor: Royden or King
 * File: stack.h
 * Purpose:  Specification of Stack class with linked lists and Node class
 ***************************************************************************/


#include <cstdlib>

using namespace std;

typedef int Stack_entry;
typedef Stack_entry Node_entry ;
enum Error_code {success, fail, underflow, overflow};


struct Node {
     //data members
  Node_entry entry ;
  Node *next ;
     //constructors
  Node();
  Node(Node_entry item ,Node *add_on = NULL );
};

class Stack {
 public:
  Stack();
  bool empty() const;
  Error_code push(const Stack_entry &item);
  Error_code pop();
  Error_code top(Stack_entry &item) const;
  int size( ) const;
 protected:
  Node *top_node ;
};
