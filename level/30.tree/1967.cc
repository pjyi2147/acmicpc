// acmicpc number: 1967
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;

void dfs(int k, int p, int c, vector<int>& dist, const vector<vector<pair<int, int>>>& tree)
{
    if (p == -1)
        dist[k] = 0;
    else
        dist[k] = dist[p] + c;
    
    for (auto i : tree[k])
    {
        if (i.first != p)
        {
            dfs(i.first, k, i.second, dist, tree);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<vector<pair<int, int>>> tree(n);

    for (int i = 0; i < n - 1; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        tree[s-1].push_back({e-1, c});
        tree[e-1].push_back({s-1, c});
    }

    vector<int> dist1(n, -1);
    dfs(0, -1, 0, dist1, tree);
    int k = max_element(dist1.begin(), dist1.end()) - dist1.begin();
    vector<int> dist2(n, -1);
    dfs(k, -1, 0, dist2, tree);
    cout << *max_element(dist2.begin(), dist2.end());
}