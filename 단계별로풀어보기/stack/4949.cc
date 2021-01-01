// acmicpc number: 4949
#include <bits/stdc++.h>
using namespace std;

const string paren = "[(";

int main()
{
    string line;
    getline(cin, line);
    while (!(line == ".") && !(line == ""))
    {
        stack<char> st;
        bool yes = true;
        for (int i = 0; i < line.length(); i++)
        {
            char ch = line[i];
            if (paren.find(ch) != string::npos)
            {
                st.push(ch);
            }
            else if (ch == ']')
            {
                if (!st.empty() && st.top() == '[') st.pop();
                else 
                {
                    yes = false;
                    break;
                } 
            }
            else if (ch == ')')
            {
                if (!st.empty() && st.top() == '(') st.pop();
                else 
                {
                    yes = false;
                    break;
                }
            }
        }
        if (!st.empty()) yes = false;
        cout << (yes ? "yes\n" : "no\n");
        getline(cin, line);
    }
}