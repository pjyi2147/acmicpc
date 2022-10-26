// acmicpc number: 2606
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, k;

int solve(int node, vector<bool>& visited, const vector<vector<int>>& nodes)
{
    int ret = 0;
    visited[node] = true;
    for (int i = 0; i < nodes[node].size(); i++)
    {
        int tmp = nodes[node][i];
        if (!visited[tmp])
        {
            ret++;
            ret += solve(tmp, visited, nodes);
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;

    vector<vector<int>> nodes(n+1, vector<int>());

    for (int i = 0; i < k; i++)
    {
        int s, e;
        cin >> s >> e;
        nodes[s].push_back(e);
        nodes[e].push_back(s);
    }
    vector<bool> visited(n+1, false);
    cout << solve(1, visited, nodes);
}