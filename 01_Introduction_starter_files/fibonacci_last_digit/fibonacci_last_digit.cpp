#include <iostream>

using namespace std;

/*
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
*/

int get_fibonacci_last_digit_fast(int n) {
  int F_n = 1; //F(n)
  int F_n_1 = 1; //F(n-1)
  int temp = 0;
  for(int i = 1; i <= n; ++i ) {
    if(i > 2) {
      temp = F_n % 10;
      F_n = (F_n + F_n_1) % 10;
      F_n_1 = temp;
    }
  }
  if(n == 0)
    return 0;
  else
    return F_n;
}

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int main() {
    int n;
    cin >> n;
    //    int c = get_fibonacci_last_digit_naive(n);
    // cout << fibonacci_fast(n) << " " << get_fibonacci_last_digit_fast(n) << " " << c << endl;
    cout << get_fibonacci_last_digit_fast(n) << endl;
}
