#include<bits/extc++.h>
#define int long long
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1 << 21,stdin),p1 == p2) ? EOF : *p1++)
using namespace std;
const int maxn = 1e6 + 5;
char *p1,*p2,buf[1 << 23];
int n,k;
int a[maxn],b[maxn];
int pos[maxn],buc[maxn];
void read(int &x)
{
    x = 0;
    char f = 1,ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
namespace bit
{
    int tree[maxn];
    int lowbit(const int &x){return x & -x;}
    void upd(int i,int x)
    {
        for (; i; i -= lowbit(i))
            tree[i] += x;
    }
    int que(int i)
    {
        int res = 0;
        for (; i <= n; i += lowbit(i))
            res += tree[i];
        return res;
    }
}
namespace sgt
{
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    int tree[maxn << 2];
    void upd(int x,int l = 1,int r = n,int rt = 1)
    {
        tree[rt]++;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        if (x <= mid)
            upd(x,l,mid,ls);
        else
            upd(x,mid + 1,r,rs);
    }
    int que_sum(int ql,int qr,int l = 1,int r = n,int rt = 1)
    {
        if (ql <= l && r <= qr)
            return tree[rt];
        int mid = (l + r) >> 1,res = 0;
        if (ql <= mid)
            res += que_sum(ql,qr,l,mid,ls);
        if (qr > mid)
            res += que_sum(ql,qr,mid + 1,r,rs);
        return res;
    }
    int que_kth(int k,int l = 1,int r = n,int rt = 1)
    {
        if (l == r)
            return l;
        int mid = (l + r) >> 1,tmp = tree[ls];
        if (k <= tmp)
            return que_kth(k,l,mid,ls);
        else
            return que_kth(k - tmp,mid + 1,r,rs);
    }
    #undef ls
    #undef rs
}
signed main()
{
    read(n),read(k);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        pos[a[i]] = i;
        buc[b[i] = bit::que(a[i])]++;
        bit::upd(a[i],1);
    }

    int r = 0;
    for (int i = 1,j = 0; i <= n; i++)
    {
        int tmp = n - (j += buc[i - 1]);
        if (k < tmp)
            goto Nahida;
        k -= tmp,r++;
    }
    if (!k)
        goto Nahida;
    puts("Impossible!");
    return 0;

    Nahida:
    for (int i = n; i >= 1; i--)
    {
        int u = sgt::que_sum(1,pos[i]),v = sgt::que_sum(pos[i],n);
        if (r <= u)
            a[pos[i] - r] = i;
        else if (r <= u + v)
            a[sgt::que_kth(r) - r] = i;
        else
            a[n - u - v] = i;
        sgt::upd(pos[i]);
    }
    
    for (int i = 1; i < n && k; i++)
        if (a[i] > a[i + 1])
            swap(a[i],a[i + 1]),k--;
    
    for (int i = 1; i <= n; i++)
        printf("%lld ",a[i]);
    return 0;
}