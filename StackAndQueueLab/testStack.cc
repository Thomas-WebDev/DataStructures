/**************************************************************
 * Filename: testStack.cc
 * Author: Royden or King
 * Date Modified: 2/14/11
 * Course: CSCI132
 * Purpose: Test stack functions push, top, pop and size
 **************************************************************/

#include "stack.h"
#include <iostream>

using namespace std;

int main(void) {
   Stack myStack;

   for(int i = 1; i <= 10; i++) {
      cout << "Pushing " << i << endl;
      if (myStack.push(i) == overflow) 
         cout << "Stack is full! " << i << " is lost." << endl;
      
      cout << "The stack size is " << myStack.size() << endl;
   } //pushing elements on the stack

 

   while (!myStack.empty()) {
      int temp;
      if (myStack.top(temp) == underflow) 
         cout << "Stack underflow on top().  This shouldn't happen!" << endl;
      
      cout << "Stack top is " << temp << ". ";
      cout << "Popping top. " << endl;
      if (myStack.pop() == underflow) 
         cout << "Stack underflow on pop.  This shouldn't happen!" << endl;
   } //Show the stack contents by popping

   cout << "All done!" << endl;
} //main
