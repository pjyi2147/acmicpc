// acmicpc number: 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0; cin >> n;
    int* t_value[n];
    int* t_memo[n];

    for (int i = 0; i < n; i++)
    {
        t_value[i] = new int[i+1];
        t_memo[i] = new int[i+1];
        for (int j = 0; j < i+1; j++)
        {
            cin >> t_value[i][j];
            t_memo[i][j] = t_value[i][j];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < i+1; j++)
        {
            t_memo[i][j] += max(t_memo[i+1][j], t_memo[i+1][j+1]);
        }
    }

    cout << t_memo[0][0];
}