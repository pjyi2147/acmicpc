// acmicpc number: 7626
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i=(a); i < (b); i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int MAXN = 4e5 + 1;
ll segt[MAXN * 4];
ll cnt[MAXN * 4];
ll n;

void update(int idx, int s, int e, int qs, int qe, int val, const vector<int>& vy)
{
    if (qe < s || e < qs)
        return;
    
    if (qs <= s && e <= qe)
    {
        cnt[idx] += val;
    }
    else 
    {
        int mid = (s + e) / 2;
        update(idx * 2, s, mid, qs, qe, val, vy);
        update(idx * 2 + 1, mid + 1, e, qs, qe, val, vy);
    }

    if (cnt[idx])
    {
        segt[idx] = vy[e] - vy[s - 1];
    }
    else if (s == e)
    {
        segt[idx] = 0;
    }
    else
    {
        segt[idx] = segt[idx * 2] + segt[idx * 2 + 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<pair<pair<int, pii>, bool>> v;
    vector<int> vy;
    FOR(i, n)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        v.push_back({{x1, {y1 + 1, y2 + 1}}, true});
        v.push_back({{x2, {y1 + 1, y2 + 1}}, false});
        vy.push_back(y1 + 1);
        vy.push_back(y2 + 1);
    }
    sort(vy.begin(), vy.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    sort(v.begin(), v.end());

    int lidx = 0, ridx = 0;
    ll ret = 0;
    int diff_x;
    FOR(i, v.size())
    {
        if (i > 0)
        {
            diff_x = v[i].first.first - v[i - 1].first.first;
            ret += diff_x * segt[1];
        }
        int val = v[i].second ? 1 : -1;
        int y1_idx = lower_bound(vy.begin(), vy.end(), v[i].first.second.first) - vy.begin();
        int y2_idx = lower_bound(vy.begin(), vy.end(), v[i].first.second.second) - vy.begin();
        update(1, 1, MAXN, y1_idx + 1, y2_idx, val, vy);
    }
    cout << ret;
}