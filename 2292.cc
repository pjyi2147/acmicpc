// acmicpc number: 2292
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, i = 1;
    cin >> N;
    
    int k = 3*(i-1)*(i-1)+3*(i-1)+1;
    while (N > k) {
        i++;
        k = 3*(i-1)*(i-1)+3*(i-1)+1;
    }

    cout << i << '\n';
}