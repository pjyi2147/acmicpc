// acmicpc number: 11404
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
    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));

    for (int i = 0; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        dist[s][e] = min(c, dist[s][e]);
    }

    for (int p = 1; p <= n; p++)
    {
        for (int s = 1; s <= n; s++)
        {
            for (int e = 1; e <= n; e++)
            {
                if (dist[s][e] > dist[s][p] + dist[p][e])
                {
                    dist[s][e] = dist[s][p] + dist[p][e];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            
            if (dist[i][j] == INF) cout << 0;
            else cout << dist[i][j];
            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}