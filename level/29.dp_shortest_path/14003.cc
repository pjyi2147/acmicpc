// acmicpc number: 14003
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;

int push(int k, vector<int> &LIS)
{
    if (LIS.empty() || LIS[LIS.size() - 1] < k)
    {
        LIS.push_back(k);
        return LIS.size() - 1;
    }

    auto idx = lower_bound(LIS.begin(), LIS.end(), k) - LIS.begin();
    LIS[idx] = k;
    return idx;
}

void solve(vector<int> &LIS, vector<int> &loc, const vector<int> &seq)
{
    for (int i = 0; i < n; i++)
    {
        loc[i] = push(seq[i], LIS);
    }
}

void print(int idx, const vector<int> &loc, const vector<int> &seq)
{
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (loc[i] == idx)
        {
            st.push(seq[i]);
            idx--;
        }
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> seq(n), LIS, loc(n, -1);

    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
    }

    solve(LIS, loc, seq);
    cout << LIS.size() << "\n";
    print(LIS.size() - 1, loc, seq);
}
