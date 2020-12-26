// acmicpc number: 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0; cin >> n;
    int t_2 = 1, t_1 = 1;

    for (int i = 1; i < n; i++)
    {
        int t = (t_2+t_1) % 15746;
        t_2 = t_1;
        t_1 = t;
    }
    cout << t_1;
}