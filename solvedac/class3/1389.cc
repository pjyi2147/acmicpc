// acmicpc number: 1389
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

ll n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    vii friends(n, vector<int>());
    FOR(i, m)
    {
        int a, b;
        cin >> a >> b;
        friends[a - 1].push_back(b - 1);
        friends[b - 1].push_back(a - 1);
    }

    int ret_num = INT_MAX, ret_human = -1;

    FOR(i, n)
    {
        vi cnt(n, -1);
        cnt[i] = 0;
        queue<int> q;
        for (auto f : friends[i])
        {
            q.push(f);
            cnt[f] = 1;
        }

        while (!q.empty()) {
            int t = q.front();
            q.pop();

            for (auto f : friends[t])
            {
                if (cnt[f] == -1)
                {
                    cnt[f] = cnt[t] + 1;
                    q.push(f);
                }
            }
        }

        int temp_sum = 0;
        for (auto j : cnt)
        {
            temp_sum += j;
        }
        if (temp_sum < ret_num)
        {
            ret_num = temp_sum;
            ret_human = i;
        }
    }

    cout << ret_human + 1;
}
