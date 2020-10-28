// acmicpc number: 2798
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    vector<int> k;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int p; 
        cin >> p;
        k.push_back(p);
    }
    sort(k.begin(), k.end());

    int sum = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i+1; j < n - 1; j++)
        {
            for (int l = j+1; l < n; l++) 
            {
                int temp = k[i]+k[j]+k[l]; 
                if (temp <= m && sum < temp) sum = temp;
            }
        }
    }
    cout << sum << "\n";
}