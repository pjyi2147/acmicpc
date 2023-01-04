// acmicpc number: 1168
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, k;

int segt[400000];

void init(int idx, int s, int e, int nidx)
{
    if (nidx < s || nidx > e)
        return;

    segt[idx]++;
    if (s == e)
        return;

    int mid = (s + e) / 2;
    init(idx * 2, s, mid, nidx);
    init(idx * 2 + 1, mid + 1, e, nidx);
}

void init()
{
    for (int i = 0; i < n; i++)
    {
        init(1, 0, n - 1, i);
    }
}

int query(int idx, int s, int e, int q)
{
    segt[idx]--;
    if (s == e)
        return s;

    int mid = (s + e) / 2;
    int left = segt[idx * 2];
    if (q <= left)
        return query(idx * 2, s, mid, q);
    return query(idx * 2 + 1, mid + 1, e, q - left);
}

int query(int q)
{
    return query(1, 0, n - 1, q) + 1;
}

void print()
{
    cout << "<";
    int q = k;
    for (int i = 0; i < n - 1; i++)
    {
        cout << query(q) << ", ";
        q += k - 1;
        q %= segt[1];
        if (q == 0)
            q = segt[1];
    }
    cout << query(q) << ">\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    init();
    print();
}