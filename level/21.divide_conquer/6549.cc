// acmicpc number: 6549
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

ll solve(vector<ll>& v, ll l, ll r)
{
    if (l == r) return v[l];
    ll m = (l + r) / 2;
    ll ret = max(solve(v, l, m), solve(v, m + 1, r));
    ll lo = m, hi = m + 1;
    ll h = min(v[lo], v[hi]);
    ret = max(ret, h * 2);
    while (l < lo || hi < r) {
        if (hi < r && (lo == l || v[lo - 1] < v[hi + 1])) {
            ++hi;
            h = min(h, v[hi]);
        } else {
            --lo;
            h = min(h, v[lo]);
        }
        ret = max(ret, h * (hi - lo + 1));
    }
    return ret;
}

ll solve(vector<ll>& v) 
{
    return solve(v, 0, v.size() - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (cin >> n && n) {
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << solve(v) << "\n";
    }
}