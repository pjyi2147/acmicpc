// acmicpc number: 10986
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    vector<long long> remcnt(m, 0);
    vector<long long> v(n, 0);
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i > 0) {
            v[i] += v[i - 1];
        }
        v[i] %= m;
        if (v[i] == 0) {
            cnt++;
        }
        remcnt[v[i]]++;
    }
    for (int i = 0; i < m; i++) {
        cnt += remcnt[i] * (remcnt[i] - 1) / 2;
    }

    cout << cnt << '\n';
}
