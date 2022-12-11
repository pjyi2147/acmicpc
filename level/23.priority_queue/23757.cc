// acmicpc number: 23757
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, m;
vector<int> ch;
priority_queue<int> pq;

void solve()
{
    for (int i = 0; i < m; i++)
    {
        int candy = ch[i];
        if (pq.top() >= candy)
        {
            int box = pq.top();
            pq.pop();

            pq.push(box - candy);
        }
        else
        {
            cout << 0;
            return;
        }
    }
    cout << 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        pq.push(k);
    }
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        ch.push_back(k);
    }

    solve();
}