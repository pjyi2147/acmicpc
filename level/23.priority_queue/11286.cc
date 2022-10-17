// acmicpc number: 11286
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;

struct comp {
    bool operator()(const int& a, const int& b) const {
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            if (v.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << v.front() << "\n";
                pop_heap(v.begin(), v.end(), comp());
                v.pop_back();
            }
        }
        else {
            v.push_back(x);
            push_heap(v.begin(), v.end(), comp());
        }
    }

    return 0;
}