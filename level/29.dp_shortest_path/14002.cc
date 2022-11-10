// acmicpc number: 14002
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;

void solve(vector<int>& s, const vector<int>& v)
{
    for (int i = 0; i < n; i++)
    {
        s[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i]) s[i] = max(s[i], s[j]+1);
        }
    }
}

void print_seq(vector<int>& s, const vector<int>& v, int tmp) {
    auto idx = find(s.begin(), s.end(), tmp) - s.begin();
    stack<int> q;
    q.push(idx);
    for (int i = idx - 1; i >= 0; i--)
    {
        if (s[i] + 1 == tmp && v[i] < v[idx])
        {
            q.push(i);
            tmp--;
            idx = i;
        }
    }

    while (!q.empty())
    {
        cout << v[q.top()] << " ";
        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> v(n, 0);
    vector<int> s(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    solve(s, v);
    int tmp = *max_element(s.begin(), s.end());
    cout << tmp << "\n";
    print_seq(s, v, tmp);
}