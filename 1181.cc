// acmicpc number: 1181
#include <bits/stdc++.h>
using namespace std;

bool comp(string a, string b)
{
    if (a.size() < b.size()) return true;
    else if (a.size() == b.size()) return strcmp(a.c_str(), b.c_str()) <= 0;
    return false;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    string str;
    vector<string> str_set;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (find(str_set.begin(), str_set.end(), str) == str_set.end())
        {
            str_set.push_back(str);
        }
    }
    sort(str_set.begin(), str_set.end(), comp);

    for (auto& i : str_set)
    {
        cout << i << "\n";
    }
}