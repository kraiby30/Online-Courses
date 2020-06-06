#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

/* GCD can easily be calculated by eucids formula which is 
that GCD(a,b) = GCD(b,a%b)
*/
int gcd_fast(int a, int b)
{
  if(b == 0)
    return a;
  else
  {
    return gcd_fast(b,a%b);
  }
  
}
//LCM(a,b) = (a*b)/GCD(a,b)
long long lcm_fast(int a, int b){
  return (((long long)a)*b)/gcd_fast(a,b);
}



int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
