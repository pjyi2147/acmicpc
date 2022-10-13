// acmicpc number: 24416
#include <bits/stdc++.h>
using namespace std;

int n;

int64_t FIB[100];

int64_t fib(int n)
{
    FIB[1] = 1;
    FIB[2] = 1;
    for (int i = 3; i <= n; i++) {
        FIB[i] = FIB[i - 1] + FIB[i - 2];
    }
    return FIB[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cout << fib(n) << " " << n - 2 << endl;
}