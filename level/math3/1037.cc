// acmicpc number: 1037
#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin >> n;
    vector<int> fac;
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        fac.push_back(k);
    }
    sort(fac.begin(), fac.end());
    cout << fac[0] * fac[n-1];
}