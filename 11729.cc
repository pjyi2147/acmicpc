// acmicpc number: 11729
#include <bits/stdc++.h>
using namespace std;

void solve(int N);
void solve(int N, int from, int to, int mid);

int main()
{
    int N;
    cin >> N;
    int cnt[21];
    cnt[1] = 1;
    for (int i = 2; i <= 20; i++) cnt[i] = cnt[i-1]*2+1;
    printf("%d\n", cnt[N]);
    solve(N);
}

void solve(int N)
{
    solve(N, 1, 3, 2);
}

void solve(int N, int from, int to, int mid)
{
    if (N > 1) solve(N-1, from, mid, to);
    printf("%d %d\n", from, to);
    if (N > 1) solve(N-1, mid, to, from);
}