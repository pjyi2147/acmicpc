// acmicpc number: 2004
#include <bits/stdc++.h>
using namespace std;

int n, m;
int get2num(int n)
{
    int ret = 0;
    if (n % 2 == 1) n--;
    while (n > 1)
    {
        n /= 2;
        ret += n;
        if (n % 2 == 1) n--;
    }
    return ret;
}

int get5num(int n)
{
    int ret = 0;
    if (n % 5 > 0) n -= (n % 5);
    while (n > 1)
    {
        n /= 5;
        ret += n;
        if (n % 5 > 0) n -= (n % 5);
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    cout << min(get2num(n)-get2num(m)-get2num(n-m), 
                get5num(n)-get5num(m)-get5num(n-m));
}