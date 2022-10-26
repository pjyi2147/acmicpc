// acmicpc number: 24480
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m, r;

void dfs(int r, int& d, vector<int>& visited, vector<priority_queue<int>>& node)
{
    visited[r] = d;

    while (!node[r].empty())
    {
        int tmp = node[r].top();
        node[r].pop();
        if (visited[tmp] == 0)
        {
            dfs(tmp, ++d, visited, node);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> r;

    vector<int> visited(n+1, 0);
    vector<priority_queue<int>> node(n+1, priority_queue<int>());

    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        node[s].push(e);
        node[e].push(s);
    }

    int d = 1;
    dfs(r, d, visited, node);

    for (int i = 1; i <= n; i++)
    {
        cout << visited[i] << "\n";
    }
}