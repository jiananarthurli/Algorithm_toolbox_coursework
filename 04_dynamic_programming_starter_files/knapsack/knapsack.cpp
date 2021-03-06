#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> & w) {

  int w_size = w.size();
  vector< vector <int> > results(W + 1, vector<int>(w_size + 1) );
  int value = 0;
  int max_result = 0;
  
  for(int i = 0; i <= W; ++i) {
    results[i][0] = 0;
  }
  for(int j = 0; j <= w_size; ++j) {
    results[0][j] = 0;
  }
  
  for(int j = 1; j <= w_size; ++j) {
    for(int i = 1; i <= W; ++i) {
      results[i][j] = results[i][j - 1];
      if(w[j - 1] <= i) {
	value = results[i - w[j - 1]][j - 1] + w[j - 1];
	//	cout << i << endl;
	//	value = i;
	if(results[i][j] < value) {
	  results[i][j] = value;
	}
      }
    }
  }

  max_result = results[W][w_size];
  
  //  for(int j = 0; j <= W; ++j) {
  //    for(int i = 0; i <= w_size; ++i) {
  //      cout << results[j][i] << " ";
  //    }
  //    cout << endl;
  //  }
  
  return max_result;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';

}
