#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using std::vector;
using namespace std;

struct npair {
  int n;
  int label;
};

bool npair_compare(const struct npair & lhs, const struct npair & rhs ) {
  if (lhs.n < rhs.n) {
    return true;
  } else if (lhs.n > rhs.n) {
    return false;
  } else if (lhs.label <= rhs.label) {
    return true;
  } else {
    return false;
  }
}

int binary_search(const vector<struct npair> & sorted, int x) {
  
  int left = 0;
  int right = sorted.size() - 1;
  double compare_i = 0.0;
  int position = -1;

  while(left != right) {
    compare_i = (double)(left + right)/2;
    if( x == sorted[(int)floor(compare_i)].n ) {
      position = (int)floor(compare_i);
      break;
    } else if( x > sorted[(int)floor(compare_i)].n ) {
      left = (int)ceil(compare_i);
    } else {
      right = (int)floor(compare_i);
    }
  }

  if(x == sorted[right].n){
    position = right;
  }
  
  return position;
}

vector<long long int> fast_count_segments(vector<long long int> starts, vector<long long int> ends, vector<long long int> points) {
  
  vector<long long int> cnt(points.size());
  vector<struct npair> points_count(points.size());

  /* 
  vector<struct npair> npair_vector;
  for(auto i : starts) {
    npair_vector.push_back({i, -1});
  }
  for(auto i : ends) {
    npair_vector.push_back({i, 1});
  }
  for(auto i : points) {
    npair_vector.push_back({i, 0});
  }
  */

  
  vector<struct npair> npair_vector(points.size() + starts.size() + ends.size());
  int j = 0;
  for(int i = 0; i < points.size(); ++i) {
    npair_vector[j].n = points[i];
    npair_vector[j].label = 0;
    ++j;
  }
  for(int i = 0; i < starts.size(); ++i) {
    npair_vector[j].n = starts[i];
    npair_vector[j].label = -1;
    ++j;
  }
  for(int i = 0; i < ends.size(); ++i) {
    npair_vector[j].n = ends[i];
    npair_vector[j].label = 1;
    ++j;
  }
  
  sort(npair_vector.begin(), npair_vector.end(), npair_compare);

  //    for(auto i : npair_vector) {
  //      cout << i.n << " " << i.label << endl;
  //    }
  
  int label_counter = 0;
  int index = 0;
  for(int i = 0; i < npair_vector.size(); ++i) {
    if(npair_vector[i].label == 0) {
      points_count[index].n = npair_vector[i].n;
      points_count[index].label = label_counter;
      ++index;
    } else {
      label_counter += npair_vector[i].label;
    }
  }

  
  for(int i = 0; i < points.size(); ++i) {
    for(auto iter = points_count.begin(); iter != points_count.end(); ++iter) {
      if (points[i] == iter->n) {
	cnt[i] = abs(iter->label);
	break;
      }
    }
    //    index = binary_search(points_count, points[i]);
    //    cnt[i] = abs(points_count[index].label);
  }
    
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  
  //  while(1) {
  //    srand(time(NULL));
    
  int n, m;
  std::cin >> n >> m;
  //      n = rand() % 50000 + 1;
  //      m = rand() % 50000 + 1;
  vector<long long int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
    //    starts[i] = rand() % 200000000 - 100000000;
    //    while(ends[i] < starts[i])
    //      ends[i] = rand() % 200000000 - 100000000;
  }
  vector<long long int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
    //    points[i] = rand() % 200000000 - 100000000;
  }
  //use fast_count_segments
  vector<long long int> cnt = fast_count_segments(starts, ends, points);
  
  //  vector<int> cnt2 = naive_count_segments(starts, ends, points);
  //  if(cnt != cnt2)
  //    cout << "Incorrect " << endl;
  //  else cout << "Correct" << endl;
  
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
  
  //  cout << endl;
  //  for (size_t i = 0; i < cnt.size(); i++) {
  //    std::cout << cnt2[i] << ' ';
  //  }
  //  cout << endl;
  //  for (size_t i = 0; i < starts.size(); i++) {
  //    std::cout << starts[i] << ' ' << ends[i] << endl;
  //  }
  //  for (size_t i = 0; i < points.size(); i++) {
  //    std::cout << points[i] << ' ';
  //  }
  //  cout << endl;
  
}
