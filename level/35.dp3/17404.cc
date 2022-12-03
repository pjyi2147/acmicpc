// acmicpc number: 17404
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
constexpr int INF = 987654321;

void solve(const vector<vector<int>>& cost)
{
    int ret = INF;
    for (int first = 0; first < 3; first++)
    {
        vector<vector<int>> sol(n, vector<int>(3, INF));
        sol[0][first] = cost[0][first];

        for (int i = 1; i < n; i++)
        {
            sol[i][0] = min(sol[i - 1][1], sol[i - 1][2]) + cost[i][0];
            sol[i][1] = min(sol[i - 1][0], sol[i - 1][2]) + cost[i][1];
            sol[i][2] = min(sol[i - 1][0], sol[i - 1][1]) + cost[i][2];
        }

        for (int i = 0; i < 3; i++)
        {
            if (i != first)
                ret = min(ret, sol[n - 1][i]);
        }
    }
    cout << ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> cost[i][j];
        }
    }

    solve(cost);
}