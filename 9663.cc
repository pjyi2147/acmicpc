// acmicpc number: 9663
#include <bits/stdc++.h>
using namespace std;

int solve(bool* p_col, bool* p_d_r, bool* p_d_l, int rem_q, int n);
int solve(int n);

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << "\n";
}

int solve(int n)
{
    bool* p_col = new bool[n];
    bool* p_d_r = new bool[n*2-1];
    bool* p_d_l = new bool[n*2-1];
    memset(p_col, 1, sizeof(bool)*n);
    memset(p_d_r, 1, sizeof(bool)*(n*2-1));
    memset(p_d_l, 1, sizeof(bool)*(n*2-1));
    return solve(p_col, p_d_r, p_d_l, 0, n);
}

int solve(bool* p_col, bool* p_d_r, bool* p_d_l, int q, int n)
{
    if (q == n) 
    {
        return 1;
    }

    int SOL = 0;
        
    for (int i = 0; i < n; i++)
    {
        int dr = q+i;
        int dl = i-q+(n-1);
        if (p_col[i] 
            && p_d_r[dr] 
            && p_d_l[dl])
        {
            p_col[i] = false;
            p_d_r[dr] = false;
            p_d_l[dl] = false;
            SOL += solve(p_col, p_d_r, p_d_l, q+1, n);
            p_col[i] = true;
            p_d_r[dr] = true;
            p_d_l[dl] = true;
        }
    }
    return SOL;
}