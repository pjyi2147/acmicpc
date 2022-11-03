// acmicpc number: 1956
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int v, e;
int INF = 987654321;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> v >> e;
    vector<vector<int>> dist(v, vector<int>(v, INF));

    for (int i = 0; i < e; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        dist[s - 1][e - 1] = min(c, dist[s - 1][e - 1]);
    }

    for (int p = 0; p < v; p++)
    {
        for (int a = 0; a < v; a++)
        {
            for (int b = 0; b < v; b++)
            {
                if (dist[a][b] > dist[a][p] + dist[p][b])
                {
                    dist[a][b] = dist[a][p] + dist[p][b];
                }
            }
        }
    }

    int ret = INF;
    for (int i = 0; i < v; i++)
    {
        for (int j = i; j < v; j++)
        {
            if (dist[i][j] == INF || dist[j][i] == INF)
                continue;
            if (i == j)
                ret = min(ret, dist[i][j]);
            else
                ret = min(ret, dist[i][j] + dist[j][i]);
        }
    }
    if (ret == INF)
        cout << -1;
    else
        cout << ret;
    return 0;
}