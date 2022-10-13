// acmicpc number: 10816
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    map<int, int> mapii;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mapii[x]++;
    }

    cin >> m;

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        cout << mapii[x] << " ";
    }
}