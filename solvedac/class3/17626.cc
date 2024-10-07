// acmicpc number: 17626
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

    int cnt[n + 1] = {0, };
    cnt[1] = 1;
    cnt[2] = 2;
    cnt[3] = 3;
    cnt[4] = 1;

    REP(i, 5, n + 1)
    {
        cnt[i] = i;
        int j = 1;
        while (j * j <= i)
        {
            cnt[i] = min(cnt[i], cnt[i - j*j] + 1);
            j++;
        }
    }
    cout << cnt[n];
}
