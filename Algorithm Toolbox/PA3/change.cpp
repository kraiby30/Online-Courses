#include <iostream>

int get_change(int m) {
  int n = 0;
  int coins[] = {10,5,1};
  for(int i = 0; i<3; i++)
  {
    n = n + m/coins[i];
    m = m % coins[i];
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
