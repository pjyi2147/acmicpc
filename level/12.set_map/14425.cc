// acmicpc number: 14425
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    set<string> s;
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        s.insert(x);
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        string x;
        cin >> x;
        ans += s.count(x);
    }
    cout << ans;
}