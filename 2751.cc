// acmicpc number: 2751
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> vec;
    scanf("%d\n", &n);

    vec.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d\n", &k);
        vec.push_back(k);
    }
    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", vec[i]);
    }
}