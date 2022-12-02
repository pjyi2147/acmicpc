// acmicpc number: 7869
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    cout << setprecision(3) << fixed;
    if (r1 < r2)
    {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }

    double d = dist(x1, y1, x2, y2);
    if (d >= r1 + r2)
    {
        cout << 0.000;
        return 0;
    }
    else if (r2 + d <= r1)
    {
        cout << pow(r2, 2) * M_PI;
        return 0;
    }

    double theta1 = acos((pow(r1, 2) + pow(d, 2) - pow(r2, 2)) / (2 * r1 * d));
    double theta2 = acos((pow(r2, 2) + pow(d, 2) - pow(r1, 2)) / (2 * r2 * d));

    double area1 = (r1 * r1 * theta1) - (r1 * r1 * sin(2 * theta1) / 2);
    double area2 = (r2 * r2 * theta2) - (r2 * r2 * sin(2 * theta2) / 2);

    cout << area1 + area2;
    return 0;
}