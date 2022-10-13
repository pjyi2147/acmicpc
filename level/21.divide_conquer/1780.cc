// acmicpc number: 1780
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& v, int x, int y, int size, int& a, int& b, int& c) {
    if (size == 1) {
        if (v[x][y] == -1) {
            a++;
        } else if (v[x][y] == 0) {
            b++;
        } else {
            c++;
        }
        return;
    }

    int m = size / 3;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (v[x][y] != v[i][j]) {
                solve(v, x, y, m, a, b, c);
                solve(v, x, y + m, m, a, b, c);
                solve(v, x, y + 2 * m, m, a, b, c);
                solve(v, x + m, y, m, a, b, c);
                solve(v, x + m, y + m, m, a, b, c);
                solve(v, x + m, y + 2 * m, m, a, b, c);
                solve(v, x + 2 * m, y, m, a, b, c);
                solve(v, x + 2 * m, y + m, m, a, b, c);
                solve(v, x + 2 * m, y + 2 * m, m, a, b, c);
                return;
            }
        }
    }

    if (v[x][y] == -1) {
        a++;
    } else if (v[x][y] == 0) {
        b++;
    } else {
        c++;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    int a = 0, b = 0, c = 0;
    solve(v, 0, 0, n, a, b, c);
    cout << a << '\n' << b << '\n' << c << '\n';
}
