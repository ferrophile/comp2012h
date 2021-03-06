//FibonacciTemplate.cpp
#include <iostream>
#include <assert.h>
using namespace std;

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

int main()
{
	int i;
	for (i=0;i<20;i++)
		cout << i << ": " << fibonacci(i) << endl;

	return 0;
}

