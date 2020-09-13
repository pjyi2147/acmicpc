// acmicpc number: 
#include <bits/stdc++.h>
using namespace std;

int MAX = 2187;
char star[2187][2187];

void sol(int N);
void sol(int x, int y, int loc, int N);

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            star[i][j] = ' ';
        }
    }

    sol(N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) putchar(star[i][j]);
        putchar('\n');
    }
}

void sol(int N)
{
    sol(0, 0, 0, N);
}

void sol(int x, int y, int loc, int N)
{
    if (loc == 5) return;
    if (N == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++) 
            {
                if (!(i == 1 && j == 1)) star[y+i][x+j] = '*';
            }
        }
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) 
        {
            sol(x+(N/3)*i, y+(N/3)*j, 3*i+(j+1), N/3);
        }
    }
}