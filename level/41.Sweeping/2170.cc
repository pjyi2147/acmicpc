// acmicpc number: 2170
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    int ret = 0;
    int s = v[0].first, e = v[0].second;
    for (auto i : v)
    {
        if (e < i.first)
        {
            ret += (e - s);
            s = i.first;
            e = i.second;
        }
        else if (e < i.second)
        {
            e = i.second;
        }
    }

    cout << ret + (e - s);
}