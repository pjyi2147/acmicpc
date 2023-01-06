// acmicpc number: 17131
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

constexpr int INTDIV = 1000000007;
int segt[200001 * 4];

int query(int idx, int s, int e, int qs, int qe)
{
    if (qe < s || e < qs)
        return 0;

    if (qs <= s && e <= qe)
    {
        return segt[idx];
    }

    int mid = (s + e) / 2;
    return query(idx * 2, s, mid, qs, qe) + query(idx * 2 + 1, mid + 1, e, qs, qe);
}

void update(int idx, int s, int e, int nidx)
{
    if (nidx < s || e < nidx)
        return;

    segt[idx]++;
    if (s == e)
        return;

    int mid = (s + e) / 2;
    update(idx * 2, s, mid, nidx);
    update(idx * 2 + 1, mid + 1, e, nidx);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    vector<pair<int, int>> v;
    vector<int> vx;
    map<int, int> mx;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
        vx.push_back(a);
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    sort(vx.begin(), vx.end());

    for (int i = 0; i < n; i++)
    {
        mx[vx[i]] = i;
    }

    vector<int> q;
    int cury = v[0].first;
    ll ret = 0;
    for (int i = 0; i < n; i++)
    {
        auto p = v[i];
        if (p.first == cury)
        {
            q.push_back(p.second);
            continue;
        }

        for (auto x : q)
        {
            ll ql = query(1, 0, n - 1, 0, mx[x] - 1);
            ll qr = query(1, 0, n - 1, mx[x] + 1, n - 1);
            ret += (ql * qr);
            ret %= INTDIV;
        }

        for (auto x : q)
        {
            update(1, 0, n - 1, mx[x]);
        }

        q.clear();
        q.push_back(p.second);
        cury = p.first;
    }
    for (auto x : q)
    {
        ll ql = query(1, 0, n - 1, 0, mx[x] - 1);
        ll qr = query(1, 0, n - 1, mx[x] + 1, n - 1);
        ret += (ql * qr);
        ret %= INTDIV;
    }
    cout << ret;
}