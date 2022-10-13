// acmicpc number: 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        long long dist = y - x;
        long long pos = 1;
        long long turn = 1;
        long long power = 0;

        while (pos < dist)
        {
            power++;

            turn++;
            pos += power;
            if (pos >= dist) break;

            turn++;
            pos += power;
            if (pos >= dist) break;
        }
        if (pos > dist) turn--;
        printf("%lld\n", turn);
    }
    return 0;
}