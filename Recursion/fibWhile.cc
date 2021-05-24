/**************************************************************
 * Filename: fibRec.cc
 * Author: Kevin Thomas Kehoe
 * Date Modified: 10/24/2016
 * Course: CSCI132
 * Purpose:  Prints out values of fibonacci numbers for n months
 **************************************************************/

#include <iostream>
using namespace std;

int main(void)
/***********************************************************************
*Pre: The user supplies initial number of months
*Post: Prints out values of fibonacci numbers for n months
*Uses: method int fibWhile(int n)
************************************************************************/
{
  int n;
  cout << "Enter an integer: ";
  cin >> n;
  cout << endl << "The fibonacci number for month " << n << " is " << fibWhile(n);;
}

int fibWhile(int n)
/***********************************************************************
*Pre: Value of the number of months passed in
*Post: Returns int of the value of the fibonacci numbers for value of n passed
*in
************************************************************************/
{
  int fib_i_minus1 = 0;
  int fib_i = 1;
  int fib_i_next;
  while (n != 1){
    n = n - 1;
    fib_i_next = fib_i_minus1 + fib_i;
    fib_i_minus1 = fib_i;
    fib_i = fib_i_next;
  }
  return fib_i;
}

