// acmicpc number: 11003
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

ll n, l;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l;
    deque<pll> dq;
    FOR(i, n)
    {
        ll a;
        cin >> a;
        while (!dq.empty() && dq.back().first > a)
            dq.pop_back();
        dq.push_back({a, i});
        while (!dq.empty() && dq.front().second <= i - l)
                dq.pop_front();
        cout << dq.front().first << " ";
    }
}
