// acmicpc number: 1976
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;

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
    cin >> n >> m;

    auto uf = new UF(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int k;
            cin >> k;
            if (k == 1) uf->merge(i, j);
        }

    vector<bool> route(n, false);
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        route[k - 1] = true;
    }

    bool pos = true;
    for (int i = 0; i < n; i++)
    {
        if (!route[i]) continue;
        for (int j = i + 1; j < n; j++)
        {
            if (!route[j])
                continue;
            if (uf->find(i) != uf->find(j))
                pos = false;
        }
    }
    cout << (pos ? "YES" : "NO");
}