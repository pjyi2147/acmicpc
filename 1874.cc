// acmicpc number: 10828
#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    string plus = "+\n";
    string minus = "-\n";
    string ret;
    bool imp = false;
    int n = 0, k = 0;

    scanf("%d", &n);

    int seq[n+1];
    bool popped[n+1];
    memset(popped, 0, sizeof(popped));

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        seq[i] = k;
    }

    for (int i = 1; i <= n; i++)
    {
        k = seq[i];
        if (st.size() == 0)
        {
            for (int i = 1; i <= k; i++)
            {
                if (!popped[i]) 
                { 
                    st.push(i);
                    ret += plus;
                }
            }
            st.pop();
            ret += minus;
            popped[k] = true;
        }
        else if (st.top() < k)
        {
            for (int i = st.top()+1; i <= k; i++)
            {
                if (!popped[i])
                {
                    st.push(i);
                    ret += plus;
                }
            }
            st.pop();
            ret += minus;
            popped[k] = true;
        }       
        else if (st.top() == k) 
        {
            st.pop();
            ret += minus;
            popped[k] = true;
        }
        else 
        {
            imp = true;
            break;
        }
    }
    if (imp) printf("NO\n");
    else printf("%s\n", ret.c_str());
}