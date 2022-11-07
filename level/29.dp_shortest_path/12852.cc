// acmicpc number: 12852
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
int INF = 987654321;

int solve(int i, vector<int>& k)
{
    if (k[i] > -1) return k[i];
    k[i] = solve(i-1, k) + 1;
    if (i % 2 == 0) k[i] = min(k[i], solve(i/2, k) + 1);
    if (i % 3 == 0) k[i] = min(k[i], solve(i/3, k) + 1);
    return k[i];
}

void print(int i, vector<int>& k)
{
    cout << i << " ";
    if (i == 1) return;
    if (i % 3 == 0 && k[i/3] + 1 == k[i]) return print(i/3, k);
    else if (i % 2 == 0 && k[i/2] + 1== k[i]) return print(i/2, k);
    else if (k[i-1] + 1 == k[i]) return print(i-1, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<int> k(n+1, -1);
    k[1] = 0;
    solve(n, k);
    cout << k[n] << '\n';
    print(n, k);
}