// acmicpc number: 9663
#include <bits/stdc++.h>
using namespace std;

int solve(bool* p_q, int rem_q, int n);
int solve(int n);
bool find_col(bool* p_q, int pos, int n);
bool find_diag_r(bool* p_q, int pos, int n);
bool find_diag_l(bool* p_q, int pos, int n);

int main()
{
    int n;
    cin >> n;
    cout << solve(n) << "\n";
}

int solve(int n)
{
    bool* p_q = new bool[n*n];
    memset(p_q, 0, sizeof(bool)*n*n);
    return solve(p_q, n, n);
}

int solve(bool* p_q, int rem_q, int n)
{
    if (rem_q == 0) 
    {
        return 1;
    }

    int SOL = 0;
        
    for (int i = 0; i < n; i++)
    {
        int pos = n*(rem_q-1)+i;
        if (find_col(p_q, pos, n) 
            && find_diag_l(p_q, pos, n) 
            && find_diag_r(p_q, pos, n))
        {
            p_q[pos] = true;
            SOL += solve(p_q, rem_q-1, n);
            p_q[pos] = false;   
        }
    }
    return SOL;
}


bool find_col(bool* p_q, int pos, int n)
{
    int col = pos % n;
    int row = pos / n;
    for (int i = row+1; i < n; i++) 
    {
        if (p_q[i*n+col]) return false;
    }
    return true;
}

// 오른쪽 아래로
bool find_diag_r(bool* p_q, int pos, int n)
{
    int k = pos;
    while (k/n < n-1 && k % n != n-1)
    {
        k += (n+1);
    }

    while (k > pos && k % n != 0)
    {
        if (p_q[k]) return false;
        k -= (n+1);
    }
    return true;
}

// 왼쪽 아래로
bool find_diag_l(bool* p_q, int pos, int n)
{
    int k = pos;
    while (k/n < n-1 && k % n != 0)
    {
        k += (n-1);
    }

    while (k > pos && k % n != n-1)
    {
        if (p_q[k]) return false;
        k -= (n-1);
    }
    return true;
}
