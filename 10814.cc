// acmicpc number: 10814
#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, string>> vec;

    for (int i=0; i < n; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        vec.push_back(make_pair(age, name));
    }
    stable_sort(vec.begin(), vec.end(), comp);

    for (auto& i : vec)
    {
        cout << i.first << " " << i.second << "\n";
    }
}