// acmicpc number: 2166
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll n;

ll tri(pair<ll, ll> x, pair<ll, ll> y)
{
    return x.first * y.second - x.second * y.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<pair<ll, ll>> pts;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        pts.push_back({x, y});
    }

    ld ret = 0;
    for (int i = 1; i < n - 1; i++)
    {
        ret += (ld)tri({pts[i].first - pts[0].first, pts[i].second - pts[0].second}, {pts[i+1].first - pts[0].first, pts[i+1].second - pts[0].second});
    }
    ld ret2 = ret / 2;
    cout << fixed;
    cout << setprecision(1) << abs(ret2);
}