#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,m,st[maxn],ed[maxn];
int lowbit(int x){return x & -x;}
void upd(int tree[],int i,int x)
{
    for (; i <= n; i += lowbit(i))
        tree[i] += x;
}
int que(int tree[],int i)
{
    int res = 0;
    for (; i; i -= lowbit(i))
        res += tree[i];
    return res;
}
signed main()
{
    scanf("%d%d",&n,&m);
    int op,l,r;
    while (m--)
    {
        scanf("%d%d%d",&op,&l,&r);
        if (op == 1)
            upd(st,l,1),upd(ed,r,1);
        else
            printf("%d\n",que(st,r) - que(ed,l - 1));
    }
    return 0;
}