#include <iostream>

int get_change(int m) {
  
  const int ten = 10;
  const int five = 5;

  return (m / ten) + (m % ten) / five + (m % ten) % five;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
