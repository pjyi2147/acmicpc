// acmicpc number: 5419
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
int segt[75001 * 4];

int query(int idx, int s, int e, int qs, int qe)
{
    if (qe < s || qs > e)
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
    if (nidx < s || nidx > e)
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
    int t;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        cin >> n;
        memset(segt, 0, sizeof(segt));
        vector<pair<int, int>> v;
        vector<int> y;
        map<int, int> my;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a, -b});
            y.push_back(-b);
        }
        sort(v.begin(), v.end());
        sort(y.begin(), y.end());
        for (int i = 0; i < y.size(); i++)
        {
            my[y[i]] = i;
        }

        ll ret = 0;
        for (auto p : v)
        {
            ret += query(1, 0, n - 1, 0, my[p.second]);
            update(1, 0, n - 1, my[p.second]);
        }
        cout << ret << '\n';
    }
}