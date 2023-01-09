// acmicpc number: 13976
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = (a); i < (b); i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<int> vi;
typedef vector<vi> vii;

constexpr int mod = 1e9 + 7;
ll n;

vll operator*(vll &a, vll &b) {
    vll ret(2, vl(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ret[i][j] += a[i][k] * b[k][j] % mod;
                ret[i][j] = (ret[i][j] + mod) % mod;
            }
        }
    }
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    vll a = {{4, -1}, {1, 0}};
    vll init = {{1, 0}, {1, 0}};
    vll ret = {{1, 0}, {0, 1}};
    if (n & 1)
    {
        cout << 0;
    }
    else
    {
        n /= 2;
        while (n)
        {
            if (n & 1)
                ret = ret * a;

            a = a * a;
            n /= 2;
        }
        ret = ret * init;
        cout << ret[0][0];
    }
}