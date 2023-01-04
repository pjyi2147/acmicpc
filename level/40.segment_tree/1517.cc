// acmicpc number: 1517
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
int segt[2000000];
vector<int> v;

void update(int idx, int s, int e, int nidx)
{
    if (nidx < s || nidx > e)
        return;
    if (s == e)
    {
        segt[idx] += 1;
        return;
    }

    segt[idx] += 1;
    int mid = (s + e) / 2;
    update(idx * 2, s, mid, nidx);
    update(idx * 2 + 1, mid + 1, e, nidx);
}

int query(int idx, int s, int e, int qs, int qe)
{
    if (qe < s || qs > e)
        return 0;
    if (qs <= s && e <= qe)
        return segt[idx];

    int mid = (s + e) / 2;
    return query(idx * 2, s, mid, qs, qe) + query(idx * 2 + 1, mid + 1, e, qs, qe);
}

int comp(int value)
{
    return lower_bound(v.begin(), v.end(), value) - v.begin();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset(segt, 0, sizeof(segt));
    vector<int> tmp;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        tmp.push_back(k);
        v.push_back(k);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    ll ret = 0;

    for (int i = 0; i < n; i++)
    {
        ret += query(1, 0, n - 1, comp(tmp[i]) + 1, n - 1);
        update(1, 0, n - 1, comp(tmp[i]));
    }

    cout << ret;
}