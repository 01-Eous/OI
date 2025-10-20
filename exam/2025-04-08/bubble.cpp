#include<bits/extc++.h>
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1 << 21,stdin),p1 == p2) ? EOF : *p1++)
using namespace std;
const int maxn = 5e5 + 5;
char *p1,*p2,buf[1 << 23];
int n,m;
int a[maxn],pos[maxn],ans[maxn];
void read(int &x)
{
    x = 0;
    char f = 1,ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
struct query
{
    int k,x,id;
    friend bool operator<(const query &x,const query &y){return x.x > y.x;}
}q[maxn];
struct Nahida{int l,r,val;}tree[maxn << 2];
#define ls (rt << 1)
#define rs (rt << 1 | 1)
void push_up(int rt){tree[rt].val = tree[ls].val + tree[rs].val;}
void build(int l,int r,int rt)
{
    tree[rt].l = l,tree[rt].r = r;
    tree[rt].val = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
}
void upd(int pos,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (l == r)
    {
        tree[rt].val++;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,ls);
    else
        upd(pos,rs);
    push_up(rt);
}
int que_sum(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].val;
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid)
        res += que_sum(ql,qr,ls);
    if (qr > mid)
        res += que_sum(ql,qr,rs);
    return res;
}
int que_kth(int k,int rt = 1)
{
    int l = tree[rt].l,r = tree[rt].r;
    if (l == r)
        return l;
    int tmp = tree[ls].val;
    if (k <= tmp)
        return que_kth(k,ls);
    else
        return que_kth(k - tmp,rs);
}
signed main()
{
    read(n);
    build(1,n,1);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        pos[a[i]] = i;
    }
    read(m);
    for (int i = 1; i <= m; i++)
    {
        auto &[k,x,id] = q[i];
        read(k),read(x),id = i;
    }
    sort(q + 1,q + m + 1);
    for (int i = n,j = 1; i >= 1; i--)
    {
        int u = que_sum(1,pos[i]),v = que_sum(pos[i],n);
        while (j <= m && q[j].x == i)
        {
            auto &[k,x,id] = q[j];
            if (k <= u)
                ans[id] = pos[i] - k;
            else if (k <= u + v)
                ans[id] = que_kth(k) - k;
            else
                ans[id] = n - u - v;
            j++;
        }
        upd(pos[i]);
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n",ans[i]);
    return 0;
}