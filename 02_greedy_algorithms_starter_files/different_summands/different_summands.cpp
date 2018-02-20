#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {

  vector<int> summands;
  
  for(int element = 1; 2 * element < n; ++element) {
    summands.push_back(element);
    n -= element;
  }

  summands.push_back(n);
  
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
  std::cout << std::endl;
}
