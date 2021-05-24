/*******************************************************************
 * Name: Kevin Thomas Kehoe
 * Date: 11/07/2016
 * Course: CSCI 132
 * Assignment: Assignement 6
 * Program: list_functions.cc
 * Note: interchange, reverse_traverse_list, join, reverse and split
 *       implimented by author, the rest was provided by Professor
 * Purpose: Implementation more methods for the list class which has been
 *          initialized as an array list.
 ***************************************************************************/

#include <iostream>
#include "list.h"
#include "list.cc"

using namespace std;

Error_code interchange(int pos1, int pos2, List &a_list)
  /* Post: Any entries at positions pos1 and pos2 of 
     List a_list are interchanged. If either entry is
     missing a code of range_error is returned. */
{
  if (a_list.empty() && pos1 <= a_list.size() && pos2 <= a_list.size()) 
     return range_error;
  List_entry x;
  List_entry y;
  a_list.retrieve(pos1, x);
  a_list.retrieve(pos2, y);
  a_list.replace(pos1, y);
  a_list.replace(pos2, x);
  return success;
} //end interchange

void reverse_traverse_list(List &a_list, void (*visit)(List_entry &))
  /* Post: The List a_list is traversed, in reverse order, and 
     the function *visit is applied to all entries. */
{
  List_entry x;
  for (int i = a_list.size() - 1; i >= 0; i--){
    (a_list.retrieve(i, x));
    (*visit)(x);
  }
} //end reverse_traverse_list


Error_code join(List &list1, List &list2)
  /* Post: All entries from list1 are copied onto the 
     end of list2. A code of overflow is returned if
     list2 is filled up before the copying is complete. */
{
  for (int i = 0; i < list1.size(); i++){
    if (list2.full())
      return overflow;
    List_entry x;
    list1.retrieve(i, x);
    list2.insert(list2.size(), x);
  }
  return success;
} //end join

Error_code reverse(List &a_list)
  /* Post: Reverses the order of all entries in a_list. 
     A code of fail is returned in case the reversal
     cannot be completed. */
{
  int pos1 = 0;
  int pos2 = a_list.size() - 1;
  while((pos1 < pos2)){
    interchange(pos1, pos2, a_list);
    pos1++;
    pos2--;
  }
  return success;
} //end reverse

Error_code split(List &source, List &oddlist, List &evenlist)
  /* Post: Copies all entries from source so that those 
     in odd-numbered positions make up oddlist
     and those in even-numbered positions make up 
     evenlist. Returns an error code of
     overflow in case either output list fills before 
     the copy is complete. */
{
  List_entry x;
  for (int i = 0; i < source.size(); i++){
    if(oddlist.full() || evenlist.full())
      return overflow;
    if (i % 2 == 0){
      source.retrieve(i, x);
      evenlist.insert(evenlist.size(), x);
    } else {
      source.retrieve(i, x);
      oddlist.insert(oddlist.size(), x);
    }   
  }
  return success;
} //end split

void print(int &x) {
  cout << x << " ";
} //end print

int main(void) {
	List myList;
	
	cout << "Creating list. " << endl;
	
	for (int i = 0; i < 10; i++) {
		myList.insert(i, i);
	} // for 
	
	myList.traverse(print);
	
	cout << endl << endl << "Interchanging positions 2 and 3 of list. " << endl;
	Error_code outcome = interchange(2, 3, myList);
	if (outcome != success) {
		cout << "Error in interchange: " << outcome << endl;
	} //if interchange failed 
        else {
		myList.traverse(print);
	} //else traverse the interchanged list
	
	cout << endl << endl 
	     << "Switching positions 2 and 3 back to original positions. " << endl;
	outcome = interchange(2, 3, myList);
	if (outcome != success) {
		cout << "Error in interchange: " << outcome << endl;
	} //if interchange failed 
        else {
		myList.traverse(print);
	} //else traverse the interchanged list

	cout << endl << endl << "Printing list in reverse. " << endl;
	reverse_traverse_list(myList, print);
	
	cout << endl << endl << "Splitting list into odds and evens. " << endl;
	List oddList, evenList;
	outcome = split(myList, oddList, evenList);
	if (outcome != success) {
		cout << "Error in splitting list: " << outcome << endl;
	} //if the list could not be split 
        else {
		cout << "Printing odd list. " << endl;
		oddList.traverse(print);
		cout << endl << endl << "Printing even list. " << endl;
		evenList.traverse(print);
	} //else the list was split, print each list
	
	cout << endl << endl << "Joining odd and even lists." << endl;
	outcome = join(oddList, evenList);
	if (outcome != success) {
		cout << "Error in joining lists. " << outcome << endl;
	} //if the join was unsuccessful 
        else {
		evenList.traverse(print);
	} //else print after joining
	
	cout << endl << endl << "Reversing list. " << endl;
	reverse(evenList);
	evenList.traverse(print);

	cout << endl;
	return 0;
} //end main
	
