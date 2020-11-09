// acmicpc number: 15651
#include <bits/stdc++.h>
using namespace std;

void backtrack(int n, int m, int step, string st)
{
    if (step == m)
    {
        cout << st << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        string copy = string(st);
        copy.append(to_string(i + 1));
        copy.append(" ");
        backtrack(n, m, step + 1, copy);
    }
}

void backtrack(int n, int m)
{
    backtrack(n, m, 0, "");
}

int main()
{
    int m, n;
    cin >> n >> m;
    backtrack(n, m);
}