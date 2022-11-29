// acmicpc number: 11758
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

int calc(pair<int, int>* pts)
{
    auto p1 = pts[0], p2 = pts[1], p3 = pts[2];
    return (p2.first - p1.first) * (p3.second - p2.second) - (p3.first - p2.first) * (p2.second - p1.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pair<int, int> pts[3];

    for (int i = 0; i < 3; i++)
    {
        int x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }

    int ret = calc(pts);
    if (ret > 0)
        cout << 1;
    else if (ret < 0)
        cout << -1;
    else
        cout << 0;
}