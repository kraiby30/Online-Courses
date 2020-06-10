#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;


/*
The maximum value of array a is multiplied with max value in
array b and the values are set to the value lesser than the 
minimum value already present in the array. Greedy algorithm
is used.
*/
long long max_dot_product(vector<int> a, vector<int> b) {
  int maxIndexA,maxIndexB;
  int minIndexA,minIndexB;
  minIndexA = std::min_element(a.begin(),a.end())-a.begin();
  minIndexB = std::min_element(b.begin(),b.end())-b.begin(); 
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    maxIndexA = std::max_element(a.begin(),a.end())-a.begin();
    maxIndexB = std::max_element(b.begin(),b.end())-b.begin();
    result += ((long long) a[maxIndexA]) * b[maxIndexB];
    a[maxIndexA]=a[minIndexA]-1;
    b[maxIndexB]=b[minIndexB]-1; 
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
