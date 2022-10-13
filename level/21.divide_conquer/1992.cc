// acmicpc number: 1992
#include <bits/stdc++.h>
using namespace std;

int n;

string solve(vector<vector<int>> &v, int x, int y, int size) {
    if (size == 1) {
        return to_string(v[x][y]);
    }

    string s = "";
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (v[x][y] != v[i][j]) {
                s += "(";
                s += solve(v, x, y, size / 2);
                s += solve(v, x, y + size / 2, size / 2);
                s += solve(v, x + size / 2, y, size / 2);
                s += solve(v, x + size / 2, y + size / 2, size / 2);
                s += ")";
                return s;
            }
        }
    }
    return to_string(v[x][y]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j)
        {
            v[i][j] = s[j] - '0';
        }
    }
    cout << solve(v, 0, 0, n) << endl;

    return 0;
}