// acmicpc number: 11279
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    priority_queue<int> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            if (k.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << k.top() << "\n";
                k.pop();
            }
        }
        else k.push(x);
    }
}