// acmicpc number: 2085
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll l = 1, r = INT32_MAX;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += max(0LL, v[i] - mid);
        }
        if (cnt >= m)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << r;
}