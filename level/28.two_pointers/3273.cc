// acmicpc number: 3273
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cin >> x;

    int s = 0, e = n-1;
    int ret = 0;
    while (s < e)
    {
        int tmp = v[s] + v[e];
        if (tmp == x) {
            ret++;
            s++;
        }
        else if (tmp < x) s++;
        else e--;
    }
    cout << ret;
}