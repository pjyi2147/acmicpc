// acmicpc number: 14725
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

struct Node
{
    map<string, Node *> ch;

    void insert(vector<string>& info, int f)
    {
        if (f == info.size())
            return;

        string s = info[f];
        auto iter = ch.find(s);
        if (iter != ch.end())
        {
            iter->second->insert(info, f + 1);
        }
        else 
        {
            auto nd = new Node;
            ch.insert({s, nd});
            nd->insert(info, f + 1);
        }
    }

    void print(int f)
    {
        if (ch.empty())
            return;
        for (auto it : ch)
        {
            for (int i = 0; i < f; i++)
            {
                cout << "--";
            }
            cout << it.first << "\n";
            it.second->print(f + 1);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    auto nd = Node();
    for (int i = 0; i < n; i++)
    {
        int k;
        vector<string> info;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            string st;
            cin >> st;
            info.push_back(st);
        }
        nd.insert(info, 0);
    }

    nd.print(0);
}