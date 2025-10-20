#include<bits/extc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n;
char s[maxn];
signed main()
{
    scanf("%d%s",&n,s + 1);
    queue<int> q[2];
    for (int i = 1; i <= n; i++)
        q[s[i] == 'P'].push(i);
    while (!q[0].empty() && !q[1].empty())
    {
        int x = q[0].front(),y = q[1].front();
        q[0].pop(),q[1].pop();
        if (x < y)
            q[0].push(x + n);
        else
            q[1].push(y + n);
    }
    if (q[0].empty())
        puts("Paul");
    else
        puts("Alex");
    return 0;
}