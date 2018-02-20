#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

int get_majority_element(vector<int> & a, int left, int right) {

  if (left == right) return a[left];

  int m = (left + right)/2;
  int leftmax = 0;
  int rightmax = 0;
  int lcounter = 0;
  int rcounter = 0;
  
  leftmax = get_majority_element(a, left, m);
  rightmax = get_majority_element(a, m+1, right);
  
  for(int i = left; i <= right; ++i) {
    if(a[i] == leftmax)
      ++lcounter;
    else if(a[i] == rightmax)
      ++rcounter;
  }
  if( lcounter > ceil((double)(right - left)/2) )
    return leftmax;
  if( rcounter > ceil((double)(right - left)/2) )
    return rightmax;
  
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << ( get_majority_element(a, 0, a.size()-1) !=0 ) << '\n';
}
