#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,m,q;
char str[maxn];
int s[maxn],t[maxn],l[maxn];
signed main()
{
    scanf("%d%d%s%d",&n,&m,str + 1,&q);
    int x,y,z;
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        s[i] = z + 1;
        t[i] = x + 1;
        l[i] = y - x;
    }
    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        for (int j = q; j >= 1; j--)
        {
            if (s[j] <= tmp && tmp < s[j] + l[j])
                tmp += t[j] - s[j];
            else if (s[j] + l[j] <= tmp)
                tmp -= l[j];
        }
        putchar(str[tmp]);
    }
    return 0;
}