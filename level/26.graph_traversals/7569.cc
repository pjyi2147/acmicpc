// acmicpc number: 7569
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m, h;

struct to {
    int x, y, z;
    to(int a, int b, int c) : y{a}, x{b}, z{c} {}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> h;

    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(h, -1)));
    vector<vector<vector<int>>> status(n, vector<vector<int>>(m, vector<int>(h, -1)));
    int days = 0;
    
    queue<to> q;
    for (int k = 0; k < h; k++) for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        cin >> status[i][j][k];
        if (status[i][j][k] == 1) {
            visited[i][j][k] = 0;
            q.push(to(i, j, k));
        }
    }

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        int xoff[] = {-1, 1, 0, 0, 0, 0};
        int yoff[] = { 0, 0,-1, 1, 0, 0};
        int zoff[] = { 0, 0, 0, 0,-1, 1};
        for (int i = 0; i < 6; i++)
        {
            int px = u.x + xoff[i];
            int py = u.y + yoff[i];
            int pz = u.z + zoff[i];

            if (px < 0 || px >= m || py < 0 || py >= n || pz < 0 || pz >= h) continue;
            if (visited[py][px][pz] == -1 && status[py][px][pz] == 0)
            {
                visited[py][px][pz] = visited[u.y][u.x][u.z] + 1;
                days = max(days, visited[py][px][pz]);
                q.push(to(py, px, pz));
            }
        }
    }
    
    for (int k = 0; k < h; k++) for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (visited[i][j][k] == -1 && status[i][j][k] == 0) {
            cout << -1;
            return 0;
        }
    }
    cout << days;
    return 0;
}