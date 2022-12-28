// acmicpc number: 11505
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m, k;
constexpr int INTDIV = 1000000007;

ll init(int idx, int s, int e, vector<int>& stree, vector<int>& in)
{
    ll ret;
    if (s == e)
    {
        stree[idx] = in[s];
        return ret = stree[idx];
    }

    int mid = (s + e) / 2;
    ret = (init(idx * 2, s, mid, stree, in) * init(idx * 2 + 1, mid + 1, e, stree, in)) % INTDIV;
    stree[idx] = ret;
    return ret;
}

void update(int idx, int s, int e, int uidx, int val, vector<int>& stree)
{
    if (uidx < s || e < uidx)
        return;
    
    if (s == e && uidx == s)
    {
        stree[idx] = (val) % INTDIV;
        return;
    }

    int mid = (s + e) / 2;
    update(idx * 2, s, mid, uidx, val, stree);
    update(idx * 2 + 1, mid + 1, e, uidx, val, stree);
    ll r1 = stree[idx * 2], r2 = stree[idx * 2 + 1];
    ll ret = (r1 * r2) % INTDIV;
    stree[idx] = ret;
}

void update(int idx, int val, vector<int>& stree)
{
    update(1, 0, n - 1, idx, val, stree);
}

ll get(int idx, int s, int e, int qs, int qe, vector<int>& stree)
{
    if (qe < s || e < qs)
        return 1;
    
    if (qs <= s && e <= qe)
        return stree[idx];

    int mid = (s + e) / 2;
    return (get(idx * 2, s, mid, qs, qe, stree) * get(idx * 2 + 1, mid + 1, e, qs, qe, stree)) % INTDIV;
}

ll get(int s, int e, vector<int>& stree)
{
    return get(1, 0, n - 1, s, e, stree);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    vector<int> stree(4 * n, 0);
    vector<int> in(n, 0);

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