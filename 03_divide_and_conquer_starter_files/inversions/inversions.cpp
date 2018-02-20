#include <iostream>
#include <vector>

using std::vector;
using namespace std;

vector<int> get_number_of_inversions(vector<int> & a, size_t left, size_t right) {
  cout << "call " << endl;
  
  size_t m = (right + left) / 2;
  vector<int> result = {0}; // first element is the number of inversions
  
  if (right == left) {
    result.push_back(a[right]);
    //    cout << "left: " << left << " right: " << right << endl;
    return result;
  }

  //    cout << "left " << left << " m " << m << " right " << right << endl;
  vector<int> result_l = get_number_of_inversions(a, left, m);
  vector<int> result_r = get_number_of_inversions(a, m+1, right);
  result[0] = result_l[0] + result_r[0];

  //  for(int i : result_l) cout << i << " ";
  //cout << "; ";
  //for(int i : result_r) cout << i << " ";
  //cout << endl;
  
  int j = 1;
  int k = 1;

  //  for( int c = 1; c <= result_l.size(); ++c ) {
  //  for( int d = 1; d <= result_r.size(); ++d ) {
  //    if(result_l[c] > result_r[d])
	//	cout << c << d << endl;
	//++result[0];
  //  }
  // }
  
  for(int i = 1; i <= (result_l.size()) + (result_r.size()); ++i) {
    if(result_l[j] > result_r[k] &&
       j != result_l.size() &&
       k != result_r.size() ) {
      result.push_back(result_l[k]);
      //      ++result[0];
      //      cout << result_l[j] << " " << j << " " << result_r[k] << " " << k << " " << i << endl; 
      ++k;
    }
    else if (j == result_l.size()) {
      result.push_back(result_l[k]);
      ++k;
    } else if (k == result_r.size()) {
      result.push_back(result_r[j]);
      ++j;
    } 
  }
  
  for(int i : result) cout << i << " ";
  cout << endl;
  
  return result;
  
}
  
int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
 
  std::cout << get_number_of_inversions(a, 0, n - 1)[0] << '\n';
}
