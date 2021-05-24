/**************************************************************
 * Filename: fibRec.cc
 * Author: Kevin Thomas Kehoe
 * Date Modified: 10/24/2016
 * Course: CSCI132
 * Purpose: Prints out values of fibonacci numbers for n months
 **************************************************************/

#include <iostream>
using namespace std;
int fib (int);

int main(void)
/***********************************************************************
*Pre: The user supplies initial number of months
*Post: Prints out values of fibonacci numbers for n months
*Uses: method int fib (int n)
************************************************************************/
{
  int n;
  cout << "Enter an integer: ";
  cin >> n;
  fib (n);
  cout << endl << "The fibonacci number for month " << n << " is " << fib(n) << endl;
}

int fib (int n)
/***********************************************************************
*Pre: Value of the number of months passed in
*Post: Returns int of the value of the fibonacci numbers for value of n passed
*in or calls fib recursively until it calulates said number for n
************************************************************************/
{
  if (n < 2){
    return n;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}

