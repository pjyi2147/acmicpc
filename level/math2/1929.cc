// acmicpc number: 1929
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    bool* p = new bool[n+1];
    memset(p,1,sizeof(bool)*(n+1));

    p[1] = false;
    for (int i = 2; i*i <= n; i++)
    {
        if (p[i] == false) continue;
        for (int j = i*2; j <= n; j+=i) p[j] = false;
    }
    for (int i = m; i <= n; i++)
    {
        if (p[i])
        {
            cout << i << "\n";
        }
    }
}