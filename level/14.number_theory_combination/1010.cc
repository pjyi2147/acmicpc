// acmicpc number: 1010
#include <bits/stdc++.h>
using namespace std;

int n;

int64_t NCR[31][31];

int64_t nCr(int n, int r)
{
    if (NCR[n][r] != 0) return NCR[n][r];
    if (r == 0 || r == n) {
        NCR[n][r] = 1;
        return 1;
    }
    NCR[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
    return NCR[n][r];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, t;
        cin >> a >> b;
        if (b > a) {
            t = a;
            a = b;
            b = t;
        }

        int64_t ans = nCr(a, b);
        cout << ans << endl;
    }
}