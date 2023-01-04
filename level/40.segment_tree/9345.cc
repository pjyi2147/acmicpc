// acmicpc number: 9345
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t, n, k;
int segt_max[400000];
int segt_min[400000];

void update_max(int idx, int s, int e, int nidx, int val)
{
    if (nidx < s || nidx > e)
        return;
    if (s == e && nidx == s)
    {
        segt_max[idx] = val;
        return;
    }

    int mid = (s + e) / 2;
    update_max(idx * 2, s, mid, nidx, val);
    update_max(idx * 2 + 1, mid + 1, e, nidx, val);
    segt_max[idx] = max(segt_max[idx * 2], segt_max[idx * 2 + 1]);
}

void update_min(int idx, int s, int e, int nidx, int val)
{
    if (nidx < s || nidx > e)
        return;
    if (s == e && nidx == s)
    {
        segt_min[idx] = val;
        return;
    }

    int mid = (s + e) / 2;
    update_min(idx * 2, s, mid, nidx, val);
    update_min(idx * 2 + 1, mid + 1, e, nidx, val);
    segt_min[idx] = min(segt_min[idx * 2], segt_min[idx * 2 + 1]);
}

void update(int nidx, int val)
{
    update_max(1, 0, n - 1, nidx, val);
    update_min(1, 0, n - 1, nidx, val);
}

int query_max(int idx, int s, int e, int qs, int qe)
{
    if (qs > e || qe < s)
        return 0;
    if (qs <= s && e <= qe)
    {
        return segt_max[idx];
    }
    int mid = (s + e) / 2;
    return max(query_max(idx * 2, s, mid, qs, qe), query_max(idx * 2 + 1, mid + 1, e, qs, qe));
}

int query_min(int idx, int s, int e, int qs, int qe)
{
    if (qs > e || qe < s)
        return INT_MAX;
    if (qs <= s && e <= qe)
    {
        return segt_min[idx];
    }
    int mid = (s + e) / 2;
    return min(query_min(idx * 2, s, mid, qs, qe), query_min(idx * 2 + 1, mid + 1, e, qs, qe));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (int T = 0; T < t; T++)
    {
        cin >> n >> k;
        vector<int> shelf(n, 0);

        for (int i = 0; i < n; i++)
        {
            shelf[i] = i;
            update(i, i);
        }

        for (int i = 0; i < k; i++)
        {
            int q, a, b;
            cin >> q >> a >> b;
            if (q == 0)
            {
                update(a, shelf[b]);
                update(b, shelf[a]);
                swap(shelf[a], shelf[b]);
            }
            else
            {
                int qmax = query_max(1, 0, n - 1, a, b);
                int qmin = query_min(1, 0, n - 1, a, b);
                if (qmin == a && qmax == b)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
}
