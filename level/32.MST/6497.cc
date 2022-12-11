// acmicpc number: 6497
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;

struct UF 
{
    int *parent;
    int *rank;

    UF(int k)
    {
        parent = new int[k];
        rank = new int[k];

        for (int i = 0; i < k; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    ~UF()
    {
        delete[] parent;
        delete[] rank;
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        if (x != y)
        {
            if (rank[x] > rank[y])
            {
                parent[y] = x;
            }
            else
                parent[x] = y;
            
            if (rank[x] == rank[y])
                rank[y]++;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while (cin >> m >> n)
    {
        UF uf(m);
        if (n == 0 && m == 0) return 0;
        vector<pair<int, pair<int, int>>> edges;
        ll total = 0;
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            total += z;
            edges.push_back({z, {x, y}});
        }

        sort(edges.begin(), edges.end());
        int saved = 0;
        for (auto e : edges)
        {
            if (uf.find(e.second.first) != uf.find(e.second.second))
            {
                uf.merge(e.second.first, e.second.second);
                saved += e.first;
            }
        }
        cout << total - saved << "\n";
    }
}