// acmicpc number: 3052
#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool mod[42];
    memset(mod, 0, sizeof(bool)*42);
    for (int i = 0; i < 10; i++)
    {
        int k;
        cin >> k;
        mod[k%42] = true;
    }
    int s = 0;
    for (int i = 0; i < 42; i++)
    {
        if (mod[i]) s++;
    }
    cout << s;
}