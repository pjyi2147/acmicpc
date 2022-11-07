// acmicpc number: 18870
#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> v1;
    vector<int> v2;

    v1.reserve(n);
    v2.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        cin >> k;
        v1.push_back(k);
        v2.push_back(k);
    }
    sort(v1.begin(), v1.end());
    v1.resize(unique(v1.begin(), v1.end()) - v1.begin());

    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin();
        cout << it << ' ';
    }
}
