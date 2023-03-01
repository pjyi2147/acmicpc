// acmicpc number: 1648
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = (a); i < (b); i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<int> vi;
typedef vector<vi> vii;

ll n, m;
int dp[196][(1 << 14) - 1];

int solve(int idx, int stat)
{
    if (idx >= n * m)
    {
        if (idx == n * m && stat == 0)
            return 1;
        return 0;
    }
    if (dp[idx][stat] > -1)
    {
        return dp[idx][stat];
    }

    int ret = 0;
    if (stat & 1)
    {
        return solve(idx + 1, stat >> 1);
    }
    if ((idx % m) < m - 1 && (stat & (1 << 1)) == 0)
    {
        ret += solve(idx + 2, stat >> 2);
    }
    ret += solve(idx + 1, (stat >> 1) | (1 << (m - 1)));
    ret %= 9901;
    return dp[idx][stat] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    if (n % 2 && m % 2)
    {
        cout << 0;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0);
}