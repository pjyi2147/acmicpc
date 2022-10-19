// acmicpc number: 10942
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

int solve(int s, int e, vector<vector<int>>& memo, const vector<int>& v) {
    if (s > e) return 1;

    if (memo[s][e] != -1) {
        return memo[s][e];
    }
    
    if (v[s] == v[e]) {
        memo[s][e] = solve(s+1, e-1, memo, v);
        return memo[s][e];
    }

    memo[s][e] = 0;
    return memo[s][e];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++) {
        memo[i][i] = 1;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;
        cout << solve(s - 1, e - 1, memo, v) << '\n';
    }
    return 0;
}