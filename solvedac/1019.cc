// acmicpc number: 1019
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
ll cnt[10];

void calc(ll num, ll digit)
{
    while (num > 0) {
        cnt[num % 10] += digit;
        num /= 10;
    }
}

void solve(ll start, ll end, ll digit)
{
    while (start % 10 != 0 && start <= end) {
        calc(start, digit);
        start++;
    }

    if (start > end) return;
    while (end % 10 != 9 && start <= end) {
        calc(end, digit);
        end--;
    }

    ll diff = (end / 10 - start / 10 + 1);
    FOR(i, 10) cnt[i] += diff * digit;
    solve(start / 10, end / 10, digit * 10);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    solve(1, n, 1);

    FOR(i, 10) cout << cnt[i] << " ";
    return 0;
}
