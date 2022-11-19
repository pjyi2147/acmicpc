// acmicpc number: 4195
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, f;

struct UF
{
    int *parent;
    int *rank;
    int *size;
    UF(int n)
    {
        parent = new int[n];
        rank = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
            size[i] = 1;
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
    int s(int u)
    {
        u = find(u);
        return size[u];
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (rank[x] > rank[y])
        {
            parent[y] = x;
            size[x] += size[y];
        }
        else
        {
            parent[x] = y;
            if (x != y)
                size[y] += size[x];
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
    cin >> n;
    for (int t = 0; t < n; t++)
    {
        cin >> f;
        map<string, int> mp;
        int cnt = 1;
        auto uf = new UF(200001);
        for (int i = 0; i < f; i++)
        {
            string a, b;
            int aidx, bidx;
            cin >> a >> b;
            if (mp[a] == 0)
            {
                aidx = cnt;
                mp[a] = cnt++;
            }
            else
                aidx = mp[a];
            if (mp[b] == 0)
            {
                bidx = cnt;
                mp[b] = cnt++;
            }
            else
                bidx = mp[b];
            uf->merge(aidx-1, bidx-1);
            cout << uf->s(aidx-1) << "\n";
        }
    }
}