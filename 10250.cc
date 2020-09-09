// acmicpc number: 10250
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int w, h, cus;
        cin >> h >> w >> cus;
        int floor = cus % h;
        if (floor == 0) floor = h;
        int num = (cus+h-1) / h;

        cout << floor;
        if (num < 10) cout << '0';
        cout << num << '\n';
    }

    return 0;
}