//IntStackTest.cpp
#include "IntStack.h"
#include <string>

template <typename T>
T fibonacci(T n) 
{
  const int sz = 100;
  assert(n < sz);
  static T f[sz]; // Initialized to zero
  f[0] = f[1] = 1;
  // Scan for unfilled array elements:
  int i;
  for(i = 0; i < sz; i++)
    if(f[i] == 0) break;
  while(i <= n) {
    f[i] = f[i-1] + f[i-2];
    i++;
  }
  return f[n];
}

int main() {
  IntStack<int> is;
  // Add some Fibonacci numbers, for interest:
  for(int i = 0; i < 20; i++)
    is.push(fibonacci(i));
  // Pop & print them:
  for(int k = 0; k < 20; k++)
    cout << is.pop() << endl;

  IntStack<std::string> is2;
  // Add some Fibonacci numbers, for interest:
  for(int i = 0; i < 20; i++)
    is2.push(to_string(fibonacci(i)));
  // Pop & print them:
  for(int k = 0; k < 20; k++)
    cout << is2.pop() << endl;

  return 0;
}