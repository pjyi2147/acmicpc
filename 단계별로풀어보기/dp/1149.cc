// acmicpc number: 1149
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0; cin >> n;
    int h_cost[n][3];
    int h_memo[n][3];
    for (int i = 0; i < n; i++)
    {
        cin >> h_cost[i][0] >> h_cost[i][1] >> h_cost[i][2];
        h_memo[i][0] = h_cost[i][0];
        h_memo[i][1] = h_cost[i][1];
        h_memo[i][2] = h_cost[i][2]; 
    }

    for (int i = 1; i < n; i++)
    {
        h_memo[i][0] += min(h_memo[i-1][1], h_memo[i-1][2]);
        h_memo[i][1] += min(h_memo[i-1][0], h_memo[i-1][2]);
        h_memo[i][2] += min(h_memo[i-1][1], h_memo[i-1][0]); 
    }

    cout << min(h_memo[n-1][0], min(h_memo[n-1][1], h_memo[n-1][2]));
}