// acmicpc number: 7576
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;

    vector<vector<int>> visited(n, vector<int>(m, -1));
    vector<vector<int>> status(n, vector<int>(m, -1));
    int days = 0;
    
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> status[i][j];
            if (status[i][j] == 1) {
                visited[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        int xoff[] = {-1, 1, 0, 0};
        int yoff[] = { 0, 0,-1, 1};

        for (int i = 0; i < 4; i++)
        {
            int px = u.second + xoff[i];
            int py = u.first + yoff[i];

            if (px < 0 || px >= m || py < 0 || py >= n) continue;
            if (visited[py][px] == -1 && status[py][px] == 0)
            {
                visited[py][px] = visited[u.first][u.second] + 1;
                days = max(days, visited[py][px]);
                q.push(make_pair(py, px));
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == -1 && status[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << days;
    return 0;
}