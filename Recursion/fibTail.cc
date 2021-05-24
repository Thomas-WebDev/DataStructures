/**************************************************************
 * Filename: fibTail.cc
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
*Uses: method int fibIter(int n)
************************************************************************/
{
  int n;
  cout << "Enter an integer: ";
  cin >> n;
  fibIter(int n).fibIter();
  cout << endl << "The fibonacci number for month " << n << " is " << endl;
}

int fibTail(int n, int i, int fib_i_minus1, int fib_i)
/***********************************************************************
*Pre: Initial values of n, i, fib_i_minus1 and fib_i
*Post: Returns int of the value of the fibonacci numbers for value of n or
*calls fibTail recursively
*Uses: method int fibTail(int n, int i, int fib_i_minus1, int fib_i)
************************************************************************/
{
  if (n == 1){
    return fib_i;
  } else {
    return fibTail(n - 1, i + 1 ,fib_i, fib_i + fib_i_minus1);
  }
}

/***********************************************************************
*Pre: Value of the number of months passed in
*Post: Sets i, fib_i, fib_i_minus1 to values and passes them, along with n
*into fibTail
*Uses: method int fibTail(int n, int i, int fib_i_minus1, int fib_i)
************************************************************************/
int fibIter(int n)
{
  i = 1;
  fib_i_minus1 = 0;
  fib_i = 1;
  fibTail(n, i, fib_i_minus1, fib_i);
}

