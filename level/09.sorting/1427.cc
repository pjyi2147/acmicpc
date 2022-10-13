// acmicpc number: 1427
#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b)
{
    return a > b;
}

int main()
{
    int k;
    vector<int> vec;
    cin >> k;
    while (k > 10) 
    {
        vec.push_back(k%10);
        k /= 10;
    }
    vec.push_back(k);
    sort(vec.begin(), vec.end(), comp);
    for (auto& i : vec) printf("%d", i);
}