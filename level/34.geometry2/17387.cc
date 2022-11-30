// acmicpc number: 17387
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c)
{
    pair<ll, ll> v1 = {b.first - a.first, b.second - a.second}, v2 = {c.first - b.first, c.second - b.second};
    ll t1 = v1.first * v2.second;
    ll t2 = v2.first * v1.second;
    if (t1 < t2)
        return -1;
    if (t1 == t2)
        return 0;
    return 1;
}

void solve(vector<pair<ll, ll>> &pts)
{
    ll tmp1 = ccw(pts[0], pts[1], pts[2]) * ccw(pts[0], pts[1], pts[3]);
    ll tmp2 = ccw(pts[2], pts[3], pts[0]) * ccw(pts[2], pts[3], pts[1]);
    if (tmp1 <= 0 && tmp2 <= 0)
    {
        if (tmp1 == 0 && tmp2 == 0)
        {
            if (pts[0] > pts[1])
                swap(pts[0], pts[1]);
            if (pts[2] > pts[3])
                swap(pts[2], pts[3]);
            if (pts[2] <= pts[1] && pts[0] <= pts[3])
                cout << 1;
            else
                cout << 0;
        }
        else
            cout << 1;
    }
    else
        cout << 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<ll, ll>> pts;
    for (int i = 0; i < 4; i++)
    {
        int x, y;
        cin >> x >> y;
        pts.push_back({x, y});
    }
    solve(pts);
}