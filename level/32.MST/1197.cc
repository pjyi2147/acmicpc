// acmicpc number: 1197
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll v, e;

struct UF
{
    int *parent;
    int *rank;
    UF(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }
    ~UF()
    {
        delete[] parent;
        delete[] rank;
    }
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (rank[x] > rank[y])
            parent[y] = x;
        else
            parent[x] = y;
        if (rank[x] == rank[y])
            rank[y]++;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e;
    auto uf = new UF(v);
    vector<pair<int, pair<int, int>>> edges;
    edges.reserve(e);
    for (int i = 0; i < e; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        edges.push_back({c, {s - 1, e - 1}});
    }

    sort(edges.begin(), edges.end());

    ll ret = 0;
    for (auto e : edges)
    {
        if (uf->find(e.second.first) != uf->find(e.second.second))
        {
            uf->merge(e.second.first, e.second.second);
            ret += e.first;
        }
    }
    cout << ret;
}