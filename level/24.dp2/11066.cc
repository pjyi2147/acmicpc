// acmicpc number: 11066
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, t;

ll solve(int s, int e, const vector<int>& v, vector<vector<ll>>& memo_cost, const vector<vector<ll>>& memo_size) {
    if (memo_cost[s][e] != -1) return memo_cost[s][e];
    memo_cost[s][e] = INT64_MAX;
    for (int i = s; i < e; i++) {
        memo_cost[s][e] = min(memo_cost[s][e], memo_size[s][i] + memo_size[i + 1][e] + solve(s, i, v, memo_cost, memo_size) + solve(i+1, e, v, memo_cost, memo_size));
    }
    return memo_cost[s][e];
}

ll solve(const vector<int>& v, vector<vector<ll>>& memo_cost, vector<vector<ll>>& memo_size) {
    int k = memo_cost.size();
    for (int i = 0; i < k; i++) {
        memo_cost[i][i] = 0;
        memo_size[i][i] = v[i];
        for (int j = i+1; j < k; j++) {
            memo_size[i][j] = memo_size[i][j-1] + v[j];
        }
    }
    return solve(0, k-1, v, memo_cost, memo_size);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> v(n, 0);
        vector<vector<ll>> memo_cost(n, vector<ll>(n, -1));
        vector<vector<ll>> memo_size(n, vector<ll>(n, -1));
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        cout << solve(v, memo_cost, memo_size) << '\n';
    }
}