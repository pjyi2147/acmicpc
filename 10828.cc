// acmicpc number: 10828
#include <bits/stdc++.h>
using namespace std;

stack<int> st;
int n, k;
char todo[20];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %s", todo);
        switch (todo[1])
        {
            case 'u':
                scanf(" %d", &k);
                st.push(k);
                break;
            case 'o':
                if (st.size() == 0) printf("-1\n"); 
                else {
                    printf("%d\n", st.top());
                    if(todo[0] == 'p') st.pop();
                }
                break;
            case 'i':
                printf("%d\n", st.size());
                break;
            case 'm':
                if (st.size()) printf("0\n");
                else printf("1\n");
                break;
        }
    }
}