// acmicpc number: 2981
#include <bits/stdc++.h>
using namespace std;

int n;
int gcm(int a, int b)
{
    if (b > a) return gcm(b, a);
    if (a % b) return gcm(b, a % b);
    return b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<int> seq;
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        seq.push_back(k);
    }
    int kgcm = abs(seq[1]-seq[0]);
    for (int i = 1; i < n-1; i++)
    {
        kgcm = gcm(kgcm, abs(seq[i+1]-seq[i]));
    }

    vector<int> result;
    for (int i = 2; i*i <= kgcm; i++)
    {
        if (kgcm % i == 0)
        {
            result.push_back(i);
            result.push_back(kgcm/i);
        }
    }
    result.push_back(kgcm);

    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";
}