// acmicpc number: 2581
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

    int sum = 0, min = 0;
    bool no_prime = true;
    for (int i = m; i <= n; i++)
    {
        if (p[i])
        {
            no_prime = false;
            sum += i; 
            if (min == 0) min = i;
        }
    }
    if (no_prime) cout << -1 << "\n";
    else cout << sum << "\n" << min << "\n";
}