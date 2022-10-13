// acmicpc number: 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 1, y = 1, z = 1;
    while (true)
    {
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0) return 0;
        if (x*x == y*y + z*z ||
            y*y == x*x + z*z ||
            z*z == y*y + x*x) cout << "right\n";
        else cout << "wrong\n";
    }

    return 0;
}