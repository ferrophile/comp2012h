//IntStack.h
//Simple integer stack

#include <iostream>
#include <assert.h>
using namespace std;

template <typename T>
class IntStack 
{
private:
  enum { ssize = 100 };
  T stack[ssize];
  int top;
public:
  IntStack() : top(0) {}
  void push(T i) 
  {
    assert(top<ssize);
    stack[top++] = i;
  }
  T pop() 
  {
    assert(top > 0);
    return stack[--top];
  }
};


