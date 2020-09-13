// acmicpc number: 1018 
#include <bits/stdc++.h>
using namespace std;

int solve(int y, int x, int m, char* chess_b)
{
    int ret1 = 0, ret2 = 0;
    for (int i = y; i < y+8; i++)
    {
        for (int j = x; j < x+8; j++)
        {
            int loc = i+j-x-y;
            if (loc % 2 && chess_b[i*m+j] == 'B') ret1++;
            else if (loc % 2 == 0 && chess_b[i*m+j] == 'W') ret1++;
        }
    }

    for (int i = y; i < y+8; i++)
    {
        for (int j = x; j < x+8; j++)
        {
            int loc = i+j-x-y;
            if (loc % 2 && chess_b[i*m+j] == 'W') ret2++;
            else if (loc % 2 == 0 && chess_b[i*m+j] == 'B') ret2++;
        }
    }
    return (ret1 < ret2) ? ret1 : ret2;
}

int main()
{
    int m, n;
    cin >> n >> m;
    char* chess_b = new char[n*m];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            chess_b[m*i+j] = s[j];
        }
    }
    int mini = 64;
    for (int i = 0; i < n - 7; i++)
    {
        for (int j = 0; j < m - 7; j++)
        {
            int temp = solve(i, j, m, chess_b);
            if (temp < mini) mini = temp;
        }
    }
    cout << mini << "\n";
}