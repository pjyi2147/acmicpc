// acmicpc number: 2579
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0; cin >> n;
    int s_value[n+1];
    int s_memo[n+1];
    memset(s_value, 0, sizeof(int)*(n+1));
    memset(s_memo, 0, sizeof(int)*(n+1));

    for (int i = 0; i < n; i++)
    {
        cin >> s_value[i];
        s_memo[i] = s_value[i];
    }

    s_memo[1] += s_memo[0];
    s_memo[2] += max(s_memo[0], s_value[1]);
    s_memo[3] += max(s_value[2]+s_memo[0],
                     s_value[1]+s_memo[0]);
    s_memo[4] += max(s_value[3]+s_memo[1], 
                         max(s_value[3]+s_value[1],
                             s_value[2]+s_memo[0]));
    
    for (int i = 5; i < n; i++)
    {
        s_memo[i] += max(s_value[i-1]+s_memo[i-3], 
                         max(s_value[i-2]+s_value[i-3]+s_memo[i-5],
                             s_value[i-2]+s_memo[i-4]));
    }

    cout << s_memo[n-1];
}