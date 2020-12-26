// acmicpc number: 10844
#include <bits/stdc++.h>
using namespace std;

int BIG_NUM = 1000000000;

int main()
{
    int n = 0; cin >> n;
    int n_value[n][10];
    long long n_memo[n][10];
    for (int j = 0; j < 10; j++)
    {
        if (j == 0) n_value[0][j] = 0;
        else n_value[0][j] = 1;
        n_memo[0][j] = n_value[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0) n_memo[i][j] = n_memo[i-1][j+1];
            else if (j == 9) n_memo[i][j] = n_memo[i-1][j-1];
            else n_memo[i][j] = (n_memo[i-1][j+1] + n_memo[i-1][j-1]) % BIG_NUM;
        }
    }
    
    long long sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += n_memo[n-1][i];
    }
    cout << (sum % BIG_NUM);
}