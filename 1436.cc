// acmicpc number: 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int cnt = 0, num = 665;
    while (cnt < n)
    {
        num++; 
        string s = to_string(num);
        if (s.find("666") != string::npos) cnt++;
    }
    cout << num << "\n";
}