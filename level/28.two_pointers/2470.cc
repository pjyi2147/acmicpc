// acmicpc number: 2470
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;

struct temp {
    int s, e, t;
    temp(int s, int e, int t): s{s}, e{e}, t{t} {}
};

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
    int s = 0, e = n-1;
    temp cur_temp(0, n-1, abs(v[s] + v[e]));
    while (s < e)
    {
        int tmp = v[s] + v[e];
        if (abs(tmp) < cur_temp.t)
        {
            cur_temp = temp(s, e, abs(tmp));
        }

        if (tmp == 0) 
        {
            cur_temp = temp(s, e, 0);
            break;
        }
        if (tmp < 0) s++;
        if (tmp > 0) e--;
    }

    cout << v[cur_temp.s] << " " << v[cur_temp.e];
}