#include "key.h"

int Key::comparisons = 0;

int Key::the_key()const
{
   return key;
} //value of key method

Key::Key (int x)
{
   key = x;
} //constructor

bool operator ==(const Key &x, const Key &y)
{
  Key::comparisons++;
  return x.the_key()== y.the_key();
} //overloaded equivalence

bool operator !=(const Key &x, const Key &y)
{
  Key::comparisons++;
  return x.the_key()!= y.the_key();
} //overloaded not equal

bool operator >=(const Key &x, const Key &y)
{
  Key::comparisons++;
  return x.the_key()>= y.the_key();
}//overloaded GE

bool operator <=(const Key &x, const Key &y)
{
  Key::comparisons++;
  return x.the_key()<= y.the_key();
}//overloaded LE

bool operator >(const Key &x, const Key &y)
{
  Key::comparisons++;
  return x.the_key()> y.the_key();
} //overloaded greater than

bool operator <(const Key &x, const Key &y)
{
  Key::comparisons++;
  return x.the_key()< y.the_key();
} //overloaded less than

