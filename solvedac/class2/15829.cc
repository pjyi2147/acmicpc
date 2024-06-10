// acmicpc number: 15829
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
int r = 31;
ll m = 1234567891;
unsigned long long mod[6];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s;

    unsigned long long hash = 0;

    FOR(i, n)
    {
        ll temp = ((ll)(s[i] - 'a' + 1));
        FOR(k, i)
        {
            temp *= r;
            temp %= m;
        }

        hash += temp;
        hash %= m;
    }

    cout << hash << endl;
}
