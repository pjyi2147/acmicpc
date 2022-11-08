// acmicpc number: 11779
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m;
int INF = 987654321;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<pair<int, int>> node[1001];
    vector<int> dist(n+1, INF);
    vector<int> pred(n+1, -1);
    for (int i = 0; i < m; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        node[s].push_back({e, c});
    }
    int a, b;
    cin >> a >> b;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[a] = 0;
    pq.push({0, a});

    while (!pq.empty())
    {
        auto u = pq.top().second;
        auto c = pq.top().first;

        pq.pop();

        if (dist[u] < c) continue;

        for (auto naver: node[u])
        {
            if (dist[naver.first] > c + naver.second)
            {
                dist[naver.first] = c + naver.second;
                pred[naver.first] = u;
                pq.push({dist[naver.first], naver.first});
            }
        }
    }

    cout << dist[b] << '\n';
    int tmp = b;
    vector<int> path;
    while (tmp > -1)
    {
        path.push_back(tmp);
        tmp = pred[tmp];
    }
    cout << path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
}