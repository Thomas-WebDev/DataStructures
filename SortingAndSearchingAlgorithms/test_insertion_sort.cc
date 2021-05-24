#include <iostream>
#include <cstdlib>
#include "list.h"
#include "list.cc"
#include "key.h"
#include "key.cc"
#include "sortable_list.h"
#include "sortable_list.cc"

using namespace std;

typedef Key Record;
void test_sort(int, Sortable_list<Record> &, int);
int Randomize(int);

int main()
{
  int list_size = 20, sorts = 100;
  Sortable_list<Record> the_list;
  cout << "Enter the size of the list to test: " << endl;
  cin >> list_size;
  cout << "Timing and testing of sorting algorithms on a list of size "
       << list_size << endl << endl;
  
  test_sort(sorts, the_list, list_size);
} //main

/*Testing program:*/
void print_out(string comment, int comp_ct, int sorts)
{
  float average;
  cout << comment << " Sort Statistics: " << endl;
  cout << "Total number of comparisons was " << comp_ct << endl;
  average = (( float )comp_ct)/ (( float )sorts) ;
  cout << " Average number of comparisons per sort was " << average
    << endl;
} //print_out

/*Print out items in list */
void print(Record &x) {
  cout << x.the_key() << " ";
} //print

void test_sort(int sorts, Sortable_list<Record> &the_list, int list_size)
/*
Pre: None.
Post: The number of key comparisons and CPU time for a
sorting funtion
have been calculated.
Uses: Methods of the classes List, Random, and Timer,
together with an output function print_out
*/
{
  if (sorts <= 0 || list_size < 0){
    cout << " Exiting test: " << endl
      << " The number of searches must be positive." << endl
      << " The number of list entries must exceed 0." << endl;
    return;
  }
  int i;
  cout << "Sorting already sorted list with Insertion Sort" << endl;
  Key::comparisons = 0;
  the_list.clear();
  for (i = 0; i < list_size; i++)
    if (the_list.insert(i, i+1) != success){
      cout << " Overflow in filling list." << endl;
  }
  cout << "The list before sorting is " << endl;
  the_list.traverse(print);
  cout << endl << endl;
  the_list.insertion_sort();
  cout<< "The list after sorting is " << endl;
  the_list.traverse(print);
  cout << endl << endl;
  print_out("Sorted Insertion", Key::comparisons, 1);
  cout << endl << endl;
  cout << "Sorting reverse sorted list with Insertion Sort" << endl;
  Key::comparisons = 0;
  the_list.clear();
  for (i = 0; i < list_size; i++)
    if (the_list.insert(i, list_size - i) != success){
      cout << " Overflow in filling list." << endl;
  }
  cout << "The list before sorting is " << endl;
  the_list.traverse(print);
  cout << endl << endl;
  the_list.insertion_sort();
  cout << "The list after sorting is " << endl;
  the_list.traverse(print);
  cout << endl << endl;
  print_out("Reverse Sorted Insertion", Key::comparisons, 1);
  cout << endl << endl;
  cout << "Sorting random lists with Insertion Sort" << endl;
  Key::comparisons = 0;
  for(int j = 0; j < sorts; j++) {
  	the_list.clear();
  	for (i = 0; i < list_size; i++)
    	if (the_list.insert(i, Randomize(list_size - 1)) != success){
     	    cout << " Overflow in filling list." << endl;
  	}
 
  	the_list.insertion_sort();
  }
  print_out("Random list Insertion", Key::comparisons, sorts);
  cout << endl << endl;
}


/**********Randomize*****************************
 *Get a random number between 0 and range        *
 *************************************************/
int Randomize(int range)
{
  
  return (int)((double)rand()/((double)RAND_MAX+1.0) * (double)(range+1));  
  
}    

