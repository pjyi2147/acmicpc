// acmicpc number: 1358
#include <bits/stdc++.h>
using namespace std;

int w, h, x, y, p;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> w >> h >> x >> y >> p;

    int cnt = 0;
    for (int i = 0; i < p; i++) {
        int px, py;
        cin >> px >> py;

        px -= x;
        py -= y;

        if (px >= 0 && px <= w && py >= 0 && py <= h) {
            cnt++;
        }
        else if (px < 0 && px >= -(h/2) && py > 0 && py < h) {
            int d = px * px + (py - h / 2) * (py - h / 2);
            if (d <= (h / 2) * (h / 2)) cnt++;
        }
        else if (px > w && px <= w + h / 2 && py > 0 && py < h) {
            int d = (px - w) * (px - w) + (py - h / 2) * (py - h / 2);
            if (d <= (h / 2) * (h / 2)) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}