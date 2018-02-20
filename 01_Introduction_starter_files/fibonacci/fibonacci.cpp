#include <iostream>
#include <cassert>
//#include <ctime>

using namespace std;

int fibonacci_naive(int n) {
  if (n <= 1)
    return n;
  
  return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
  int F_n = 1; //F(n)
  int F_n_1 = 1; //F(n-1)
  int temp = 0;
  for(int i = 1; i <= n; ++i ) {
    if(i > 2) {
      temp = F_n;
      F_n += F_n_1;
      F_n_1 = temp;
    }
  }
  if(n == 0)
    return 0;
  else
    return F_n;
}

void test_solution() {
  assert(fibonacci_fast(3) == 2);
  assert(fibonacci_fast(10) == 55);
  for (int n = 0; n < 20; ++n)
    assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
  int n = 0;
  cin >> n;
  
  //  int tic = clock();
  //  int fib1 = fibonacci_naive(n);
  // int time1 = clock() - tic;
  //  tic = clock();
  //  int fib2 = fibonacci_fast(n);
  //  int time2 = clock() - tic;
  
  cout << fibonacci_fast(n) << endl;
  return 0;
}
