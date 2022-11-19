// acmicpc number: 20040
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
        {
            parent[y] = x;
        }
        else
        {
            parent[x] = y;
        }
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

    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        if (uf->find(s) == uf->find(e))
        {
            cout << i + 1;
            return 0;
        }
        else
            uf->merge(s, e);
    }
    cout << 0;
}