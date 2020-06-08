#include <iostream>
#include <vector>

using std::vector;

int getIndex(vector<int> weights,vector<int> values){
  int maxIndex=0;
  double max = 0.0;

  for(int i=0; i<weights.size(); i++)
  {
    if(weights[i]!=0 && (double) values[i]/weights[i]>max)
    {
      max = ((double)values[i])/weights[i];
      maxIndex = i;
    }
  }

  return maxIndex;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double a,value = 0.0;
  int maxIndex;
  
  for(int i =0 ; i<weights.size(); i++)
  {
    if(capacity == 0)
      break;
    maxIndex = getIndex(weights,values);
    a = std::min(capacity,weights[maxIndex]);
    value += a*(((double)values[maxIndex])/weights[maxIndex]);
    weights[maxIndex] -= a;
    capacity -= a;
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
  return 0;
}
