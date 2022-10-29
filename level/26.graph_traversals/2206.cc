// acmicpc number: 2206
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m;
struct p
{
    int x, y;
    bool b;
    p(int y, int x, bool b) : y{y}, x{x}, b{b} {}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    if (n == 1 && m == 1)
    {
        char c;
        cin >> c;
        (c == '0') ? cout << 1 : cout << -1;
        return 0;
    }

    vector<vector<bool>> mp(n, vector<bool>(m, false));
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2, -1)));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            mp[i][j] = (c == '1');
        }

    queue<p> q;
    visited[0][0][0] = 1;
    visited[0][0][1] = 1;
    q.push(p(0, 0, true));

    int xoff[] = {0, 0, -1, 1};
    int yoff[] = {-1, 1, 0, 0};

    while (!q.empty())
    {
        auto u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int px = u.x + xoff[i];
            int py = u.y + yoff[i];

            if (px < 0 || px >= m || py < 0 || py >= n)
                continue;
            if (mp[py][px] == 0 && visited[py][px][u.b] == -1)
            {
                visited[py][px][u.b] = visited[u.y][u.x][u.b] + 1;
                if (px == m - 1 && py == n - 1)
                {
                    cout << visited[py][px][u.b];
                    return 0;
                }
                q.push(p(py, px, u.b));
            }

            if (u.b && mp[py][px] == 1)
            {
                for (int j = 0; j < 4; j++)
                {
                    int pbx = px + xoff[j];
                    int pby = py + yoff[j];

                    if (pbx < 0 || pbx >= m || pby < 0 || pby >= n)
                        continue;
                    if (mp[pby][pbx] != 0 || visited[pby][pbx][0] != -1)
                        continue;
                    visited[pby][pbx][0] = visited[u.y][u.x][u.b] + 2;
                    if (pbx == m - 1 && pby == n - 1)
                    {
                        cout << visited[pby][pbx][0];
                        return 0;
                    }
                    q.push(p(pby, pbx, false));
                }
            }
        }
    }
    cout << -1;
    return 0;
}