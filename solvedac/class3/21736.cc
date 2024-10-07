// acmicpc number: 21736
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i=(a); i < (b); i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<int> vi;
typedef vector<vi> vii;

ll n, m;

int dfs(const vector<vector<char>>& campus,
        vector<vector<bool>>& visited, int y, int x)
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = { 0, 0, 1, -1};

    int ret = 0;
    visited[y][x] = true;
    if (campus[y][x] == 'P') ret++;
    FOR (i, 4)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
            campus[ny][nx] != 'X' && !visited[ny][nx])
        {
            ret += dfs(campus, visited, ny, nx);
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<vector<char>> campus(n, vector<char>(m, ' '));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int a, b;

    FOR (i, n)
    {
        FOR(j, m)
        {
            char c;
            cin >> c;
            campus[i][j] = c;
            if (campus[i][j] == 'I')
            {
                a = i;
                b = j;
            }
        }
    }
    int ret = dfs(campus, visited, a, b);
    if (ret == 0) cout << "TT";
    else cout << ret;
    return 0;
}
