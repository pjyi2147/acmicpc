// acmicpc number: 2110
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> c;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    ll l = 1, r = v[n-1] - v[0];
    while (l <= r)
    {
        ll m = (l + r) / 2;
        ll cnt = 1;
        int prev = 0;
        for (int i = 1; i < n; i++) 
        {
            if (v[i] - v[prev] >= m)
            {
                cnt++;
                prev = i;
            }
        }
        if (cnt >= c) 
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