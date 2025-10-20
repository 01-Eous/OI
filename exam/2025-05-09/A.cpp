#include<bits/extc++.h>
#define int unsigned
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
bool st;
const int maxn = 5e4 + 5;
int n,m,cnt;
int a[maxn],root[maxn];
struct Nahida
{
    int val,sum;
    int lson,rson;
}tree[maxn * 20];
int clone(int rt)
{
    tree[++cnt] = tree[rt];
    return cnt;
}
int upd(int x,int l,int r,int rt)
{
    rt = clone(rt);
    tree[rt].val++;
    tree[rt].sum += x;
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    if (x <= mid)
        ls = upd(x,l,mid,ls);
    else
        rs = upd(x,mid + 1,r,rs);
    return rt;
}
int que_sum(int ql,int qr,int l,int r,int L,int R)
{
    if (ql > qr)
        return 0;
    if (ql <= l && r <= qr)
        return tree[R].sum - tree[L].sum;
    int mid = (l + r) >> 1;
    int res = 0;
    if (ql <= mid)
        res += que_sum(ql,qr,l,mid,tree[L].lson,tree[R].lson);
    if (qr > mid)
        res += que_sum(ql,qr,mid + 1,r,tree[L].rson,tree[R].rson);
    return res;
}
int que_val(int ql,int qr,int l,int r,int L,int R)
{
    if (ql > qr)
        return 0;
    if (ql <= l && r <= qr)
        return tree[R].val - tree[L].val;
    int mid = (l + r) >> 1;
    int res = 0;
    if (ql <= mid)
        res += que_val(ql,qr,l,mid,tree[L].lson,tree[R].lson);
    if (qr > mid)
        res += que_val(ql,qr,mid + 1,r,tree[L].rson,tree[R].rson);
    return res;
}
int que_kth(int k,int l,int r,int L,int R)// 在区间 (L,R] 内
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    int tmp = tree[tree[R].lson].val - tree[tree[L].lson].val;
    if (k <= tmp)
        return que_kth(k,l,mid,tree[L].lson,tree[R].lson);
    else
        return que_kth(k - tmp,mid + 1,r,tree[L].rson,tree[R].rson);
}
bool ed;
signed main()
{
    scanf("%u%u",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%u",a + i);
        root[i] = upd(a[i],1,5e4,root[i - 1]);
    }
    int l,r;
    while (m--)
    {
        scanf("%u%u",&l,&r);
        int len = r - l + 1;
        int lft = (len + 1) >> 1,rht = len - lft;
        int val = que_kth(lft,1,5e4,root[l - 1],root[r]);
        lft = que_val(1,val - 1,1,5e4,root[l - 1],root[r]),rht = que_val(val + 1,5e4,1,5e4,root[l - 1],root[r]);
        int suml = que_sum(1,val - 1,1,5e4,root[l - 1],root[r]),sumr = que_sum(val + 1,5e4,1,5e4,root[l - 1],root[r]);
        printf("%u\n",val * lft - suml + sumr - val * rht);
    }
    return 0;
}