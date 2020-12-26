// acmicpc number: 1912
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0; cin >> n;
    int seq[n];
    int cont_sum[n];
    memset(seq, 0, sizeof(int)*n);
    memset(cont_sum, 0, sizeof(int)*n);
    
    for (int i = 0; i < n; i++) cin >> seq[i];
    cont_sum[n-1] = seq[n-1];

    for (int i = n-2; i >= 0; i--)
    {
        if (cont_sum[i+1] > 0) cont_sum[i] = seq[i] + cont_sum[i+1];
        else cont_sum[i] = seq[i];
    }

    int max = INT_MIN;
    for (int i = 0; i < n; i++) if (max < cont_sum[i]) max = cont_sum[i];

    cout << max;
}