#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd(int a, int b) {
  int remainder = 1;
  int temp;
  if (b > a) {
    temp = a;
    a = b;
    b = temp;
  }
  while(remainder != 0) {
    remainder = a % b;
    a = b;
    b = remainder;
  }

  return a;
}
  

int main() {
  int a, b;
  std::cin >> a >> b;
  //  std::cout << gcd_naive(a, b) << " " << gcd(a, b) << std::endl;
  std::cout << gcd(a,b) << std::endl;
  return 0;
}
