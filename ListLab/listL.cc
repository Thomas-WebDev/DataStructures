/*******************************************************************
 * Name: Kevin Thomas Kehoe
 * Date: 11/07/2016
 * Course: CSCI 501A
 * Program: listL.cc
 * Note: remove(), replace() and retrieve() implimented by author, the
 *       rest was provided by Professor
 * Purpose: Implementation of listL class as a linked list.
 ***************************************************************************/

#include "listL.h"

template <class Node_entry>
Node<Node_entry> :: Node ( ) {
	 next =NULL ;
}

template <class Node_entry>
Node<Node_entry> ::Node(Node_entry item ,Node<Node_entry> *add_on)
{
  entry =item ;
  next =add_on ;
}

template<class List_entry>
List<List_entry>:: List( ) {
/*Post: The List has been created and is initialized to be empty.*/
  count = 0;
  head = NULL;
}

template <class List_entry>
Error_code List<List_entry> :: remove(int position, List_entry &x)
  /*Post: If 0 <= position < n, where n is the number of entries in the List,
  the function succeeds: The entry at position is removed from the
  List, and all later entries have their position numbers decreased
  by 1. The parameter x records a copy of the entry formerly at
  position.
  Else: The function fails with a diagnostic error code.*/
{
  if (position < 0 || position >= count)
    return range_error;
  Node<List_entry> *position_node, *previous_node, *proceeding_node;
  position_node = set_position(position);
  if (position > 0) {
    previous_node = set_position(position - 1);
    proceeding_node = position_node -> next;
    previous_node -> next = proceeding_node;
    delete position_node;
  } else {
    head = head -> next;
    delete position_node;    
  }
  count--;
  return success;
}


template<class List_entry>
Error_code List<List_entry> :: retrieve(int position, List_entry &x ) const
  /*Post: If 0 <= position < n, where n is the number of entries in the List,
  the function succeeds: The entry at position is copied to x; all
  List entries remain unchanged.
  Else: The function fails with a diagnostic error code.*/
{
  if (position < 0 || position > count)
    return range_error;
  Node<List_entry> *position_node;
  position_node = set_position(position);
  x = (*position_node).entry;
  return success;
}

template <class List_entry>
Error_code List<List_entry> :: replace(int position, const List_entry &x )
  /*Post: If 0 <= position < n, where n is the number of entries in the List,
  the function succeeds: The entry at position is replaced by x; all
  other entries remain unchanged.
  Else: The function fails with a diagnostic error code. */
{
  if (position < 0 || position > count)
    return range_error;
  Node<List_entry> *original_node, *replace_node, *previous_node, *proceeding_node;
  original_node = set_position(position);
  proceeding_node = set_position(position + 1);
  replace_node = new Node<List_entry>(x, proceeding_node);
  if (position > 0) {
    previous_node = set_position(position - 1);
    previous_node -> next = replace_node;
    delete original_node;
  } else {
    replace_node = head;
    delete original_node;    
  }
  return success;
}

template<class List_entry>
int List<List_entry> :: size( ) const
  /* Post: The function returns the number of entries in the List. */
{
  return count;
}

template<class List_entry>
bool List<List_entry> :: full( ) const
  /*Post: The function returns true or false according to whether the List
  is full or not.*/
{
  Node<List_entry> new_node = new Node<List_entry>;
  return new_node == NULL;
}

template<class List_entry>
bool List<List_entry> :: empty( ) const
  /*Post: The function returns true or false according to whether the List
  is empty or not.*/
{
  return count == 0;
}

template<class List_entry>
void List<List_entry> :: clear( )
  /*Post: All List entries have been removed; the List is empty.*/
{
  while (count > 0) {
  	List_entry x;
  	remove(count - 1, x);
 	count--;
  }
}


template <class List_entry>
Error_code List<List_entry> :: insert(int position, const List_entry &x)
  /* Post: If the List is not full and 0 > position > n, where n is the number of
  entries in the List, the function succeeds: Any entry formerly at position
  and all later entries have their position numbers increased by 1 and x is
  inserted at position of the List.
  Else: The function fails with a diagnostic error code. */
{
  if (position < 0 || position > count)
    return range_error;
  Node<List_entry> *new_node, *previous, *following;
  if (position > 0) {
    previous = set_position(position - 1);
    following = previous->next;
  }
  else following = head;
  new_node = new Node<List_entry>(x, following);
  if (new_node == NULL)
    return overflow;
  if (position == 0)
    head = new_node;
  else
    previous->next = new_node;
  count++;
  return success;
}

template <class List_entry>
void List<List_entry> :: traverse(void (*visit)(List_entry &))
  /* Post: The action specied by function (*visit) has been performed on every entry
     of the List, beginning at position 0and doing each in turn. */
{
  Node<List_entry> *q = head;
  for (int i = 0; i < count; i++) {
    (*visit)(q -> entry);
    q = q -> next;
  }
}

template <class List_entry>
List<List_entry> :: ~List( ) {
	clear( );
}

template <class List_entry>
List<List_entry> :: List(const List<List_entry> &original) {
	Node<List_entry> *new_copy ,*original_node;
	original_node = original.head;
        count = original.count;
	if (original_node == NULL) {
		head = NULL;
	} else {		//Duplicate the linked nodes.
		head = new_copy = new Node<List_entry>(original_node ->entry);
		while (original_node ->next != NULL){
			original_node = original_node ->next;
			new_copy ->next = new Node<List_entry>(original_node ->entry);
			new_copy = new_copy ->next ;
		}
	}

}

template <class List_entry>
void List<List_entry> :: operator = (const List<List_entry> &original) {
	Node<List_entry> *new_head, *new_copy, *original_node;
	original_node = original.head;
	if (original_node == NULL) {
		new_head =NULL;
	} else {		//Duplicate the linked nodes
		new_head = new Node<List_entry>(original_node ->entry);
		new_copy = new_head;
		while (original_node ->next != NULL){
			original_node = original_node ->next ;
			new_copy ->next = new Node<List_entry>(original_node ->entry);
			new_copy = new_copy ->next;
		}
	}
	clear( );
        count = original.count;
	head = new_head ;		//and replace them with new entries.
}

template <class List_entry>
Node<List_entry> *List<List_entry> :: set_position(int position) const
{
  Node<List_entry> *q = head;
  for (int i =0; i < position; i++ ) {
	q = q -> next;
  }
  return q;
}


