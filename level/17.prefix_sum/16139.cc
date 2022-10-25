// acmicpc number: 16139
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    vector<vector<int>> v(s.size(), vector<int>(26, 0));
    for (int i = 0; i < s.size(); i++) {
        v[i][s[i] - 'a']++;
        for (int j = 0; j < 26; j++) {
            if (i > 0) {
                v[i][j] += v[i - 1][j];
            }
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        int cnt = 0;
        if (l > 0) {
            cnt = v[r][c - 'a'] - v[l - 1][c - 'a'];
        } else {
            cnt = v[r][c - 'a'];
        }
        cout << cnt << '\n';
    }
}