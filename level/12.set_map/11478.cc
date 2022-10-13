// acmicpc number: 11478
#include <bits/stdc++.h>
using namespace std;

string n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    unordered_set<string> set;
    for (int i = 0; i < n.size(); i++) {
        for (int j = 1; j <= n.size() - i; j++) {
            set.insert(n.substr(i, j));
        }
    }
    cout << set.size();
}