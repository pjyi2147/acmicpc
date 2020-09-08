// acmicpc number: 2869
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int up, down, h;
    cin >> up >> down >> h;

    int one = up-down;
    h -= down;
    printf("%d", ((h - 1) / one) + 1);
}