#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

/*
In fibonacci series, sum of fibonacci numer from a to b,
Fibo_Partial_Sum(a,b) = Fibo(b+2) - Fibo(a+1); So the 
last digit of partial sum is found accordingly;
*/
int fibonacci_partial_sum_fast(long long from, long long to) {
    long long n = from + 1;
    long long N = to + 2;
    std::vector<int> fiboLastDigit(60); 
    fiboLastDigit[1]=1;
    if(N>59)
    {
        N=N%60;
    }
    if(n>59)
    {
        n=n%60;
    }
    for(int i =2;i<=N && i<=n; i++)
    {
        fiboLastDigit[i] = (fiboLastDigit[i-1] + fiboLastDigit[i-2]) % 10;
    }
    //std::cout<<fiboLastDigit[N]<<" "<<fiboLastDigit[n]<<std::endl;
    if(fiboLastDigit[N]-fiboLastDigit[n]<0)
    {
        return fiboLastDigit[N]-fiboLastDigit[n]+10;
    }
    else
        return fiboLastDigit[N]-fiboLastDigit[n];
    
    
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << fibonacci_partial_sum_fast(from, to) << '\n';
}
