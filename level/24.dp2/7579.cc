// acmicpc number: 7579
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;

int solve(const vector<int>& c, const vector<int>& mem)
{
    ll ret = 0;
    int cost_sum = 0;
    for (int i = 0; i < n; i++)
    {
        cost_sum += c[i];
    }
    vector<vector<int>> memo(n, vector<int>(cost_sum + 1, 0));
    for (int j = c[0]; j <= cost_sum; j++)
    {
        memo[0][j] = mem[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= cost_sum; j++) 
        {
            memo[i][j] = memo[i-1][j];
            if (j >= c[i]) memo[i][j] = max(memo[i][j], memo[i-1][j - c[i]] + mem[i]);
        }
    }

    for (int i = 0; i <= cost_sum; i++)
    {
        if (memo[n-1][i] >= m) {
            ret = i;
            break;
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
    vector<int> mem(n, 0);
    vector<int> c(n, 0);
    for (int i = 0; i < n; i++) 
    {
        cin >> mem[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    cout << solve(c, mem);
}