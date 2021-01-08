// acmicpc number: 10757
#include <bits/stdc++.h>
using namespace std;

string a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    vector<int> ai;
    vector<int> bi;
    vector<int> ret;
    ret.push_back(0);
    for (int i = 0; i < a.length(); i++)
    {
        ai.push_back(a[a.length()-1-i] - '0');
    }
    for (int i = 0; i < b.length(); i++)
    {
        bi.push_back(b[b.length()-1-i] - '0');
    }
    int ais = ai.size();
    int bis = bi.size();
    int m = max(ais, bis);
    int s = min(ais, bis);
    for (int i = 0; i < m; i++)
    {
        int tmp = 0;
        int carry = 0;
        if (i < s) tmp = ai[i] + bi[i];
        else if (ais == m) tmp = ai[i];
        else tmp = bi[i];
        if (tmp > 9) 
        {
            tmp %= 10;
            carry = 1;
        }

        ret[i] += tmp;
        if (ret[i] > 9)
        {
            ret[i] %= 10;
            carry++;
        }
        ret.push_back(carry);
    }

    for (int i = ret.size()-1; i >= 0; i--)
    {
        if (i == ret.size()-1 && ret[i] == 0) continue;
        cout << ret[i];
    }
    cout << "\n";
}