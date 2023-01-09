// acmicpc number: 2494
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = (a); i < (b); i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
pii dp[10002][10];
string cur, des;

void solve()
{
    FOR(i, 10)
    {
        dp[0][i].first = i;
    }

    REP(i, 1, n + 1)
    FOR(j, 10)
    {
        int curn = (cur[i - 1] - '0') % 10;
        int desn = (des[i - 1] - '0') % 10;

        int leftcnt = (desn - j - curn + 20) % 10;
        int rightcnt = (10 - leftcnt) % 10;

        // right
        if (dp[i][j].first > dp[i - 1][j].first + rightcnt)
        {
            dp[i][j].first = dp[i - 1][j].first + rightcnt;
            dp[i][j].second = -rightcnt;
        }

        // left
        if (dp[i][(j + leftcnt) % 10].first > dp[i - 1][j].first + leftcnt)
        {
            dp[i][(j + leftcnt) % 10].first = dp[i - 1][j].first + leftcnt;
            dp[i][(j + leftcnt) % 10].second = leftcnt;
        }
    }

    int ret = INT_MAX;
    int idx = 0;
    FOR(i, 10)
    {
        if (ret > dp[n][i].first)
        {
            ret = dp[n][i].first;
            idx = i;
        }
    }

    cout << ret << '\n';
    stack<int> st;

    for (int i = n; i > 0; i--)
    {
        int cnt = dp[i][idx].second;
        st.push(cnt);
        if (cnt > 0)
        {
            idx = (idx - cnt + 20) % 10;
        }
    }

    int i = 1;
    while (!st.empty())
    {
        cout << i << " " << st.top() << "\n";
        i++;
        st.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    FOR(i, 10002)
    FOR(j, 10)
    {
        dp[i][j].first = 200001;
    }
    cin >> cur >> des;
    solve();
}