// acmicpc number: 4196
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll T, n, m;

void dfs(int i, vector<int> *g, vector<pair<int, int>> &f, int &c, vector<bool> &visited)
{
    visited[i] = true;
    for (auto ch : g[i])
    {
        if (!visited[ch])
            dfs(ch, g, f, c, visited);
    }
    f.push_back({c++, i});
}

void dfs(vector<int> *g, vector<pair<int, int>> &f)
{
    int c = 1;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            dfs(i, g, f, c, visited);
        }
    }
}

void dfs2(int u, vector<bool> &visited, vector<int> *g)
{
    visited[u] = true;
    for (auto ch : g[u])
    {
        if (!visited[ch])
            dfs2(ch, visited, g);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> n >> m;
        vector<int> graph[n];
        vector<pair<int, int>> f_time;

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1].push_back(b - 1);
        }

        dfs(graph, f_time);
        sort(f_time.begin(), f_time.end(), greater<pair<int, int>>());

        vector<bool> visited(n, false);
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[f_time[i].second])
            {
                ret++;
                dfs2(f_time[i].second, visited, graph);
            }
        }

        cout << ret << "\n";
    }
}