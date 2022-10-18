// acmicpc number: 2293
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
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int max = v.back();
    vector<int> p_cnt(k+1, 0);
    vector<int> cnt(k+1, 0);
    for (int i = 1; i <= k; i++) {
        if (i % v[0] == 0) p_cnt[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        int coin = v[i];
        for (int j = 1; j <= k; j++) {
            cnt[j] = (j % coin == 0) ? 1 : 0;
            for (int r = 0; r <= j / coin; r++) {
                cnt[j] += p_cnt[j - r * coin];
            }
        }
        p_cnt = cnt;
    }
    cout << p_cnt[k];
}