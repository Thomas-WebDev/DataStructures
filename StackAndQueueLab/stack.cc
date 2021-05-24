/*******************************************************************
 * Name: Kevin Thomas Kehoe
 * Date: 10/03/2016
 * Course: CSCI 132
 * Assignment: Lab 4
 * Program: stack.cc
 * Purpose: Implementation of stack class with linked lists and Node class.
 ***************************************************************************/

#include "stack.h"

Stack::Stack( ) {
  /*Post: Empty stack is created*/
  top_node = NULL;
} // default constructor

bool Stack::empty( ) const {
  /*Post: Returns true if the stack is empty, false otherwise*/
  return top_node == NULL;
} // empty?

int Stack::size( ) const {
  /*Post: Number of items in the stack is returned
  	***You must implement this function for Lab4 *****/
  int count = 0;
  Node *count_node = top_node;
  while (count_node != NULL){
    count++;
    count_node = count_node -> next;
  }
  return count;
}

Error_code Stack:: top(Stack_entry &item) const {
  /*Post:Value of top of stack is placed in item;
    returns success or returns
    a code of underflow if the stack is empty
    ***You must implement this function for Lab4 *****/
  if (top_node == NULL)
    return underflow;
  item = (*top_node).entry;
  return success;
} // top

Error_code Stack ::push(const Stack_entry &item)
  /*Post:Stack_entry item is added to the top of the Stack ;
    returns success or returns
    a code of overflow if dynamic memory is exhausted.*/
{
  Node *new_top =new Node(item ,top_node);
  if (new_top == NULL )return overflow ;
  top_node = new_top ;
  return success ;
} // push

Error_code Stack ::pop()
  /*Post:The top of the Stack is removed.If the Stack is empty the method returns
    underflow ;otherwise it returns success */
{
  Node *old_top =top_node ;
  if (top_node ==NULL )return underflow ;
  top_node =old_top ->next ;
  delete old_top;
  return success;
} // pop

Node ::Node()
{
  next = NULL ;
} //default constructor for Node struct

Node ::Node(Node_entry item, Node *add_on)
{
  entry = item ;
  next = add_on ;
} // constructor for Node struct
