// acmicpc number: 13392
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = (a); i < (b); i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int dp[10003][10];
int cur[10003];
int des[10003];
ll n;

int solve()
{
    FOR(i, 10)
    {
        dp[0][i] = i;
    }

    REP(i, 1, n + 1)
    FOR(j, 10)
    {
        int ldist = (des[i-1] - j - cur[i-1] + 20) % 10;
        int rdist = (10 - ldist) % 10;
        // left
        int leftidx = (j + ldist) % 10;
        dp[i][leftidx] = min(dp[i][leftidx], dp[i - 1][j] + ldist);
        // right
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + rdist);
    }

    int ret = INT_MAX;
    FOR(i, 10)
    {
        ret = min(ret, dp[n][i]);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    FOR(i, 10002)
    FOR(j, 10)
    {
        dp[i][j] = 200000;
    }

    cin >> n;
    FOR(i, n)
    {
        char c;
        cin >> c;
        cur[i] = c - '0';
    }
    FOR(i, n)
    {
        char c;
        cin >> c;
        des[i] = c - '0';
    }
    cout << solve();
}