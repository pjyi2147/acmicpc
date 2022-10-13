// acmicpc number: 1764
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    unordered_set <string> set;
    vector<string> vec;
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        set.insert(x);
    }

    for (int i = 0; i < m; ++i) {
        string x;
        cin >> x;
        if (set.find(x) != set.end()) vec.push_back(x);
    }

    sort(vec.begin(), vec.end());
    cout << vec.size() << "\n";
    for (auto x : vec) cout << x << "\n";
}