// acmicpc number: 10989 
#include <bits/stdc++.h>
using namespace std;

int cnt[10001];

int main()
{
    cin.tie(NULL); 
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        cnt[temp]++;
    }

    for (int i = 1; i < 10001; i++)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            cout << i << '\n';
        }
    }
}
