// acmicpc number: 1991
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;


void print_pre(int k, const vector<pair<int, int>>& nodes)
{
    char ch = k + 'A';
    cout << ch;
    if (nodes[k].first >= 0)
        print_pre(nodes[k].first, nodes);
    if (nodes[k].second >= 0)
        print_pre(nodes[k].second, nodes);
}

void print_mid(int k, const vector<pair<int, int>>& nodes)
{
    char ch = k + 'A';
    if (nodes[k].first >= 0)
        print_mid(nodes[k].first, nodes);
    cout << ch;
    if (nodes[k].second >= 0)
        print_mid(nodes[k].second, nodes);
}

void print_pos(int k, const vector<pair<int, int>>& nodes)
{
    char ch = k + 'A';
    if (nodes[k].first >= 0)
        print_pos(nodes[k].first, nodes);
    if (nodes[k].second >= 0)
        print_pos(nodes[k].second, nodes);
    cout << ch;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<pair<int, int>> nodes(n);
    for (int i = 0; i < n; i++)
    {
        char p, l, r;
        int pi, li, ri;
        cin >> p >> l >> r;
        if (l == '.')
            li = -1;
        else
            li = l - 'A';
        if (r == '.')
            ri = -1;
        else
            ri = r - 'A';
        pi = p - 'A';
        nodes[pi] = make_pair(li, ri);
    }

    print_pre(0, nodes);
    cout << "\n";
    print_mid(0, nodes);
    cout << "\n";
    print_pos(0, nodes);
    cout << "\n";

    return 0;
}