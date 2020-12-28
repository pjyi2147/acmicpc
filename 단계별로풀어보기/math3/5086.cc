// acmicpc number: 5086
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    while (!(a == 0 && b == 0))
    {
        if (a > b) (a % b == 0 ? cout << "multiple\n" : cout << "neither\n");
        else (b % a == 0 ? cout << "factor\n" : cout << "neither\n");
        cin >> a >> b;
    }
}