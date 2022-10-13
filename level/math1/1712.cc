// acmicpc number: 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int fix, flex_c, price;
    cin >> fix >> flex_c >> price;

    if (flex_c >= price) {
        cout << -1 << "\n";
        return 0;
    }
    cout << fix / (price-flex_c) + 1 << "\n";
}