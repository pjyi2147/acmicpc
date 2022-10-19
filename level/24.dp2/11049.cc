// acmicpc number: 11049
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

int solve(int s, int e, vector<vector<int>>& memo, const vector<pair<int, int>>& v) {
    if (memo[s][e] != -1) return memo[s][e];

    if (s + 1 == e) return memo[s][e] = v[s].first * v[s].second * v[e].second;

    memo[s][e] = INT32_MAX;
    for (int i = s; i < e; i++) {
        int tmp = solve(s, i, memo, v) + solve(i + 1, e, memo, v) + v[s].first * v[i].second * v[e].second;
        memo[s][e] = min(tmp, memo[s][e]);
    }
    return memo[s][e];
}

int solve(const vector<pair<int, int>>& v)
{
    vector<vector<int>> memo(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        memo[i][i] = 0;
    }
    return solve(0, v.size() - 1, memo, v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        v[i] = make_pair(r, c);
    }
    
    cout << solve(v) << "\n";
}