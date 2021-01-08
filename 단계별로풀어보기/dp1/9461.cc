// acmicpc number: 9461
#include <bits/stdc++.h>
using namespace std;

long long Seq[110] = {1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12};

int main()
{
    int n = 0; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t = 0; cin >> t;
        for (int j = 5; j < t; j++)
        {
            if (Seq[j] == 0) Seq[j] = Seq[j-1]+Seq[j-5];
        }
        cout << Seq[t-1] << "\n";
    }
}