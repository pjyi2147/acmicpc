// acmicpc number: 1655
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;

struct comp_g {
    bool operator()(int a, int b) {
        return a > b;
    }
};

struct comp_l {
    bool operator()(int a, int b) {
        return a < b;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    priority_queue<int, vector<int>, comp_l> pq1;
    priority_queue<int, vector<int>, comp_g> pq2;
    for (int i = 0; i < n; i++) 
    {
        int x;
        cin >> x;
        if (!pq1.empty() && x > pq1.top()) pq2.push(x);
        else pq1.push(x);

        if (pq1.size() == pq2.size() + 2) {
            int k = pq1.top();
            pq1.pop();
            pq2.push(k);
        }
        else if (pq1.size() + 1 == pq2.size()) {
            int k = pq2.top();
            pq2.pop();
            pq1.push(k);
        }
        cout << pq1.top() << "\n";
    }
}