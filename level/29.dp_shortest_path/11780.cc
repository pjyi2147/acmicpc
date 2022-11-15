// acmicpc number: 11780
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

int n, m;
constexpr int INF = 987654321;

void find_path(int i, int j, vector<int> &path, const vector<vector<int>> &dist, const vector<vector<int>> &route)
{
    if (route[i][j] == 0)
    {
        path.push_back(i);
        path.push_back(j);
        return;
    }

    find_path(i, route[i][j], path, dist, route);
    path.pop_back();
    find_path(route[i][j], j, path, dist, route);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> route(n + 1, vector<int>(n + 1, 0));
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
                    route[s][e] = p;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ((dist[i][j] == INF) ? 0 : dist[i][j]) << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || dist[i][j] == INF)
                cout << 0 << endl;
            else
            {
                vector<int> path;
                find_path(i, j, path, dist, route);
                cout << path.size() << " ";
                for (auto i : path)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
        }
    }
}