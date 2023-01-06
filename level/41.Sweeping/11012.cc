// acmicpc number: 11012
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i=(a); i < (b); i++)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int maxn = 100001;
int roots[maxn + 1];

ll n, m, tsize;

struct Node
{
    int l, r, val;
    Node() : l(0), r(0), val(0){};
    Node(int l, int r, int val) : l(l), r(r), val(val){};
};

void init(vector<Node> &tree)
{
    int mid = tsize >> 1;
    REP(i, 1, mid + 1)
    {
        tree[i].l = i << 1;
        tree[i].r = i << 1 | 1;
    }
}

void update(vector<Node> &tree, int node, int s, int e, int idx)
{
    if (s != e)
    {
        int mid = (s + e) >> 1;
        int n1 = tree[node].l, n2 = tree[node].r;
        if (idx <= mid)
        {
            tree[node].l = tree.size();
            tree.push_back(Node(tree[n1].l, tree[n1].r, tree[n1].val + 1));
            update(tree, tree[node].l, s, mid, idx);
        }
        else
        {
            tree[node].r = tree.size();
            tree.push_back(Node(tree[n2].l, tree[n2].r, tree[n2].val + 1));
            update(tree, tree[node].r, mid + 1, e, idx);
        }
    }
}

int query(vector<Node> &tree, int node, int s, int e, int qs, int qe)
{
    if (qe < s || e < qs)
        return 0;
    
    if (qs <= s && e <= qe)
    {
        return tree[node].val;
    }

    int mid = (s + e) >> 1;
    return query(tree, tree[node].l, s, mid, qs, qe) + query(tree, tree[node].r, mid + 1, e, qs, qe);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    tsize = 1;
    while (tsize < maxn) tsize <<= 1;
    tsize <<= 1;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<int>> yval(maxn + 1);
        auto tree = vector<Node>(tsize);
        FOR(i, n)
        {
            int x, y;
            cin >> x >> y;
            yval[x + 1].push_back(y + 1);
        }
        init(tree);
        roots[0] = 1;
        REP(i, 1, maxn+1)
        {
            roots[i] = tree.size();
            int pi = roots[i - 1];
            tree.push_back(Node(tree[pi].l, tree[pi].r, tree[pi].val));
            for (auto y : yval[i])
            {
                tree[roots[i]].val += 1;
                update(tree, roots[i], 1, maxn, y);
            }
        }

        ll ret = 0;
        FOR(i, m)
        {
            int l, r, b, t;
            cin >> l >> r >> b >> t;
            ret += query(tree, roots[r + 1], 1, maxn, b + 1, t + 1) - query(tree, roots[l], 1, maxn, b + 1, t + 1);
        }
        cout << ret << '\n';
    }
}