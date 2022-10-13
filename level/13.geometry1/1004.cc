// acmicpc number: 1004
#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    for (int i = 0; i < T; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int n;
        cin >> n;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int cx, cy, r;
            cin >> cx >> cy >> r;
            int d1 = (cx - x1) * (cx - x1) + (cy - y1) * (cy - y1);
            int d2 = (cx - x2) * (cx - x2) + (cy - y2) * (cy - y2);
            if (d1 < r * r && d2 > r * r) {
                cnt++;
            } else if (d1 > r * r && d2 < r * r) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
