// acmicpc number: 11660
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            if (i > 0) {
                v[i][j] += v[i - 1][j];
            }
            if (j > 0) {
                v[i][j] += v[i][j - 1];
            }
            if (i > 0 && j > 0) {
                v[i][j] -= v[i - 1][j - 1];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        int ans = v[x2][y2];
        if (x1 > 0) {
            ans -= v[x1 - 1][y2];
        }
        if (y1 > 0) {
            ans -= v[x2][y1 - 1];
        }
        if (x1 > 0 && y1 > 0) {
            ans += v[x1 - 1][y1 - 1];
        }
        cout << ans << '\n';
    }
}
