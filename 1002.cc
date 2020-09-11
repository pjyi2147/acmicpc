// acmicpc number: 1002
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int x_diff = x1 - x2;
        int y_diff = y1 - y2;
        int r_diff = r1 - r2;

        if (x_diff == 0 && y_diff == 0) // 원 중심이 같음
        {
            if (r_diff == 0) // 반지름이 같음 
            {
                cout << -1 << "\n";
                continue;
            }
            cout << 0 << "\n";
            continue;
        }
        if (x_diff*x_diff+y_diff*y_diff==(r1+r2)*(r1+r2) ||
            x_diff*x_diff+y_diff*y_diff==(r1-r2)*(r1-r2))
        {
            cout << 1 << "\n";
            continue;
        }
        if (x_diff*x_diff+y_diff*y_diff>=(r1+r2)*(r1+r2) ||
            x_diff*x_diff+y_diff*y_diff<=(r1-r2)*(r1-r2))
        {
            cout << 0 << "\n";
            continue;
        }
        cout << 2 << "\n";
    }
    return 0;
}