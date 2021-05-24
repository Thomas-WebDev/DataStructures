/****************************************************
 * File Name: deque.h
 * Author: Kevin Thomas Kehoe
 * Course: CSCI132
 * Assignment: Homework 3
 * Modification Date: September 21, 2016
 * Purpose: specification of Deque class
 *****************************************************/

#include "queue.h"

class Deque: private Queue {
 public:
  //append an item to the front of the deque
  Error_code append_front(const Queue_entry &item);
  //append an item to the rear of the deque    
  Error_code append_rear(const Queue_entry &item);       
  //delete an item from the front of the deque
  Error_code serve_front();
  //delete an item from the rear of the deque
  Error_code serve_rear();   
  //retrieve an item from the front of the deque
  Error_code retrieve_front(Queue_entry &item) const;
  //retrieve an item from the rear of the deque
  Error_code retrieve_rear(Queue_entry &item) const;
  //checks if deque is empty
  bool empty() const;
};
