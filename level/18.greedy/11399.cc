// acmicpc number: 11399
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> t;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        t.push_back(k);
    }
    sort(t.begin(), t.end());
    int ret = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += t[i];
        ret += sum;
    }
    cout << ret;
}