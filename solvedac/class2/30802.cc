// acmicpc number: 30802
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i=(a); i < (b); i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<int> vi;
typedef vector<vi> vii;

int n, s, m, l, xl, xxl, xxxl, t, p;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s >> m >> l >> xl >> xxl >> xxxl >> t >> p;

    int gt = 0;
    s > 0 ? gt += (s - 1) / t + 1 : 0;
    m > 0 ? gt += (m - 1) / t + 1 : 0;
    l > 0 ? gt += (l - 1) / t + 1 : 0;
    xl > 0 ? gt += (xl - 1) / t + 1 : 0;
    xxl > 0 ? gt += (xxl - 1) / t + 1 : 0;
    xxxl > 0 ? gt += (xxxl - 1) / t + 1 : 0;

    cout << gt << "\n" << n / p << " " << n % p;
}
