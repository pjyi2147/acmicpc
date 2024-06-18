// acmicpc number: 11724
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

void dfs(const vector<vector<bool>>& grid, vector<bool>& visited, int cur)
{
    FOR(i, n)
    {
        if (grid[cur][i] && !visited[i])
        {
            visited[i] = true;
            dfs(grid, visited, i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<vector<bool>> grid(n, vector<bool>(n, false));
    vector<bool> visited(n, false);

    FOR (i, m)
    {
        int a, b;
        cin >> a >> b;
        grid[a - 1][b - 1] = true;
        grid[b - 1][a - 1] = true;
    }

    int cnt = 0;
    FOR(i, n)
    {
        if (!visited[i])
        {
            cnt++;
            visited[i] = true;
            dfs(grid, visited, i);
        }
    }
    cout << cnt;
}
