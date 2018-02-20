#include <iostream>

using namespace std;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int get_fibonacci_last_digit_fast(long long int n) {
  static int F_n = 1; //F(n)
  static int F_n_1 = 1; //F(n-1)
  int temp = 0;
  for(static int i = 1; i <= n; ++i ) {
    if(i > 2) {
      temp = F_n % 10;
      F_n = (F_n + F_n_1) % 10;
      F_n_1 = temp;
      //      cout << i << " " << F_n  << endl;
    }
  }
  if(n == 0)
    return 0;
  else
    return F_n;
}

int fibonacci_sum(long long int n) {
  int period = 60;
  int remainder = 0;
  int sum = 0;
  
  if(n > period)
    remainder = n % period;
  else
    remainder = n;
  
  for(long long int j = 0; j <= remainder; ++j) {
    sum = (sum +  get_fibonacci_last_digit_fast(j)) % 10;
    //    cout << "the sum is " << sum << endl;
  }
  return sum;
}

int main() {
    long long n = 0;
    std::cin >> n;
    //    std::cout << fibonacci_sum_naive(n)  << " " << fibonacci_sum(n) << std::endl;
    std::cout << fibonacci_sum(n) << std::endl;
}
