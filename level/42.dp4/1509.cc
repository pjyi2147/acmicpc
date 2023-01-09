// acmicpc number: 1509
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = (a); i < (b); i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int MAXLEN = 2500;
bool pcnt[MAXLEN][MAXLEN];
int dp[MAXLEN];
string s;

void process(string &s)
{
    FOR(i, s.size())
    {
        pcnt[i][i] = true;
    }

    REP(j, 1, s.size())
    {
        FOR(i, s.size())
        {
            int next = i + j;
            if (next >= s.size())
                break;

            if (s[i] == s[next] && (j == 1 || pcnt[i + 1][next - 1]))
            {
                pcnt[i][next] = true;
            }
        }
    }
}

int solve(string &s)
{
    FOR(i, s.size())
    {
        dp[i] = i + 1;
    }

    REP(i, 1, s.size())
    {
        if (pcnt[0][i])
        {
            dp[i] = 1;
            continue;
        }

        REP(j, 1, i + 1)
        {
            if (pcnt[j][i])
            {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }

    return dp[s.size() - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    process(s);
    cout << solve(s);
}