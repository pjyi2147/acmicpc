// acmicpc number: 1074
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

ll n, r, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> r >> c;

    int cnt = 0;
    while (n >= 1)
    {
        int t = 1 << (n - 1);
        if (r >= t && c >= t)
        {
            r -= t;
            c -= t;
            cnt += 3 * t * t;
        }
        else if (r >= t)
        {
            r -= t;
            cnt += 2 * t * t;
        }
        else if (c >= t)
        {
            c -= t;
            cnt += t * t;
        }
        n--;
    }
    cout << cnt;
}
