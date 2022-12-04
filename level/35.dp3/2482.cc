// acmicpc number: 2482
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, k;
constexpr int MOD = 1000000003;

void solve()
{
    if (k > n / 2)
    {
        cout << 0;
        return;
    }

    vector<vector<int>> sol(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        sol[i][0] = 1;
        sol[i][1] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            sol[i][j] = (sol[i - 2][j - 1] + sol[i - 1][j]) % MOD;
        }
    }
    cout << (sol[n - 3][k - 1] + sol[n - 1][k]) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    solve();
}