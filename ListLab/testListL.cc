#include "listL.h"
#include "listL.cc"
#include <iostream>
#include <cstdlib>

using namespace std;

void print(int &);

int main(void) {
  List<int> testList;

  for(int i = 0; i <= 10; i++) {
    testList.insert(i, i*2);
  }
  int test;
  testList.insert(10, 222);
  cout << "Inserted value 222 at position 10." << endl;
  testList.remove(4, test);
  cout << "Removed from position 4, value = " << test << endl;
  testList.replace(6, 111);
  cout << "Replaced position 6 with value 111." << endl;
  testList.retrieve(3, test);
  cout << "Retrieved from position 3, value = " << test << endl;
  testList.remove(0, test);
  cout << "Removed from position 0, value = " << test << endl;

  
  testList.traverse(print);
  return 0;
}

void print(int &x) {
  cout << x << endl;
}




