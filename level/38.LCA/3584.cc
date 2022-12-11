// acmicpc number: 3584
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;

struct Node
{
    Node *parent;
    int val;
    bool visited;

    Node(int val, Node *p = nullptr, bool visited = false) : val{val}, parent{p}, visited{visited} {}

    void mark()
    {
        this->visited = true;
        if (parent != nullptr)
            return parent->mark();
    }

    int find()
    {
        if (this->visited)
            return val;
        if (this->parent != nullptr)
            return parent->find();
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n;
        vector<Node *> tree(n + 1, nullptr);
        for (int i = 1; i <= n; i++)
        {
            tree[i] = new Node(i);
        }

        for (int i = 0; i < n - 1; i++)
        {
            int s, e;
            cin >> s >> e;
            tree[e]->parent = tree[s];
        }

        int a, b;
        cin >> a >> b;

        tree[a]->mark();
        cout << tree[b]->find() << "\n";
    }
}