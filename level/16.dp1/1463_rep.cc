// acmicpc number: 1463
#include <bits/stdc++.h>
using namespace std;

int n;
const int INF = 1000002;
const int MAX_N = 1000001;
int cache[MAX_N];

void solve()
{
    cache[0] = 0;
    cache[1] = 0;
    for (int i = 2; i < MAX_N; i++)
    {
        int& cand = cache[i];
        cand = INF;
        if (i % 3 == 0) cand = min(cand, 1+cache[i/3]);
        if (i % 2 == 0) cand = min(cand, 1+cache[i/2]);
        cand = min(cand, 1+cache[i-1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    solve();
    cout << cache[n];
}