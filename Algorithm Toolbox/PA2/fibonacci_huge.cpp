#include <iostream>
#include <vector>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long pisanoPeriod(long long m)
{
    long long previous = 0, current = 1;
    long m2 = m*m;

    for(int i =0; i<m2; i++)
    {   
        long long temp_previous = previous;
        previous = current;
        current =  (temp_previous+current)%m;

        if (previous==0 && current==1)
        return i+1;

    }
}

/*
In this funtion we find fib(n)mod(m). This is a periodic function
that depends on m and the period is given by pisanoPeriod. So,insted 
of calculating fib(n)mod(m), calculating fib(n mod pisanoPeriod)mod(m)
is sufficient. Fibomod stores the pisano pattern instead of storing
the fibonacci numbers.
*/
long long get_fibonacci_huge_fast(long long n, long long m) {

    int pisano_period = pisanoPeriod(m);
    n = n % pisano_period;
    if(n<2)
        return n%m;
    else
    {
        std::vector<long long> fibomod(n+1);
        fibomod[1]=1;
        for(int i=2; i<=n; i++)
        {
            fibomod[i] = (fibomod[i-1] + fibomod[i-2])%m;
        }
        return fibomod[n];
    }
}



int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
