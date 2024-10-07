// acmicpc number: 16565
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

ll n;
int comb[53][53];
int mod = 10007;

int calc_comb(int n, int r)
{
    if (r < 0 || r > n) return 0;
    if (n == r || r == 0) return 1;
    if (r == n - 1 || r == 1) return n;
    if (comb[n][r] != 0) return comb[n][r];
    return comb[n][r] = ((calc_comb(n-1, r-1) + calc_comb(n-1, r)) % mod);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    ll ret = 0;
    ll mod = 10007;

    if (n < 4)
    {
        cout << 0 << endl;
        return 0;
    }

    if (n > 39)
    {
        cout << calc_comb(52, n) << endl;
    }

    else
    {
        int upto = n / 4;
        for (int i = 1; i <= upto; i++)
        {
            int front = calc_comb(13, i);
            int back = calc_comb(52 - 4 * i, n - 4 * i);
            ret += front * back * (i % 2 == 1 ? 1 : -1);
            ret %= mod;
            if (ret < 0) ret += mod;
        }
        cout << ret << endl;
    }
}
