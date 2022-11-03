// acmicpc number: 9370
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int TC;
int INF = 987654321;

void dijkstra(int s, vector<int> &dist, const vector<vector<int>> &node)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        auto u = pq.top().second;
        auto c = pq.top().first;
        pq.pop();

        if (c > dist[u])
            continue;
        for (int i = 0; i < node.size(); i++)
        {
            if (node[u][i] == INF)
                continue;
            if (dist[i] > dist[u] + node[u][i])
            {
                dist[i] = dist[u] + node[u][i];
                pq.push({dist[i], i});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> TC;
    for (int qwe = 0; qwe < TC; qwe++)
    {
        int n, m, t, s, g, h;
        cin >> n >> m >> t >> s >> g >> h;
        vector<vector<int>> node(n + 1, vector<int>(n + 1, INF));
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b >> node[a][b];
            node[b][a] = node[a][b];
        }

        vector<int> cand(t, INF);
        for (int i = 0; i < t; i++)
        {
            cin >> cand[i];
        }

        vector<int> dist_s(n + 1, INF);
        vector<int> dist_g(n + 1, INF);
        vector<int> dist_h(n + 1, INF);

        dijkstra(s, dist_s, node);
        dijkstra(g, dist_g, node);
        dijkstra(h, dist_h, node);

        sort(cand.begin(), cand.end());
        for (auto i : cand)
        {
            if (dist_s[i] == dist_s[g] + node[g][h] + dist_h[i])
                cout << i << " ";
            else if (dist_s[i] == dist_s[h] + node[h][g] + dist_g[i])
                cout << i << " ";
        }
        cout << '\n';
    }
}