/****************************************************
 * File Name: deque.cc
 * Author: Kevin Thomas Kehoe
 * Course: CSCI132
 * Assignment: Homework 3
 * Modification Date: September 21, 2016
 * Purpose:  Implementation of Deque class
 *****************************************************/

#include "deque.h"

//append an item to the front of the deque
Error_code Deque::append_front(const Queue_entry &item)
  /*
Post: item is added to the front of the Queue. If the Queue is full
return an Error_code of overflow and leave the Queue unchanged.
  */
{
  if (count >= maxqueue) 
    return overflow;
  count++;
  front = ((front - 1) < 0) ? (maxqueue -1) : 0;
  entry[front] = item;
  return success;
} //appnd

//append an item to the rear of the deque    
Error_code Deque::append_rear(const Queue_entry &item){
  /*
Post: item is added to the rear of the Queue. If the Queue is full
return an Error_code of overflow and leave the Queue unchanged.
  */
  count++;
  append(item);
  return success;
}
      
//delete an item from the front of the deque
Error_code Deque::serve_front()
  /*
Post: The front of the Queue is removed. If the Queue
is empty return an Error_code of underflow.
  */
{
  count--;
  serve();
  return success;
} //serve

//delete an item from the rear of the deque
Error_code Deque::serve_rear()
  /*
Post: The rear of the Queue is removed. If the Queue
is empty return an Error_code of underflow.
  */
{
  if (count <= 0) 
    return underflow;
  count--;
  if((rear - 1) == -1)
    rear = maxqueue;
  else
    rear = rear - 1;
  return success;
} //serve

//retrieve an item from the front of the deque
Error_code Deque::retrieve_front(Queue_entry &item) const
  /*
Post: The front of the Queue retrieved to the output
      parameter item. If the Queue is empty return an Error_code of underflow.
  */
{
  if (count <= 0) 
    return underflow;
  else {
    retrieve(item);
    return success;
  }
}

//retrieve an item from the rear of the deque
Error_code Deque::retrieve_rear(Queue_entry &item) const
  /*
Post: The rear of the Queue retrieved to the output
      parameter item. If the Queue is empty return an Error_code of underflow.
  */
{
  if (count <= 0) 
    return underflow;
  item = entry[rear];
  return success;
}

bool Deque::empty() const{
  /*
Post: Return true if the Queue is empty, otherwise return false.
  */
  return count == 0;
} //empty
