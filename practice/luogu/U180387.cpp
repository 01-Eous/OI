#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 3e5 + 5;
int n,q;
int a[maxn],b[maxn];
inline void read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
struct Nahida 
{
    int l,r,c[2][2];
    int max1[2],max2[2];
    int add[2],tmin[2];
    Nahida()
    {
        l = r = 0;
        c[0][0] = c[0][1] = c[1][0] = c[1][1] = -inf;
        max1[0] = max1[1] = -inf;
        add[0] = add[1] = -inf;
        tmin[0] = tmin[1] = inf;
    }
    void init(int a,int b)
    {
        c[1][1] = a + b;
        c[0][0] = c[0][1] = c[1][0] = -inf;
        max1[0] = a,max2[0] = -inf;
        max1[1] = b,max2[1] = -inf; 
    }
    void clear_tag()
    {
        memset(add,0,sizeof add);
        memset(tmin,0x3f,sizeof tmin);
    }
    void push_up(const Nahida &lson,const Nahida &rson)
    {
        for (int i = 0; i < 2; i++)
        {
            if(lson.max1[i] > rson.max1[i])
            {
                this->max1[i] = lson.max1[i];
                this->max2[i] = max(lson.max2[i],rson.max1[i]);
            }
            else if (lson.max1[i] < rson.max1[i])
            {
                this->max1[i] = rson.max1[i];
                this->max2[i] = max(lson.max1[i],rson.max2[i]);
            }
            else
            {
                this->max1[i] = lson.max1[i];
                this->max2[i] = max(lson.max2[i],rson.max2[i]);
            }
        }
        c[0][0] = c[0][1] = c[1][0] = c[1][1] = -inf;

        //左儿子
        if (lson.max1[0] == this->max1[0] && lson.max1[1] == this->max1[1])
        {
            this->c[0][0] = lson.c[0][0];
            this->c[0][1] = lson.c[0][1];
            this->c[1][0] = lson.c[1][0];
            this->c[1][1] = lson.c[1][1];
        }
        else if (lson.max1[0] == this->max1[0] && lson.max1[1] != this->max1[1])
        {
            this->c[0][0] = max(lson.c[0][0],lson.c[0][1]);
            this->c[1][0] = max(lson.c[1][0],lson.c[1][1]);
        }
        else if (lson.max1[0] != this->max1[0] && lson.max1[1] == this->max1[1])
        {
            this->c[0][0] = max(lson.c[0][0],lson.c[1][0]);
            this->c[0][1] = max(lson.c[0][1],lson.c[1][1]);
        }
        else
            this->c[0][0] = max({lson.c[0][0],lson.c[0][1],lson.c[1][0],lson.c[1][1]});

        //右儿子
        if (rson.max1[0] == this->max1[0] && rson.max1[1] == this->max1[1])
        {
            this->c[0][0] = max(this->c[0][0],rson.c[0][0]);
            this->c[0][1] = max(this->c[0][1],rson.c[0][1]);
            this->c[1][0] = max(this->c[1][0],rson.c[1][0]);
            this->c[1][1] = max(this->c[1][1],rson.c[1][1]);
        }
        else if (rson.max1[0] == this->max1[0] && rson.max1[1] != this->max1[1])
        {
            this->c[0][0] = max(this->c[0][0],max(rson.c[0][0],rson.c[0][1]));
            this->c[1][0] = max(this->c[1][0],max(rson.c[1][0],rson.c[1][1]));
        }
        else if (rson.max1[0] != this->max1[0] && rson.max1[1] == this->max1[1])
        {
            this->c[0][0] = max(this->c[0][0],max(rson.c[0][0],rson.c[1][0]));
            this->c[0][1] = max(this->c[0][1],max(rson.c[0][1],rson.c[1][1]));
        }
        else
            this->c[0][0] = max(this->c[0][0],max({rson.c[0][0],rson.c[0][1],rson.c[1][0],rson.c[1][1]}));
    }
    void tag_add(int tag,bool id)
    {
        if (!tag)
            return;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                if (this->c[i][j] != -inf)
                    this->c[i][j] += tag;
        this->max1[id] += tag;
        if (this->max2[id] != -inf)
            this->max2[id] += tag;
        if (this->tmin[id] != inf)
            this->tmin[id] += tag;
        this->add[id] += tag;
    }
    void tag_min(int tag,bool id)//a[i] -> min(a[i],tag)
    {
        if (this->max1[id] <= tag)
            return;
        if (this->c[1][1] != -inf)
            this->c[1][1] += tag - this->max1[id];
        if (this->c[!id][id] != -inf)
            this->c[!id][id] += tag - this->max1[id];
        this->tmin[id] = this->max1[id] = tag;
    }
}tree[maxn << 2];
inline void push_down(int rt)
{
    for (int i = 0; i < 2; i++)
    {
        tree[ls].tag_add(tree[rt].add[i],i);
        tree[rs].tag_add(tree[rt].add[i],i);
    }
    for (int i = 0; i < 2; i++)
    {
        tree[ls].tag_min(tree[rt].tmin[i],i);
        tree[rs].tag_min(tree[rt].tmin[i],i);
    }
    tree[rt].clear_tag();
}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].clear_tag();
    if (l == r)
        return tree[rt].init(a[l],b[r]);
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
void upd_min(int ql,int qr,int x,bool id,int rt = 1)//a[i] -> min(a[i],x)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (tree[rt].max1[id] <= x)
        return;
    if (ql <= l && r <= qr && tree[rt].max2[id] < x)
        return tree[rt].tag_min(x,id);
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd_min(ql,qr,x,id,ls);
    if (qr > mid)
        upd_min(ql,qr,x,id,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
void upd_add(int ql,int qr,int x,bool id,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].tag_add(x,id);
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd_add(ql,qr,x,id,ls);
    if (qr > mid)
        upd_add(ql,qr,x,id,rs);
    tree[rt].push_up(tree[ls],tree[rs]);
}
Nahida que(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt];
    push_down(rt);
    int mid = (l + r) >> 1;
    if (l <= qr && qr <= mid)
        return que(ql,qr,ls);
    if (mid < ql && ql <= r)
        return que(ql,qr,rs);
    Nahida ret;
    ret.push_up(que(ql,qr,ls),que(ql,qr,rs));
    return ret;
}
signed main()
{
    read(n),read(q);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    for (int j = 1; j <= n; j++)
        read(b[j]);
    build(1,n,1);
    int op,l,r,x;
    while (q--)
    {
        read(op),read(l),read(r);
        if (op <= 4)
        {
            read(x);
            if (op == 1)
                upd_min(l,r,x,0);
            else if (op == 2)
                upd_min(l,r,x,1);
            else if (op == 3)
                upd_add(l,r,x,0);
            else
                upd_add(l,r,x,1);
        }
        else
        {
            Nahida tmp = que(l,r);
            printf("%lld\n",max({tmp.c[0][0],tmp.c[0][1],tmp.c[1][0],tmp.c[1][1]}));
        }
    }
    return 0;
}