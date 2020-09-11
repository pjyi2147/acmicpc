// acmicpc number: 1978
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int k; cin >> k;
        bool p = true;
        if (k == 1) continue;
        for (int j = 2; j*j <= k; j++)
        {
            if (k % j == 0) 
            {
                p = false;
                continue;
            }
        }
        if (p) cnt++;
    }

    cout << cnt << "\n";
}