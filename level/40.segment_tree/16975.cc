// acmicpc number: 16975
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;
ll segt[400000];
ll val[100000];

void update(int idx, int s, int e, int qs, int qe, int val)
{
    if (qe < s || e < qs)
        return;
    if (qs <= s && e <= qe)
    {
        segt[idx] += val;
        return;
    }

    int mid = (s + e) / 2;
    update(idx * 2, s, mid, qs, qe, val);
    update(idx * 2 + 1, mid + 1, e, qs, qe, val);
}

ll query(int idx, int s, int e, int qidx)
{
    if (qidx < s || qidx > e)
        return 0;
    if (s == e && qidx == s)
        return segt[idx];

    ll ret = segt[idx];

    int mid = (s + e) / 2;
    return ret + ((qidx <= mid) ? query(idx * 2, s, mid, qidx) : query(idx * 2 + 1, mid + 1, e, qidx));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    memset(segt, 0, sizeof(segt));

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int a, b, c;
            cin >> a >> b >> c;
            update(1, 0, n - 1, a - 1, b - 1, c);
        }
        else
        {
            int x;
            cin >> x;
            ll ret = val[x - 1] + query(1, 0, n - 1, x - 1);
            cout << ret << "\n";
        }
    }
}