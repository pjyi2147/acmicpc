// acmicpc number: 12899
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
int segt[8000000 + 4];
constexpr int M = 2000000;

void update(int idx, int s, int e, int x)
{
    if (x < s || x > e)
        return;

    segt[idx]++;
    if (s == e)
        return;

    int mid = (s + e) / 2;
    update(idx * 2, s, mid, x);
    update(idx * 2 + 1, mid + 1, e, x);
}

void update(int x)
{
    update(1, 1, M, x);
}

int query(int idx, int s, int e, int x)
{
    segt[idx]--;
    if (s == e)
        return s;

    int mid = (s + e) / 2;
    int left = segt[idx * 2];
    if (x <= left)
        return query(idx * 2, s, mid, x);
    return query(idx * 2 + 1, mid + 1, e, x - left);
}

int query(int x)
{
    return query(1, 1, M, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int t, x;
        cin >> t >> x;
        if (t == 1)
        {
            update(x);
        }
        else
        {
            cout << query(x) << "\n";
        }
    }
}