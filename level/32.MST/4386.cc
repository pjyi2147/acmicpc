// acmicpc number: 4386
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

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
    cin >> n;

    vector<pair<double, double>> points;
    auto uf = new UF(n);
    for (int i = 0; i < n; i++)
    {
        double a, b;
        cin >> a >> b;
        points.push_back({a, b});
    }

    vector<pair<double, pair<int, int>>> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double dist = sqrt(pow((points[i].first - points[j].first), 2) + pow((points[i].second - points[j].second), 2));
            edges.push_back({dist, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());
    double ret = 0;
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