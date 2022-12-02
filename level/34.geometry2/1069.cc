// acmicpc number: 1069
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll x, y, d, t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> x >> y >> d >> t;
    cout << setprecision(10) << fixed;
    
    double dist = sqrt(x * x + y * y);
    double time = dist;

    if (dist > d)
    {
        int j = dist / d;
        time = min(time, (j * t) + dist - (j * d));
        time = min(time, (double)((j + 1) * t));
    }
    else
    {
        time = min(time, t + (d - dist));
        time = min(time, (double)(2 * t));
    }
    cout << time;
}