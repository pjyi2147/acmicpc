// acmicpc number: 11727
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    int cnt[n + 1] = {0};
    cnt[1] = 1;
    cnt[2] = 3;
    REP(i, 3, n + 1)
    {
        cnt[i] = 2 * cnt[i-2] + cnt[i - 1];
        cnt[i] %= 10007;
    }
    cout << cnt[n];
}
