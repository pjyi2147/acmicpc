// acmicpc number: 4948
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, MAX_I = 123456*2+1;
    bool* p = new bool[MAX_I];
    memset(p,1,sizeof(bool)*(MAX_I));

    p[1] = false;
    for (int i = 2; i*i <= MAX_I; i++)
    {
        if (p[i] == false) continue;
        for (int j = i*2; j <= MAX_I; j+=i) p[j] = false;
    }

    cin >> n;
    while (n != 0)
    {   
        int cnt = 0;
        for (int i = n+1; i <= 2*n; i++) {
            if (p[i]) cnt++;
        }
        cout << cnt << "\n";
        cin >> n;
    }
}