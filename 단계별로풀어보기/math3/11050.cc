// acmicpc number: 11050
#include <bits/stdc++.h>
using namespace std;

int a, b;
int f[100];

int fac(int a)
{
    if (a == 0) return 1;

    int& ret = f[a];
    if (ret != 0) return ret;
    return ret = a * fac(a - 1);
}

int main()
{
    cin >> a >> b;
    cout << fac(a) / fac(b) / fac(a - b);
}