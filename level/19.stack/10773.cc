// acmicpc number: 10773
#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        if (k == 0) s.pop();
        else s.push(k);
    }
    int sum = 0;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }
    cout << sum;
}