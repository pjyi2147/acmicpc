// acmicpc number: 20149
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

void inter(vector<pair<ll, ll>>& pts)
{
    double A = pts[1].second - pts[0].second, B = pts[0].first - pts[1].first, E = A * pts[0].first + B * pts[0].second;
    double C = pts[3].second - pts[2].second, D = pts[2].first - pts[3].first, F = C * pts[2].first + D * pts[2].second;

    double det = (A * D) - (B * C);
    double tmp1 = (E * D) - (B * F);
    double tmp2 = (A * F) - (E * C);

    if (det != 0)
    {
        cout << setprecision(11) << fixed << tmp1 / det << " " << tmp2 / det;
    }
}

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
    ll tmp1 = ccw(pts[0], pts[1], pts[2]);
    ll tmp2 = ccw(pts[0], pts[1], pts[3]);
    ll tmp3 = ccw(pts[2], pts[3], pts[0]);
    ll tmp4 = ccw(pts[2], pts[3], pts[1]);
    if (tmp1 * tmp2 == 0 && tmp3 * tmp4 == 0)
    {
        if (pts[0] > pts[1])
            swap(pts[0], pts[1]);
        if (pts[2] > pts[3])
            swap(pts[2], pts[3]);
        if (tmp1 == 0 && tmp2 == 0 && tmp3 == 0 && tmp4 == 0)
        {
            if (pts[0] <= pts[3] && pts[2] <= pts[1])
            {
                cout << 1 << '\n';
                if (pts[0] == pts[3])
                {
                    cout << pts[0].first << " " << pts[0].second;
                }
                else if (pts[2] == pts[1])
                {
                    cout << pts[2].first << " " << pts[2].second;
                }
                else
                {
                    inter(pts);
                }
            }
            else
                cout << 0;
        }
        else
        {
            cout << 1 << '\n';
            inter(pts);
        }
    }
    else if (tmp1 * tmp2 <= 0 && tmp3 * tmp4 <= 0)
    {
        cout << 1 << '\n';
        inter(pts);
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