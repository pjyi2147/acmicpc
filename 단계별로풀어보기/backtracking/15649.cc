// acmicpc number: 15649
#include <bits/stdc++.h>
using namespace std;

void backtrack(int n, int m, bool* check, int step, string st)
{
    if (step == m)
    {
        cout << st << "\n";
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (!check[i]) 
        {
            check[i] = true;
            string copy = string(st);
            copy.append(to_string(i+1));
            copy.append(" ");
            backtrack(n, m, check, step+1, copy);
            check[i] = false;
        }
    }
}

void backtrack(int n, int m)
{
    bool* check = new bool[n];
    memset(check, 0, n*sizeof(bool));
    backtrack(n, m, check, 0, "");
}

int main()
{
    int m, n;
    cin >> n >> m;
    backtrack(n, m);
}