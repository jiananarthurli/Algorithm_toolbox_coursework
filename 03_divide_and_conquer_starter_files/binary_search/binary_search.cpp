#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
using std::sort;

int binary_search(const vector<int> &sorted, int x) {
  
  int left = 0;
  int right = sorted.size() - 1;
  double compare_i = 0.0;
  int position = -1;

  //  std::cout << "sorted. " << std::endl;

  while(left != right) {
    compare_i = (double)(left + right)/2;
    if( x == sorted[(int)floor(compare_i)] ) {
      position = (int)floor(compare_i);
      break;
    } else if( x > sorted[(int)floor(compare_i)] ) {
      left = (int)ceil(compare_i);
    } else {
      right = (int)floor(compare_i);
    }
  }

  if(x == sorted[right]){
    position = right;
  }
  
  return position;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }

  vector<int> sorted = a;
  sort(sorted.begin(), sorted.end());
  
  for (int i = 0; i < m; ++i) {
    std::cout << binary_search(sorted, b[i]) << ' ';
  }
  std::cout << std::endl;

  return 0;
}
