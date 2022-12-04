// acmicpc number: 1311
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
constexpr int INF = 987654321;

int dfs(int x, int visited, vector<vector<int>>& dp, const vector<vector<int>>& cost)
{
    if (visited == (1 << n) - 1)
    {
        return 0;
    }
    if (dp[x][visited] != -1)
        return dp[x][visited];

    dp[x][visited] = INF;
    for (int i = 0; i < n; i++)
    {
        if (visited & (1 << i)) continue;

        dp[x][visited] = min(dp[x][visited], dfs(x + 1, visited | (1 << i), dp, cost) + cost[x][i]);
    }
    return dp[x][visited];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n, 0));
    vector<vector<int>> dp(n + 1, vector<int>(1 << n, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }

    cout << dfs(0, 0, dp, cost);
}