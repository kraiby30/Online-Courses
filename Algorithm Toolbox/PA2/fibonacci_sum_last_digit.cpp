#include <iostream>
#include <vector>


int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

/*
In fibonacci series, sum of first n fibonacci numbers is 
equal to fibonacci(n+2)-1; So the last digit of fibonacci(N=n+2)
is found and accordingly the last digit of sum of first n 
fibonacci numbers is obtained;
*/
int fibonacci_sum_fast(long long n) {
    long long N = n+2;
    if(n<2)
        return n;
    else
    {
        std::vector<int> fiboLastDigit(60); 
        fiboLastDigit[1]=1;
        if(N>59)
        {
            N=N%60;
        }
        for(int i =2;i<=N; i++)
        {
            fiboLastDigit[i] = (fiboLastDigit[i-1] + fiboLastDigit[i-2]) % 10;
        }
    
        if(fiboLastDigit[N]==0)
        {
            return 9; // if last digit is 0, fiboLastDigit[N]-1 = -1
        }
        else
            return fiboLastDigit[N]-1;
    }
    
}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
