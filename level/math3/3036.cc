// acmicpc number: 3036
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ring;

int gcm(int a, int b)
{
    if (b > a) return gcm(b, a);

    if (a % b == 0) return b;
    return gcm(b, a % b);
}

void frac(int a, int b)
{
    cout << a/gcm(a,b) << "/" << b/gcm(a,b) << "\n";
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        ring.push_back(k);
    }
    
    for (int i = 1; i < n; i++)
    {
        frac(ring[0], ring[i]);
    }
}