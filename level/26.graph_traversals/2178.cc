// acmicpc number: 2178
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m;

void solve(int x, int y, const vector<vector<bool>>& v, vector<vector<int>>& visited)
{
    visited[x][y] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        int offx[] = {0, 0, -1, 1};
        int offy[] = {-1, 1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            int px = u.first + offx[i];
            int py = u.second + offy[i];
            if (px < 0 || px >= m || py < 0 || py >= n) continue;
            if (visited[py][px] == 0 && v[py][px])
            {
                visited[py][px] = visited[u.second][u.first] + 1;
                q.push(make_pair(px, py));
                if (py == n-1 && px == m-1) return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    vector<vector<bool>> v(n, vector<bool>(m, false));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        char c;
        cin >> c;
        v[i][j] = c == '1';
    }
    solve(0, 0, v, visited);
    cout << visited[n-1][m-1];
}