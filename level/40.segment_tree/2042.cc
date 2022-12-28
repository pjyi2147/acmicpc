// acmicpc number: 2042
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m, k;

ll init(int idx, int s, int e, vector<ll> &stree, vector<ll> &in)
{
    if (s == e)
    {
        stree[idx] = in[s];
        return stree[idx];
    }

    ll mid = (s + e) / 2;
    stree[idx] = init(idx * 2, s, mid, stree, in) + init(idx * 2 + 1, mid + 1, e, stree, in);
    return stree[idx];
}

void update(int idx, int s, int e, int seg_i, ll value, vector<ll> &stree)
{
    if (seg_i < s || seg_i > e)
        return;

    if (s == e && s == seg_i)
    {
        stree[idx] = value;
        return;
    }

    int mid = (s + e) / 2;
    update(idx * 2 + 1, mid + 1, e, seg_i, value, stree);
    update(idx * 2, s, mid, seg_i, value, stree);
    stree[idx] = stree[idx * 2] + stree[idx * 2 + 1];
}

void update(int i, ll value, vector<ll> &stree)
{
    update(1, 0, n - 1, i, value, stree);
}

ll get(int idx, int s, int e, int qs, int qe, vector<ll> &stree)
{
    if (qs <= s && e <= qe)
        return stree[idx];

    if (e < qs || qe < s)
        return 0;

    int mid = (s + e) / 2;
    return get(idx * 2, s, mid, qs, qe, stree) + get(idx * 2 + 1, mid + 1, e, qs, qe, stree);
}

ll get(int qs, int qe, vector<ll> &stree)
{
    return get(1, 0, n - 1, qs, qe, stree);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    vector<ll> stree(4 * n, 0);
    vector<ll> in(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    init(1, 0, n - 1, stree, in);

    for (int i = 0; i < m + k; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(b - 1, c, stree);
        }
        else
        {
            cout << get(b - 1, c - 1, stree) << "\n";
        }
    }
}