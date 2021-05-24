
#ifndef KEY_H
#define KEY_H


class Key {
  int key;
public:
  static int comparisons;
  Key (int x = 0) ;
  int the_key()const;
};
bool operator ==(const Key &x,const Key &y);
bool operator >(const Key &x,const Key &y);
bool operator <(const Key &x,const Key &y);
bool operator >=(const Key &x,const Key &y);
bool operator <=(const Key &x,const Key &y);
bool operator !=(const Key &x,const Key &y);

#endif
