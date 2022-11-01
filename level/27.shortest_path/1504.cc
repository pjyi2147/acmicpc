// acmicpc number: 1504
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, e;
int INF = 987654321;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> e;
    vector<vector<int>> node(n+1, vector<int>(n+1, INF));
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        node[a][b] = min(c, node[a][b]);
        node[b][a] = min(c, node[b][a]);
    }
    int v1, v2;
    cin >> v1 >> v2;

    vector<int> dist_1ton(n+1, INF); 
    vector<int> dist_nto1(n+1, INF);
    dist_1ton[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto u = pq.top().second;
        auto c = pq.top().first;
        pq.pop();

        if (dist_1ton[u] < c) continue;
        for (int i = 1; i < n+1; i++)
        {
            if (node[u][i] < INF)
            {
                if (dist_1ton[i] > node[u][i] + c)
                {
                    dist_1ton[i] = node[u][i] + c;
                    pq.push({dist_1ton[i], i});
                }
            }
        }
    }

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq2;
    dist_nto1[n] = 0;
    pq2.push({0, n});
    while (!pq2.empty())
    {
        auto u = pq2.top().second;
        auto c = pq2.top().first;
        pq2.pop();

        if (dist_nto1[u] < c) continue;
        for (int i = 1; i < n+1; i++)
        {
            if (node[u][i] < INF)
            {
                if (dist_nto1[i] > node[u][i] + c)
                {
                    dist_nto1[i] = node[u][i] + c;
                    pq2.push({dist_nto1[i], i});
                }
            }
        }
    }

    vector<int> dist_v1tov2(n+1, INF);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq3;
    dist_v1tov2[v1] = 0;
    pq3.push({0, v1});
    while (!pq3.empty())
    {
        auto u = pq3.top().second;
        auto c = pq3.top().first;
        pq3.pop();
        if (u == v2) break;
        if (dist_v1tov2[u] < c) continue;
        for (int i = 1; i < n+1; i++)
        {
            if (node[u][i] < INF)
            {
                if (dist_v1tov2[i] > node[u][i] + c)
                {
                    dist_v1tov2[i] = node[u][i] + c;
                    pq3.push({dist_v1tov2[i], i});
                }
            }
        }
    }

    int ret = min(dist_1ton[v1]+dist_nto1[v2], dist_1ton[v2]+dist_nto1[v1]);
    if ((ret >= INF) || (dist_v1tov2[v2] == INF)) 
    {
        cout << -1; 
        return 0;
    }
    cout << ret + dist_v1tov2[v2];
}