// acmicpc number: 2446
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++) putchar(' ');
        for (int j = 0; j < 2*n-2*i-1; j++) putchar('*');
        putchar('\n');
    }
    for (int i = n-2; i >= 0; i--)
    {
        for (int j = 0; j < i; j++) putchar(' ');
        for (int j = 0; j < 2*n-2*i-1; j++) putchar('*');
        if(n!=0) putchar('\n');
    }
}