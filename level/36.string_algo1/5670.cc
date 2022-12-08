// acmicpc number: 5670
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
struct Trie
{
    Trie *ch[26] = {nullptr};
    Trie *parent = nullptr;
    bool leaf = false;

    void insert(const string& st, int idx)
    {
        if (idx == st.size())
        {
            leaf = true;
            return;
        }
        int st_idx = st[idx] - 'a';
        if (!ch[st_idx])
        {
            ch[st_idx] = new Trie();
            ch[st_idx]->parent = this;
        }
        ch[st_idx]->insert(st, idx + 1);
    }

    pair<ll, ll> hop()
    {
        pair<ll, ll> ret = {0, 0};
        for (int i = 0; i < 26; i++)
        {
            if (ch[i])
            {
                auto p = ch[i]->hop();
                ret.first += (p.first + p.second);
                ret.second += p.second;
                if (ch[i]->leaf)
                {
                    ret.first++;
                    ret.second++;
                }
            }
        }
        return ret;
    }

    void compress()
    {
        int cnt = 0;
        int loc = 0;
        for (int i = 0; i < 26; i++)
        {
            if (ch[i])
            {
                ch[i]->compress();
                cnt++;
                loc = i;
            }
        }
        if (cnt == 1 && !leaf && parent)
        {
            int loc_this = 0;
            for (int i = 0; i < 26; i++)
            {
                if (parent->ch[i] == this)
                    loc_this = i;
            }
            parent->ch[loc_this] = ch[loc];
            ch[loc]->parent = this->parent;
            delete this;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin >> n)
    {
        Trie trie;
        for (int i = 0; i < n; i++)
        {
            string st;
            cin >> st;
            trie.insert(st, 0);
        }
        trie.compress();
        auto ret = trie.hop();
        cout << setprecision(2) << fixed << ((double)ret.first / (double)n) << "\n";
    }
}