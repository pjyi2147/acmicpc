// acmicpc number: 1920
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m;

bool search(vector<int>& v, int x)
{
    int l = 0, r = v.size() - 1;
    while (l <= r) 
    {
        int m = (l + r) / 2;
        if (v[m] == x) return true;
        if (v[m] < x) l = m + 1;
        else r = m - 1;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << search(v, x) << "\n";
    }
    return 0;
}