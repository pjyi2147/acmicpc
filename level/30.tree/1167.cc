// acmicpc number: 1167
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
constexpr int INF = 987654321;

void dfs(int r, int p, int c, vector<int>& dist, vector<vector<pair<int, int>>>& tree)
{
    if (p == -1)
        dist[r] = 0;
    else
        dist[r] = dist[p] + c;
    
    for (auto ch: tree[r])
    {
        if (ch.first == p) continue;
        dfs(ch.first, r, ch.second, dist, tree);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<vector<pair<int, int>>> tree(n);
    for (int i = 0; i < n; i++)
    {
        int k, a, b;
        cin >> k;
        while (cin >> a && a != -1)
        {
            cin >> b;
            tree[k - 1].push_back({a - 1, b});
        }
    }
    vector<int> dist(n, -1);
    dfs(0, -1, 0, dist, tree);
    auto k = max_element(dist.begin(), dist.end()) - dist.begin();
    vector<int> dist2(n, -1);
    dfs(k, -1, 0, dist2, tree);
    cout << *max_element(dist2.begin(), dist2.end());
}