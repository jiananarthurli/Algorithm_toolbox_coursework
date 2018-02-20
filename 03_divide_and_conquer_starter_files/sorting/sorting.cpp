#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using namespace std;

struct index{
  int j;
  int k;
};

index partition3(vector<int> & a, int l, int r) {
  
  int x = a[l];
  index ind = { l, l };
  
  for (int i = l + 1; i <= r; ++i) {
    if (a[i] == x) {
      ++ind.k;
      swap(a[i], a[ind.k]);      
    } else if (a[i] < x) {
      ++ind.k;
      swap(a[i], a[ind.k]);     
      ++ind.j;
      swap(a[ind.k], a[ind.j]);
    }
  }
  swap(a[l], a[ind.k]);
  //  std::cout << x << " " << ind.j << " " << ind.k << std::endl;
  return ind;
}

void randomized_quick_sort(vector<int> & a, int l, int r) {
  
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  index ind = partition3(a, l, r);
  
  //  for (size_t i = 0; i < a.size(); ++i) {
  //    std::cout << a[i] << ' ';
  //  }
  //  std::cout << std::endl;
  

  randomized_quick_sort(a, l, ind.j);
  randomized_quick_sort(a, ind.k + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << std::endl;

  return 0;
}
