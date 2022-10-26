// acmicpc number: 1012
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int T, n, m, k;

struct Compg
{
    bool operator()(int a, int b) { return a > b; }
} compg;

void setfire(int x, int y, const vector<vector<bool>> &v, vector<vector<bool>> &visited)
{
    visited[y][x] = true;
    int offx[] = {0, 0, -1, 1};
    int offy[] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++)
    {
        int px = x + offx[i];
        int py = y + offy[i];
        if (px < 0 || px >= m || py < 0 || py >= n)
            continue;

        if (v[py][px] && !visited[py][px])
        {
            setfire(px, py, v, visited);
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
        cin >> m >> n >> k;

        vector<vector<bool>> v(n, vector<bool>(m, false));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            v[y][x] = true;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] && !visited[i][j])
                {
                    cnt++;
                    setfire(j, i, v, visited);
                }
            }
        }
        cout << cnt << "\n";
    }
}