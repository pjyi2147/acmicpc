// acmicpc number: 10866
#include <bits/stdc++.h>
using namespace std;

deque<int> de;
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
                if (todo[5] == 'b') de.push_back(k);
                else de.push_front(k);
                break;
            case 'o':
                if (de.size() == 0) printf("-1\n"); 
                else if (todo[4] == 'b') {
                    printf("%d\n", de.back());
                    de.pop_back();
                }
                else {
                    printf("%d\n", de.front());
                    de.pop_front();
                }
                break;
            case 'i':
                printf("%d\n", de.size());
                break;
            case 'm':
                if (de.size()) printf("0\n");
                else printf("1\n");
                break;
            case 'r':
                if (de.size()) printf("%d\n", de.front());
                else printf("-1\n");
                break;
            case 'a':
                if (de.size()) printf("%d\n", de.back());
                else printf("-1\n");
                break;
        }
    }
}