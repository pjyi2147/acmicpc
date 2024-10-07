// acmicpc number: 7662
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

ll T, n;
map<int, int> mapcnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    FOR(rep, T)
    {
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> gpq;
        priority_queue<int, vector<int>, less<int>> lpq;
        mapcnt.clear();
        FOR(i, n)
        {
            char inst;
            int num;
            cin >> inst >> num;
            switch (inst)
            {
            case 'I':
                gpq.push(num);
                lpq.push(num);
                mapcnt[num]++;
                break;
            case 'D':
                /* code */
                if (num == -1)
                {
                    if (!gpq.empty())
                    {
                        mapcnt[gpq.top()]--;
                        gpq.pop();
                    }
                }
                else
                {
                    if (!lpq.empty())
                    {
                        mapcnt[lpq.top()]--;
                        lpq.pop();
                    }
                }

                while (!lpq.empty() && mapcnt[lpq.top()] == 0)
                {
                    lpq.pop();
                }

                while (!gpq.empty() && mapcnt[gpq.top()] == 0)
                {
                    gpq.pop();
                }
                break;
            default:
                break;
            }
        }

        if (lpq.empty() || gpq.empty()) cout << "EMPTY\n";
        else cout << lpq.top() << " " << gpq.top() << "\n";
    }
    return 0;
}
