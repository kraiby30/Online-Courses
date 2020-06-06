#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

/*
In Fibonacci series, the last digit starts repeating after 60
So Even if a large number is given, the remainder when divided
by 60 is found out and last digit is found accordingly
*/
int fibonacci_last_digit_fast(int n){
    if(n<2)
        return n;
    else
    {
        std::vector<int> fiboLastDigit(60); 
        fiboLastDigit[1]=1;
        if(n>59)
        {
            n=n%60;
        }
        for(int i =2;i<=n; i++)
        {
            fiboLastDigit[i] = (fiboLastDigit[i-1] + fiboLastDigit[i-2]) % 10;
        }
        return fiboLastDigit[n];

    }
    
}

int main() {
    int n;
    std::cin >> n;
    //int c = get_fibonacci_last_digit_naive(n);
    int c = fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
