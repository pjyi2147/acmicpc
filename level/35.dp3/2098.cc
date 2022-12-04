// acmicpc number: 2098
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
int cost[16][16];
int dp[16][1 << 16];
constexpr int INF = 987654321;

int solve(int x, int visited)
{
    if (visited == (1 << n) - 1)
    {
        if (cost[x][0] != 0)
            return cost[x][0];
        else
            return INF;
    }

    if (dp[x][visited] != -1)
        return dp[x][visited];

    dp[x][visited] = INF;
    for (int i = 0; i < n; i++)
    {
        if (visited & (1 << i) || cost[x][i] == 0)
            continue;

        int tmp = solve(i, visited | (1 << i));
        if (tmp < INF) dp[x][visited] = min(dp[x][visited], tmp + cost[x][i]);
    }
    return dp[x][visited];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }
    memset(dp, -1, sizeof(int) * 16 * (1 << 16));
    cout << solve(0, 1);
}