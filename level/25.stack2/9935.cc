// acmicpc number: 9935
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


bool del(int k, stack<char>& st, const string& bomb)
{
    if (k < 0) return false;
    if (bomb[k] == st.top())
    {
        char tmp = st.top();
        st.pop();
        bool ret = true;
        if (k > 0) ret = del(k-1, st, bomb); 
        if (!ret) {
            st.push(tmp);
        } 
        return ret;
    }
    return false;
}

void del(stack<char>& st, const string& bomb)
{
    del(bomb.size() - 1, st, bomb);
    return;
}

void rev_cout(stack<char>& st)
{
    if (st.size() > 0) 
    {
        char tmp = st.top();
        st.pop();
        rev_cout(st);
        cout << tmp;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str, bomb;
    getline(cin, str);
    getline(cin, bomb);
    stack<char> str_stack;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        str_stack.push(ch);
        if (str_stack.size() < bomb.size()) continue;
        if (ch != bomb[bomb.size() -1]) continue;
        del(str_stack, bomb);
    }
    if (str_stack.size() > 0) rev_cout(str_stack);
    else cout << "FRULA";
    return 0;
}