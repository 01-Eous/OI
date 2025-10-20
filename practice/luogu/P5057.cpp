#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,m,len,id[maxn];
bool a[maxn],tag[maxn];
void init()
{
    len = sqrt(n);
    for (int i = 1; i <= n; i++)
        id[i] = (i - 1) / len  + 1;
}
void push_down(int id)
{
    for (int i = (id - 1) * len + 1; i <= id * len; i++)
        a[i] ^= tag[id];
    tag[id] = 0;
}
void upd(int l,int r)
{
    int lid = id[l],rid = id[r];
    if (lid == rid)
    {
        push_down(lid);
        for (int i = l; i <= r; i++)
            a[i] ^= 1;
        return;
    }
    push_down(lid);
    for (int i = l; id[i] == lid; i++)
        a[i] ^= 1;
    push_down(rid);
    for (int i = r; id[i] == rid; i--)
        a[i] ^= 1;
    for (int i = lid + 1; i <= rid - 1; i++)
        tag[i] ^= 1;
}
int que(int pos)
{
    push_down(id[pos]);
    return a[pos];
}
signed main()
{
    scanf("%d%d",&n,&m);
    init();
    int op,l,r;
    while (m--)
    {
        scanf("%d%d",&op,&l);
        if (op == 1)
        {
            scanf("%d",&r);
            upd(l,r);
        }
        else
            printf("%d\n",que(l));
    }
    return 0;
}