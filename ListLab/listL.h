#include <cstdlib>

using namespace std;

#ifndef LISTL_H
#define LISTL_H
enum Error_code {success, fail, range_error, underflow, overflow};

template <class Node_entry>
struct Node {
	Node_entry entry;
	Node<Node_entry> *next;
	Node();
	Node(Node_entry, Node<Node_entry> *link = NULL);
};

template<class List_entry>
class List {
 public:
  // methods of the List ADT
  List( );
  int size( ) const;
  bool full( ) const;
  bool empty( ) const;
  void clear( );
  void traverse(void (*visit)(List_entry &));
  Error_code retrieve(int position, List_entry &x) const;
  Error_code replace(int position, const List_entry &x);
  Error_code remove(int position, List_entry &x);
  Error_code insert(int position, const List_entry &x);
  ~List( );
  List(const List<List_entry> &original);
  void operator = (const List<List_entry> &original);
 protected:
  // data members for a contiguous list implementation
  int count;
  Node<List_entry> *head;
  Node<List_entry> *set_position(int position) const;
};
#endif
