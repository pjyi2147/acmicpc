// acmicpc number: 1450
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, c;

void solve(int s, int e, ll sum, vector<ll>& v, const vector<int> arr)
{
    if (s > e)
    {
        v.push_back(sum);
        return;
    }

    solve(s+1, e, sum+arr[s], v, arr);
    solve(s+1, e, sum, v, arr);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> c;
    vector<int> arr(n);
    vector<ll> a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    solve(0, n/2, 0, a, arr);
    solve(n/2+1, n-1, 0, b, arr);

    sort(b.begin(), b.end());

    ll ret = 0;
    for (int i = 0; i < a.size(); i++)
    {
        ret += upper_bound(b.begin(), b.end(), c-a[i]) - b.begin();
    }

    cout << ret;
}