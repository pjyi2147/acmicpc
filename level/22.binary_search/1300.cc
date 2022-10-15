// acmicpc number: 1300
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;

    ll l = 1, r = min(1000000000LL, n*n);
    while (l <= r) {
        ll m = (l + r) / 2;
        ll cnt = 0;
        for (ll i = 1; i <= n; i++) {
            cnt += min(n, m/i);
        }

        if (cnt >= k) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    cout << l;
}