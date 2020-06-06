#include <iostream>
#include <vector>
#include <math.h>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

/* sum of fibonacci squares, fiboSumSquares(x) is 
the difference between fibonacci(x+1)^2 and fibonacci(x)^2
*/
int fibonacci_sum_squares_fast(long long n) 
{
    n = n%60;
    long long N = (n+1)%60;
    std::vector<int> fiboLastDigit(60);
    fiboLastDigit[1]=1;
    for(int i =2;i<=max(n,N); i++)
    {
        fiboLastDigit[i] = (fiboLastDigit[i-1] + fiboLastDigit[i-2]) % 10;
    }
    if(n%2 == 0)
    {
        if((fiboLastDigit[N]*fiboLastDigit[N]-fiboLastDigit[n]*fiboLastDigit[n])%10-1<0)
            return (fiboLastDigit[N]*fiboLastDigit[N]-fiboLastDigit[n]*fiboLastDigit[n]-1)%10+10;
        else
            return (fiboLastDigit[N]*fiboLastDigit[N]-fiboLastDigit[n]*fiboLastDigit[n]-1)%10 ;     
    }
    else
    {
        if((fiboLastDigit[N]*fiboLastDigit[N]-fiboLastDigit[n]*fiboLastDigit[n])%10+1<0)
            return (fiboLastDigit[N]*fiboLastDigit[N]-fiboLastDigit[n]*fiboLastDigit[n]+1)%10+10;
        else
            return (fiboLastDigit[N]*fiboLastDigit[N]-fiboLastDigit[n]*fiboLastDigit[n]+1)%10; 
    }

    
}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
