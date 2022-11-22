// acmicpc number: 2887
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

struct UF
{
    int *parents;
    int *ranks;
    UF(int k)
    {
        parents = new int[k];
        ranks = new int[k];
        for (int i = 0; i < k; i++)
        {
            parents[i] = i;
            ranks[i] = 1;
        }
    }
    ~UF()
    {
        delete[] parents;
        delete[] ranks;
    }
    int find(int k)
    {
        if (parents[k] != k)
            parents[k] = find(parents[k]);
        return parents[k];
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (ranks[x] > ranks[y])
            parents[y] = x;
        else
            parents[x] = y;
        if (ranks[x] == ranks[y])
            ranks[y]++;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<pair<int, int>> ptx(n);
    vector<pair<int, int>> pty(n);
    vector<pair<int, int>> ptz(n);
    vector<pair<int, pair<int, int>>> dist;
    auto uf = new UF(n);
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        ptx[i] = {x, i};
        pty[i] = {y, i};
        ptz[i] = {z, i};
    }
    sort(ptx.begin(), ptx.end());
    sort(pty.begin(), pty.end());
    sort(ptz.begin(), ptz.end());

    for (int i = 0; i < n - 1; i++)
    {
        dist.push_back({abs(ptx[i + 1].first - ptx[i].first), {ptx[i].second, ptx[i + 1].second}});
        dist.push_back({abs(pty[i + 1].first - pty[i].first), {pty[i].second, pty[i + 1].second}});
        dist.push_back({abs(ptz[i + 1].first - ptz[i].first), {ptz[i].second, ptz[i + 1].second}});
    }

    sort(dist.begin(), dist.end());

    ll ret = 0;
    for (auto i : dist)
    {
        if (uf->find(i.second.first) != uf->find(i.second.second))
        {
            ret += i.first;
            uf->merge(i.second.first, i.second.second);
        }
    }
    cout << ret;
}