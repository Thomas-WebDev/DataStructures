/**************************************************************
 * Filename: fibRec.cc
 * Author: Kevin Thomas Kehoe
 * Date Modified: 10/24/2016
 * Course: CSCI132
 * Purpose: 
 **************************************************************/

#include <iostream>
using namespace std;
int coeff (int, int);

int main(void)
/***********************************************************************
*Pre: 
*Post: computes and prints out the coefficients of pascal's triangle for the 
first n rows
************************************************************************/
{
  int n;
  cout << "Enter an integer greater than zero: ";
  cin >> n;
  for(int i = 0; i < n; i ++){
    for (int k = 0; k <= i; k ++)
      cout << coeff(i, k) << " ";
    cout << endl;
  }
}

int coeff (int n, int k)
/***********************************************************************
*Pre: Pass in range values of n and k
*Post: Returns value of the coefficient for pascal's triangle or recursively
*calls coeff(n, k) to get to value for inputs of n and k
************************************************************************/
{
  if ((k == 0 || n == k) && n >= 0){
    return 1;
  } else {
    return coeff(n-1, k) + coeff(n-1, k-1);
  }
}

