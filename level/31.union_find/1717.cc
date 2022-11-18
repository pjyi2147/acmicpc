// acmicpc number: 1717
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m;

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
    auto uf = new UF(n + 1);
    for (int i = 0; i < m; i++)
    {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 0)
        {
            uf->merge(a, b);
        }
        else 
        {
            if (uf->find(a) == uf->find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    delete uf;
}