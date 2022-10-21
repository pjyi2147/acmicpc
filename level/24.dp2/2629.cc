// acmicpc number: 2629
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;
int SHIFT = 15000;

ll solve(int q, ll k, vector<vector<ll>>& memo, const vector<int>& w) 
{
    if (abs(q) > SHIFT) return 0;

    int tmp_q = q + SHIFT;
    if (memo[k][tmp_q] != -1) return memo[k][tmp_q];

    memo[k][tmp_q] = 0;
    if (q == w[k] || q == -w[k]) return memo[k][tmp_q] = 1;
    if (k < n-1) {
        memo[k][tmp_q] += solve(q - w[k], k+1, memo, w) + solve(q + w[k], k+1, memo, w) + solve(q, k+1, memo, w);
        return (memo[k][tmp_q] > 0) ? memo[k][tmp_q] = 1 : memo[k][tmp_q] = 0;
    }
    return memo[k][tmp_q] = 0;
}

ll solve(int q, vector<vector<ll>>& memo, const vector<int>& w) 
{
    return solve(q, 0, memo, w);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> w(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    cin >> m;
    vector<vector<ll>> memo(n, vector<ll>(30001, -1));

    for (int i = 0; i < n; i++) {
        memo[i][SHIFT] = 1;
    }
    
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;

        if (solve(q, memo, w) > 0) cout << "Y ";
        else cout << "N "; 
    }
}