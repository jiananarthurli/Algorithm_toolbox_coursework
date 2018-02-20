#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool descend_cmp(string lhs, string rhs) {return ((lhs + rhs) > (rhs + lhs));}

string largest_number(vector<string> a) {

  sort(a.begin(), a.end(), descend_cmp);
  
  std::stringstream ret;
  for (size_t i = 0; i < a.size() ; i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a) << std::endl;
}
