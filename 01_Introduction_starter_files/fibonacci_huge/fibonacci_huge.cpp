#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
  
  if (n <= 1)
    return n;
  
  long long previous = 0;
  long long current  = 1;
  
  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
  }
  
  return current % m;
}

long long int fibonacci_huge(long long int n, long long int m) {

  if (n <= 1)
    return n;
  
  if (m == 1)
    return 0;
  
  int F_r = 1; //F(n) remainder
  int F_r_pr = 0; //F(n-1) remainder
  int temp = 0;
  int period = 0;
  int remainder = 0;
  
  for(int i = 2; i <= n; ++i ) {
    temp = F_r;
    F_r = (F_r +  F_r_pr) % m;
    F_r_pr = temp;
    
    if(F_r == 1 && F_r_pr == 0) {
      period = i - 1;
      //      std::cout << "period is " << period << std::endl;
      break;
    }
  }
  
  if(period != 0)
    remainder = n % period;
  else
    remainder = n;
    
  //  std::cout << "remainder is " << remainder << std::endl;
  
  F_r = 1; //F(n) remainder
  F_r_pr = 0; //F(n-1) remainder
  temp = 0;
  
  for(int i = 2; i <= remainder; ++i) {
    
    temp = F_r;
    F_r = (F_r +  F_r_pr) % m;
    F_r_pr = temp;
    
  }
  
  if(remainder == 0)
    return 0;
  else
    return F_r;
}

//long long int fibonacci_huge(long long int n, long long int m) {

//  if(n <= 1)
//  return n;
  
// long long int fib_r = -1;
//long long int fib_r_pr = -1;
//long long int temp = -1;
//int period = 0;
//int remainder = 0;
  
//  for(int i = 2; i <= n; ++i) {
//    temp = fib_r;
//  fib_r = fibonacci_fast(i) % m;
//  fib_r_pr = temp;
//  //    std::cout << fib_r << std::endl;
//  if(fib_r == 1 && fib_r_pr == 0) {
//    period = i - 1;
//    //      std::cout << "period " << period << std::endl;
//    break;
//  }
//}
// remainder = n % period;
// return fibonacci_fast(remainder) % m;
//}

int main() {
  long long n, m;
  std::cin >> n >> m;
  //  std::cout << get_fibonacci_huge_naive(n, m) << " " << fibonacci_huge(n, m)  <<'\n';
  std::cout << fibonacci_huge(n, m) << std::endl;
}
