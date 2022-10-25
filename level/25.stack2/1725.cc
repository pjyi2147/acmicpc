// acmicpc number: 1725
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
    vector<int> h(n+2, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i+1];
    }

    st.push(0);
    int ret = 0;
    for (int i = 1; i <= n+1; i++)
    {
        while (!st.empty() && h[st.top()] > h[i])
        {
            int chck = st.top();
            st.pop();
            ret = max(ret, h[chck] * (i - st.top() - 1));
        }
        st.push(i);
    }
    cout << ret;
    return 0;
}