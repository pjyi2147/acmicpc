// acmicpc number: 7562
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int l, T;

void solve(int x, int y, int dx, int dy, vector<vector<int>> &visited)
{
    visited[y][x] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        int xoff[] = {-1, -1, 1, 1, -2, -2, 2, 2};
        int yoff[] = {2, -2, 2, -2, -1, 1, -1, 1};

        for (int i = 0; i < 8; i++)
        {
            int py = u.first + yoff[i];
            int px = u.second + xoff[i];
            if (px < 0 || px >= l || py < 0 || py >= l)
                continue;
            if (visited[py][px] == -1)
            {
                visited[py][px] = visited[u.first][u.second] + 1;
                if (px == dx && py == dy) break;
                q.push(make_pair(py, px));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> l;
        vector<vector<int>> visited(l, vector<int>(l, -1));
        int x, y, dx, dy;
        cin >> x >> y >> dx >> dy;
        solve(x, y, dx, dy, visited);
        cout << visited[dy][dx] << '\n';
    }
}