// acmicpc number: 1753
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int v, e, k;
int INF = 987654321;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e >> k;
    vector<pair<int, int>> node[20001];
    vector<int> dist(v+1, INF);

    for (int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        node[a].push_back(make_pair(b, w));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[k] = 0;
    pq.push(make_pair(0, k));
    while (!pq.empty())
    {
        auto u = pq.top();
        pq.pop();

        for (int i = 0; i < node[u.second].size(); i++)
        {
            int a = node[u.second][i].first;
            int W = node[u.second][i].second;

            if (u.first + W < dist[a])
            {
                dist[a] = u.first + W;
                pq.push(make_pair(dist[a], a));
            }
        }
    }

    for (int i = 1; i <= v; i++)
    {
        if (dist[i] != INF) cout << dist[i] << '\n';
        else cout << "INF\n";
    }
}