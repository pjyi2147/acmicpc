// acmicpc number: 11659
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<int> v(n);
    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i == 0) {
            s[i] = v[i];
        } else {
            s[i] = s[i - 1] + v[i];
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << s[b - 1] - (a == 1 ? 0 : s[a - 2]) << '\n';
    }
    return 0;
}