// acmicpc number: 1406 
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    string st;

    cin >> st;
    cin >> m;
    list<char> lst(st.begin(), st.end());
    auto cur = lst.end();

    char cmd, alpha;
    for (int i = 0; i < m; i++)
    {
        cin >> cmd;
        switch (cmd)
        {
        case 'L':
            if (cur != lst.begin()) cur = cur--;
            break;
        case 'D':
            if (cur != lst.end()) cur = cur++;
            break;
        case 'B':
            if (cur != lst.begin()) {
                cur = lst.erase(--cur);
            }
            break;
        case 'P':
            cin >> alpha;
            lst.insert(cur, alpha);
            break;
        }
    }
    for (auto &c : lst)
    {
        cout << c;
    }
    return 0;
}