/**************************************************************
 * Filename: compare.cc
 * Author: Kevin Thomas Kehoe
 * Date Modified: September 26, 2016
 * Course: CSCI132
 * Assignment: lab 4
 * Purpose: Test deque functions
 **************************************************************/

#include <iostream>
#include "queue.h"

using namespace std;

int main(void) {

  char a;            //holds second character for comparison
  char c;            //holds character before added to queue and/or compared
  Queue queue;       //stores first string
  bool same = true;  //for same strings

  cout << "Please enter two strings separated by a colon:" << endl;
  cin.get(c);
  //seperate the first string into characters abd stores the chars in a queue
  
  while (c != ':' && c != '\n'){
    if (queue.append(c) == overflow)
      cout << "Overflow error in queue" << endl;
    cin.get(c);
  }
  //checks if there are two strings if not it returns a error statement
  cin.get(c);
  if (c == '\n'){
    cout << "The input has no colon."  << endl;
  } 
  //if there are two strings it compares them
  else {
    //checks if the two strings are the same and serves the queue as it does so
    while ((!queue.empty()) && (c != '\n')){
      queue.retrieve(a);
	if (a != c)
	  same = false;
      queue.serve();
      cin.get(c);
    }
    //returns statement if the two strings are the same
    if (same)
      cout << "The two strings are the same."  << endl;
    //returns statement if the two strings aren't the same but are the same length
    else if((queue.empty()) && c == '\n')
      cout << "The two strings are the same length, but they are different."  << endl;
    //returns a statement if lefthand string is longer
    else if((!queue.empty()) && c == '\n')
      cout << "The lefthand string is longer than the righthand string." << endl;
    //returns a statement if righthand string is longer
    else if((queue.empty()) && c != '\n')
      cout << "The righthand string is longer than the lefthand string."  << endl;    
  }
  return 0;
} //end of main function
