#include<bits/extc++.h>
#define int long long
#define ls rt->lson
#define rs rt->rson
using namespace std;
const int maxn = 1e5 + 5;
random_device seed;
mt19937 rnd(seed() * time(0));
int n;
struct Nahida
{
    int siz,val;
    Nahida *lson,*rson;
    unsigned rnk;
}*root = 0;
inline void read(int &x)
{
    x = 0;
    char f = 1,ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
inline Nahida *clone(int val)
{
    Nahida *rt = new Nahida;
    ls = rs = 0;
    rt->siz = 1;
    rt->val = val;
    rt->rnk = rnd();
    return rt;
}
inline void push_up(Nahida *rt){rt->siz = 1 + (ls ? ls->siz : 0) + (rs ? rs->siz : 0);}
Nahida *merge(Nahida *l,Nahida *r)
{
    if (!l)
        return r;
    if (!r)
        return l;
    if (l->rnk < r->rnk)// 把 r 合并到 l
    {
        l->rson = merge(l->rson,r);
        push_up(l);
        return l;
    }
    else// 把 l 合并到 r
    {
        r->lson = merge(l,r->lson);
        push_up(r);
        return r;
    }
}
void split_val(Nahida *rt,int val,Nahida *&l,Nahida *&r)
{
    if (!rt)
    {
        l = r = 0;
        return;
    }
    if (rt->val <= val)
    {
        l = rt;
        split_val(rs,val,rs,r);
    }
    else
    {
        r = rt;
        split_val(ls,val,l,ls);
    }
    push_up(rt);
}
inline void insert(int val)
{
    Nahida *x,*y;
    split_val(root,val - 1,x,y);
    root = merge(merge(x,clone(val)),y);
}
inline void erase(int val)
{
    Nahida *x,*y,*z;
    split_val(root,val,x,z);
    split_val(x,val - 1,x,y);
    Nahida *tmp = merge(y->lson,y->rson);
    delete y;
    root = merge(merge(x,tmp),z);
}
inline int que_kth(int k)
{
    Nahida *rt = root;
    while (rt)
    {
        if ((ls ? ls->siz : 0) + 1 == k)
            break;
        if ((ls ? ls->siz : 0) >= k)
            rt = ls;
        else
        {
            k -= (ls ? ls->siz : 0) + 1;
            rt = rs;
        }
    }
    return rt->val;
}
inline int que_rnk(int val)
{
    Nahida *x,*y;
    split_val(root,val - 1,x,y);
    int res = (x ? x->siz : 0) + 1;
    root = merge(x,y);
    return res;
}
inline int que_pre(int val)
{
    Nahida *x,*y;
    split_val(root,val - 1,x,y);
    Nahida *rt = x;
    while (rs)
        rt = rs;
    root = merge(x,y);
    return rt->val;
}
inline int que_suf(int val)
{
    Nahida *x,*y;
    split_val(root,val,x,y);
    Nahida *rt = y;
    while (ls)
        rt = ls;
    root = merge(x,y);
    return rt->val;
}
void clear(Nahida *rt)
{
    if (!rt)
        return;
    clear(ls),clear(rs);
    delete rt;
}
signed main()
{
    read(n);
    int op,x;
    while (n--)
    {
        read(op),read(x);
        if (op == 1)
            insert(x);
        else if (op == 2)
            erase(x);
        else if (op == 3)
            printf("%lld\n",que_rnk(x));
        else if (op == 4)
            printf("%lld\n",que_kth(x));
        else if (op == 5)
            printf("%lld\n",que_pre(x));
        else
            printf("%lld\n",que_suf(x));
    }
    return 0;
}