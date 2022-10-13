// acmicpc number: 11047
#include <bits/stdc++.h>
using namespace std;

int n, v;
int coin[11];

int main()
{
    cin >> n >> v;
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    int start = n - 1;
    int coins = 0;
    while (v > 0)
    {
        if (coin[start] <= v)
        {
            coins += (v / coin[start]);
            v %= coin[start];
        }
        start--;
    }
    cout << coins;
}