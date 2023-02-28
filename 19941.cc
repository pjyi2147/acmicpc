// acmicpc number: 19941
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    queue<int> human;
    queue<int> ham;

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == 'H')
        {
            ham.push(i);
        }
        else
        {
            human.push(i);
        }
    }

    int ret = 0;
    while (!ham.empty() && !human.empty())
    {
        int dist = abs(human.front() - ham.front());
        if (dist > k)
        {
            if (human.front() > ham.front())
            {
                ham.pop();
            }
            else
            {
                human.pop();
            }
        }
        else 
        {
            ret++;
            human.pop();
            ham.pop();
        }
    }

    cout << ret;
}