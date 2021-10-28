#include <bits/stdc++.h>
using namespace std;

unsigned long long int factorial(int n);

int main(void)
{
    int T;
    cin >> T;
    string a;

    for(int i = 1; i <= T; i++){
        cin >> a;
        int arr[27] = {0};
        unsigned long long int sum = 1;
        int len = a.length();

        for(int j = 0; j < len; j++)
            arr[a[j] - 'A']++;

        for(int j = 0; j < 27; j++)
            if(arr[j] != 0)
                sum *= factorial(arr[j]);

        cout << "Data set " << i << ": " << factorial(len) / sum << endl;
    }
}

unsigned long long int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}