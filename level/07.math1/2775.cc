// acmicpc number: 
#include <bits/stdc++.h>
using namespace std;

int getppl(int k, int n, int* ap);

int main()
{
    int T;
    cin >> T;
    
    int* ap = new int[17*17];

    memset(ap, 0, sizeof(int)*17*17);

    for (int i = 0; i < 17; i++)
    {
        ap[i] = i;
        ap[17*i+1] = 1;
    }

    for (int i = 0; i < T; i++)
    {
        int k = 0, n = 0;
        cin >> k >> n;
        cout << getppl(k, n, ap) << "\n";
    }

    return 0;
}

int getppl(int k, int n, int* ap)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n - k < 2) 
    {
        int t = k;
        
        n -= 2;
        k = n;
        n = t;
        n += 2;
    }

    if (ap[k*17+n] == 0)
    {
        ap[k*17+n] = getppl(k, n-1, ap) + getppl(k-1, n, ap);
    }
    return ap[k*17+n];
}