// acmicpc number: 1774
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;

struct UF
{
    int *parents;
    int *rank;
    UF(int n)
    {
        parents = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
            rank[i] = 1;
        }
    }

    ~UF()
    {
        delete[] parents;
        delete[] rank;
    }

    int find(int n)
    {
        if (parents[n] != n)
            parents[n] = find(parents[n]);
        return parents[n];
    }

    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (rank[x] > rank[y])
            parents[y] = x;
        else
            parents[x] = y;
        if (rank[x] == rank[y])
            rank[y]++;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    auto uf = new UF(n);
    vector<pair<int, int>> pts(n);
    vector<pair<double, pair<int, int>>> edges;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        uf->merge(a - 1, b - 1);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double dist = sqrt(pow(pts[i].first - pts[j].first, 2) + pow(pts[i].second - pts[j].second, 2));
            edges.push_back({dist, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    double ret = 0;
    for (auto &i : edges)
    {
        if (uf->find(i.second.first) != uf->find(i.second.second))
        {
            uf->merge(i.second.first, i.second.second);
            ret += i.first;
        }
    }
    cout << setprecision(2) << fixed << ret;
}