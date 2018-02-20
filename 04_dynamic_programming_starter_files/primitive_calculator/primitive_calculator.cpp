#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n) {
  vector<int> sequence;
  vector<int> operations(n+1);
  operations[0] = 0;
  operations[1] = 0;
  for(int i = 2; i <= n; ++i) {
    if(i % 3 == 0 && i % 2 == 0) {
      operations[i] = min( min(operations[i / 3] + 1, operations[i / 2] + 1), operations[i - 1] + 1);
    } else if(i % 2 == 0) {
      operations[i] = min(operations[i / 2] + 1, operations[i - 1] + 1);
    } else if(i % 3 == 0) {
      operations[i] = min(operations[i / 3] + 1, operations[i - 1] + 1);
    } else {
      operations[i] = operations[i - 1] + 1;
    }
  }

  int number = n;
  sequence.push_back(number);
  //  cout << "total iterations: " << operations[number] << endl;

  for(int i = 0; i < operations[n]; ++i) {
    
    if(number % 3 == 0 && number % 2 == 0) {
    
      if(operations[number / 3] < operations[number - 1]) {
	number /= 3;
	sequence.push_back(number);
      } else if(operations[number / 2] < operations[number - 1]) {
	number /= 2;
	sequence.push_back(number);
      } else {
	number -= 1;
	sequence.push_back(number);
      }
      
    } else if(number % 2 == 0) {
      if(operations[number / 2] < operations[number - 1]) {
	number /= 2;
	sequence.push_back(number);
      } else {
	number -= 1;
	sequence.push_back(number);
      }
      
    } else if(number % 3 == 0) {
      if(operations[number / 3] < operations[number - 1]) {
	number /= 3;
	sequence.push_back(number);
      } else {
	number -= 1;
	sequence.push_back(number);
      }
      
    } else {
      number -= 1;
      sequence.push_back(number);
      //      cout << number << endl;
    }
    //    cout << i << endl;
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  //  int sequence = optimal_sequence(n);
  vector<int> sequence = optimal_sequence(n);
  //  cout << sequence << endl;
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
