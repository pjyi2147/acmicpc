// acmicpc number: 1193
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, i = 1;
    cin >> N;

    int k = i*(i-1)/2;
    while (N > k) {
        i++;
        k = i*(i-1)/2;
    }

    int re = k - N + 1;
    int qo = i - re;
    if (i % 2 != 0) printf("%d/%d\n", qo, re);
    else printf("%d/%d\n", re, qo);
}