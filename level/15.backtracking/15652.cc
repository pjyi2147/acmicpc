// acmicpc number: 15652
#include <bits/stdc++.h>
using namespace std;

void backtrack(int n, int m, int step, string st, int l_n)
{
    if (step == m)
    {
        cout << st << "\n";
        return;
    }

    for (int i = l_n; i < n; i++)
    {
        string copy = string(st);
        copy.append(to_string(i + 1));
        copy.append(" ");
        backtrack(n, m, step + 1, copy, i);
    }
}

void backtrack(int n, int m)
{
    backtrack(n, m, 0, "", 0);
}

int main()
{
    int m, n;
    cin >> n >> m;
    backtrack(n, m);
}