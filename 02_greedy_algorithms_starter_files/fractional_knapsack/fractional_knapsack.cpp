#include <iostream>
#include <vector>
#include <cstdio>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  double max_value = 0.0;
  int max_i = 0;
  double value_per_weight = 0.0;
  double max_value_per_weight = 0.0;

  while(weights.size() != 0 && capacity != 0) {
    max_value_per_weight = 0.0;
    max_i = 0;
    for(int i = 0; i < weights.size(); ++i) {
      value_per_weight = (double)values[i] / (double)weights[i];
      if(value_per_weight > max_value_per_weight) {
	max_value_per_weight = value_per_weight;
	max_i = i;
      }
    }

    if(weights[max_i] < capacity) {
      value += values[max_i];
      capacity -= weights[max_i];
    }
    else {
      value += capacity * max_value_per_weight;
      capacity = 0.0;
    }

    weights.erase(weights.begin() + max_i);
    values.erase(values.begin() + max_i);

  }
      
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  //  printf("%.5f\n",optimal_value);
  return 0;
}
