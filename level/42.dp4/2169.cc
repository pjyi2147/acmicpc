// acmicpc number: 2169
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = (a); i < (b); i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int MAXN = 1001;
int val[MAXN][MAXN];
int dp[MAXN][MAXN];
ll n, m;

int solve()
{
    dp[0][0] = val[0][0];
    REP(i, 1, m)
    {
        dp[0][i] = dp[0][i - 1] + val[0][i];
    }

    REP(i, 1, n)
    {
        vector<vector<int>> temp(m, vector<int>(2, 0));
        FOR(j, m)
        {
            temp[j][0] = dp[i - 1][j] + val[i][j];
            temp[j][1] = dp[i - 1][j] + val[i][j];
        }

        REP(j, 1, m)
        {
            temp[j][0] = max(temp[j][0], temp[j - 1][0] + val[i][j]);
        }

        for (int j = m - 2; j >= 0; j--)
        {
            temp[j][1] = max(temp[j][1], temp[j + 1][1] + val[i][j]);
        }

        FOR(j, m)
        {
            dp[i][j] = max(temp[j][0], temp[j][1]);
        }
    }
    return dp[n - 1][m - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    FOR(i, n)
    FOR(j, m)
    {
        cin >> val[i][j];
    }
    cout << solve() << "\n";
}