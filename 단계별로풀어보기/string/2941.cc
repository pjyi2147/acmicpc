// acmicpc number: 2941
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    int cnt = 0;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'c' || s[i] == 'z' || s[i] == 's')
        {
            if (s[i+1] == '=' || s[i+1] == '-') continue;
        }
        else if (s[i] == 'd')
        {
            if (s[i+1] == '-') continue;
            if (s[i+1] == 'z' && s[i+2] == '=') continue;
        }
        else if (s[i] == 'l' || s[i] == 'n')
        {
            if (s[i+1] == 'j') continue;
        }
        cnt++;
    }
    cout << cnt;
}