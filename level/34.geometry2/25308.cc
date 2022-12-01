// acmicpc number: 25308
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

double ccw(pair<double, double> v1, pair<double, double> v2)
{
    return v1.first * v2.second - v2.first * v1.second;
}

bool calc(int p1, int p2, int p3)
{
    double p1d = p1, p2d = p2, p3d = p3;
    double tmp = ccw({(-p1)/sqrt(2), (p1)/sqrt(2) - p2}, {p3/sqrt(2), p3/sqrt(2) - p2});

    if (tmp < 0)
        return false;
    return true;
}

bool solve(const vector<int>& pts, const vector<int>& loc)
{
    int ret = true;
    for (int i = 0; i < 8; i++)
    {
        int p1 = pts[loc[((i - 1) + 8) % 8]], p2 = pts[loc[(i % 8)]], p3 = pts[loc[(i + 1) % 8]];

        if (!calc(p1, p2, p3))
            return false;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> pts(8, -1);

    for (int i = 0; i < 8; i++)
    {
        cin >> pts[i];
    }
    int ret = 0;
    
    vector<int> loc(8, -1);
    vector<bool> check(8, false);
    for (int a = 0; a < 8; a++)
    {
        loc[0] = a;
        check[a] = true;
        for (int b = 0; b < 8; b++)
        {
            if (check[b])
                continue;
            loc[1] = b;
            check[b] = true;
            for (int c = 0; c < 8; c++)
            {
                if (check[c])
                    continue;
                loc[2] = c;
                check[c] = true;
                for (int d = 0; d < 8; d++)
                {
                    if (check[d])
                        continue;
                    loc[3] = d;
                    check[d] = true;
                    for (int e = 0; e < 8; e++)
                    {
                        if (check[e])
                            continue;
                        loc[4] = e;
                        check[e] = true;
                        for (int f = 0; f < 8; f++)
                        {
                            if (check[f])
                                continue;
                            loc[5] = f;
                            check[f] = true;
                            for (int g = 0; g < 8; g++)
                            {
                                if (check[g])
                                    continue;
                                loc[6] = g;
                                check[g] = true;
                                for (int h = 0; h < 8; h++)
                                {
                                    if (check[h])
                                        continue;
                                    loc[7] = h;
                                    check[h] = true;

                                    if (solve(pts, loc))
                                        ret++;

                                    check[h] = false;
                                }
                                check[g] = false;
                            }
                            check[f] = false;
                        }
                        check[e] = false;
                    }
                    check[d] = false;
                }
                check[c] = false;
            }
            check[b] = false;
        }
        check[a] = false;
    }
    cout << ret;
}