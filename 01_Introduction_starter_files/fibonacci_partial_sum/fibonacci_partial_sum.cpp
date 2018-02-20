#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
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

int fibonacci_partial_sum(long long int from, long long int to) {
  int period = 60;
  int from_remainder = 0;
  int to_remainder = 0;
  int sum = 0;
  
  if(from > period)
    from_remainder = from % period;
  else
    from_remainder = from;
  
  if(to > period)
    to_remainder = to % period;
  else
    to_remainder = to;
  
  
  for(long long int j = from_remainder; j <= to_remainder; ++j) {
    sum = (sum +  get_fibonacci_last_digit_fast(j)) % 10;
    //    cout << "the sum is " << sum << endl;
  }
  return sum;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << fibonacci_partial_sum(from, to) << '\n';
}
