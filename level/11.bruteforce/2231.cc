// acmicpc number: 2231
#include <bits/stdc++.h>
using namespace std;

int digitsum(int n)
{
    if (n < 10) return n;
    return n % 10 + digitsum(n / 10);
}

int main()
{
    int n;
    cin >> n;
    bool find = false;
    int ans = 0;

    for (int i = n - 54; i < n; i++)
    {  
        if (i + digitsum(i) == n) 
        {
            find = true;
            ans = i;
            break;
        }
    }

    if (find) cout << ans << "\n";
    else cout << 0 << "\n";
}