// acmicpc number: 1654
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll k, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k >> n;
    vector<ll> v(k);
    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
    }

    ll l = 1, r = INT32_MAX;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        ll cnt = 0;
        for (int i = 0; i < k; i++)
        {
            cnt += v[i] / m;
        }
        if (cnt >= n)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    cout << r;
}