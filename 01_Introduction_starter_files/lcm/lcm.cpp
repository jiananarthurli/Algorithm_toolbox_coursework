#include <iostream>

using namespace std;

int gcd(int, int);

long long int lcm(int, int);

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}

long long int lcm(int a, int b) {
  int gcd_ab = gcd(a, b);
  //  std::cout << gcd_ab << " " << a/gcd_ab << " " << b/gcd_ab << endl;
  return (long long)(a/gcd_ab)*(long long)(b/gcd_ab)*gcd_ab;
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
