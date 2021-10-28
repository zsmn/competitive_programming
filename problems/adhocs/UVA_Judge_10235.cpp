#include <bits/stdc++.h>
using namespace std;

bool prime(int n)
{
    if(n <= 1) return 0;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int rev(int n)
{
    int sum = 0;
    while(n){
        sum = sum * 10 + (n % 10);
        n /= 10;
    }

    return sum;
}

int main(void)
{
    int N;

    while(cin >> N){
        int newN = rev(N);
        if(!prime(N))
            cout << N << " is not prime." << endl;
        else if(prime(N) && prime(newN) && N != newN)
            cout << N << " is emirp." << endl;
        else
            cout << N << " is prime." << endl;
    }

    return 0;
}