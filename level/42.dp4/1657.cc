// acmicpc number: 1657
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
int dp[15 * 15][(1 << 14)];
int tofu[196];

int score(char a, char b)
{
    if (a > b)
        swap(a, b);
    if (a == 'A')
    {
        if (b == 'A')
            return 10;
        if (b == 'B')
            return 8;
        if (b == 'C')
            return 7;
        if (b == 'D')
            return 5;
        if (b == 'F')
            return 1;
    }
    else if (a == 'B')
    {
        if (b == 'B')
            return 6;
        if (b == 'C')
            return 4;
        if (b == 'D')
            return 3;
        if (b == 'F')
            return 1;
    }
    else if (a == 'C')
    {
        if (b == 'C')
            return 3;
        if (b == 'D')
            return 2;
        if (b == 'F')
            return 1;
    }
    else if (a == 'D')
    {
        if (b == 'D')
            return 2;
        if (b == 'F')
            return 1;
    }
    else
        return 0;
    return 0;
}

int solve(int idx, int stat)
{
    if (dp[idx][stat] != -1)
    {
        return dp[idx][stat];
    }
    if (idx == n * m && stat == 0)
        return 0;
    if (idx >= n * m && stat != 0)
        return -1e9;

    int &ret = dp[idx][stat];
    ret = 0;
    ret = max(ret, solve(idx + 1, stat >> 1));
    if (stat & 1)
    {
        ret = max(ret, solve(idx + 1, stat >> 1));
    }
    else
    {
        if ((idx % m) < m - 1 && (stat & (1 << 1)) == 0)
        {
            int s1 = score(tofu[idx], tofu[idx + 1]);
            ret = max(ret, solve(idx + 2, stat >> 2) + s1);
        }
        if (idx + m < n * m)
        {
            int s2 = score(tofu[idx], tofu[idx + m]);
            ret = max(ret, solve(idx + 1, (stat >> 1) | (1 << (m - 1))) + s2);
        }
    }
    return dp[idx][stat];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    FOR(i, n * m)
    {
        char c;
        cin >> c;
        tofu[i] = c;
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0);
}