// acmicpc number: 17299
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int cnt[1000001];
    memset(cnt, -1, sizeof(int)*1000001);
    vector<int> v(n, 0);
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        cnt[v[i]]++;
    }

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty())
        {
            if (cnt[v[st.top()]] < cnt[v[i]])
            {
                ans[st.top()] = v[i];
                st.pop();
            }
            else break;
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}