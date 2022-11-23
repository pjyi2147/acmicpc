// acmicpc number: 15681
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, r, q;

void setroot(int r, int p, vector<int>& parent, const vector<vector<int>>& g)
{
    if (parent[r] == -1 && p != -1)
        parent[r] = p;

    for (auto ch : g[r])
    {
        if (ch != p) 
        {
            setroot(ch, r, parent, g);
        }
    }
}

int solve(int r, vector<int>& parent, const vector<vector<int>>& g, vector<int>& subnodes)
{
    if (subnodes[r] != -1)
        return subnodes[r];

    subnodes[r] = 1;
    for (auto ch : g[r])
    {
        if (ch != parent[r])
        {
            subnodes[r] += solve(ch, parent, g, subnodes);
        }
    }
    return subnodes[r];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> r >> q;

    vector<vector<int>> g(n, vector<int>());
    vector<int> subnodes(n, -1);

    for (int i = 0; i < n-1; i++)
    {
        int s, e;
        cin >> s >> e;
        g[s-1].push_back(e-1);
        g[e-1].push_back(s-1);
    }

    vector<int> parent(n, -1);
    setroot(r - 1, -1, parent, g);

    solve(r - 1, parent, g, subnodes);
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        cout << subnodes[k - 1] << "\n";
    }
}