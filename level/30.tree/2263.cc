// acmicpc number: 2263
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;

void printpre(int inS, int inE, const vector<int>& in, int postS, int postE, const vector<int>& post)
{
    if (postE < postS)
        return;
    int root = post[postE];
    cout << root << " ";
    int it;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == root) 
        {
            it = i;
            break;
        }
    }
    printpre(inS, it - 1, in, postS, postS + (it - 1 - inS), post);
    printpre(it + 1, inE, in, postS + it - inS, postE - 1, post);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    vector<int> in(n);
    vector<int> post(n);

    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }

    printpre(0, n - 1, in, 0, n - 1, post);
    cout << "\n";
}