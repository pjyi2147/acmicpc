// acmicpc number: 2836
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<pair<int, int>> bw;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
        {
            bw.push_back({b, a});
        }
    }

    sort(bw.begin(), bw.end());
    ll len = bw[0].second - bw[0].first;
    int e = bw[0].second;
    for (int i = 1; i < bw.size(); i++)
    {
        if (bw[i].first <= e)
        {
            if (bw[i].second > e)
            {
                len += (bw[i].second - e);
                e = bw[i].second;
            }
        }
        else
        {
            len += (bw[i].second - bw[i].first);
            e = bw[i].second;
        }
    }
    cout << m + len * 2;
}