// acmicpc number: 1520
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll m, n;

ll solve(ll y, ll x, vector<vector<int>>& memo, const vector<vector<int>>& v)
{
    if (memo[y][x] != -1) return memo[y][x];

    memo[y][x] = 0;
    int dx[] = {1, -1, 0,  0};
    int dy[] = {0,  0, 1, -1};
    for (int i = 0; i < 4; i++)
    {
        int px = x + dx[i];
        int py = y + dy[i];
        if (py < 0 || py >= m || px < 0 || px >= n) continue;

        if (v[py][px] > v[y][x]) memo[y][x] += solve(py, px, memo, v);
    }

    return memo[y][x];
}

ll solve(const vector<vector<int>>& v) 
{
    vector<vector<int>> memo(m, vector<int>(n, -1));
    memo[0][0] = 1;
    return solve(m-1, n-1, memo, v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    cout << solve(v);
}