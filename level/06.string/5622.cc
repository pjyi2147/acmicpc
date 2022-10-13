// acmicpc number: 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.length();

    int total = 0;
    string abc = "ABC";
    string def = "DEF";
    string ghi = "GHI";
    string jkl = "JKL";
    string mno = "MNO";
    string pqrs = "PQRS";
    string tuv = "TUV";
    string wxyz = "WXYZ";

    int OFFSET = 3;

    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        if (abc.find(c) != string::npos) total += 0;
        else if (def.find(c) != string::npos) total += 1;
        else if (ghi.find(c) != string::npos) total += 2;
        else if (jkl.find(c) != string::npos) total += 3;
        else if (mno.find(c) != string::npos) total += 4;
        else if (pqrs.find(c) != string::npos) total += 5;
        else if (tuv.find(c) != string::npos) total += 6;
        else if (wxyz.find(c) != string::npos) total += 7;

        total += OFFSET;
    }   

    cout << total;
}