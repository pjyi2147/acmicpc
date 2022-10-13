// acmicpc number: 11401
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
const ll MOD = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    ll a = 1, b = 1;
    for (int i = 1; i <= n; i++)
    {
        a = a * i % MOD;
    }

    for (int i = 1; i <= k; i++)
    {
        b = b * i % MOD;
    }
    for (int i = 1; i <= n-k; i++)
    {
        b = b * i % MOD;
    }

    ll b2 = 1;
    ll p = MOD - 2;
    while (p)
    {
        if (p % 2)
        {
            b2 = b2 * b % MOD;
        }
        b = b * b % MOD;
        p /= 2;
    }
    
    cout << a * b2 % MOD;
}