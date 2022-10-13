// acmicpc number: 1269
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    unordered_set <int> set;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        set.insert(x);
    }
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (set.find(x) != set.end()) cnt++;
    }
    cout << n + m - 2 * cnt;
}