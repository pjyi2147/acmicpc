// acmicpc number: 3015
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
    stack<int> st;
    stack<int> st_cnt;
    ll ret = 0;
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        int k_cnt = 1;
        while (!st.empty())
        {
            if (st.top() < k)
            {
                ret += st_cnt.top();
                st_cnt.pop();
                st.pop();
            }
            else if (st.top() == k)
            {
                ret += st_cnt.top();
                k_cnt += st_cnt.top();
                st_cnt.pop();
                st.pop();
            }
            else
            {
                ret += 1;
                break;
            }
        }
        st.push(k);
        st_cnt.push(k_cnt);
    }
    cout << ret;
}