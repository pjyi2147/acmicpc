// acmicpc number: 2446
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j%2 == 0) 
            {
                putchar('*');
                if (j == n-1) putchar('\n');
            }
            else 
            { 
                if (j == n-1) putchar('\n');
                else putchar(' ');
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (j%2) 
            {
                putchar('*');
                if (j == n-1) putchar('\n');
            }
            else 
            { 
                if (j == n-1) putchar('\n');
                else putchar(' ');
            }
        }    
    }
}