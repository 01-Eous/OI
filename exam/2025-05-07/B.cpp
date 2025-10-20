#include<bits/extc++.h>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e6 + 5;
int n;
int a[maxn],col[maxn],d[maxn];
vector<int> lft,rht;
struct Nahida
{
    int val,tag;
    void tag_down(int x){val += x,tag += x;}
}tree[maxn << 2];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + (ch ^ 48); ch = getchar();}
    return x * f;
}
void push_up(int rt){tree[rt].val = max(tree[ls].val,tree[rs].val);}
void push_down(int rt)
{
    int &tag = tree[rt].tag;
    if (!tag)
        return;
    tree[ls].tag_down(tag);
    tree[rs].tag_down(tag);
    tag = 0;
}
void upd(int ql,int qr,int x,int l = 1,int r = n,int rt = 1)
{
    if (ql > qr)
        return;
    if (ql <= l && r <= qr)
        return tree[rt].tag_down(x);
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd(ql,qr,x,l,mid,ls);
    if (qr > mid)
        upd(ql,qr,x,mid + 1,r,rs);
    push_up(rt);
}
signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (tmp < a[i])
        {
            tmp = a[i];
            col[i] = 1;
            lft.push_back(i);
        }
    }
    tmp = n + 1;
    for (int i = n; i >= 1; i--)
    {
        if (tmp > a[i])
        {
            tmp = a[i];
            col[i] = 2;
            rht.push_back(i);
        }
    }
    reverse(rht.begin(),rht.end());
    int l = 0,r = 0,ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 1)
            r = a[i];
        else if (col[i] == 2)
        {
            for (int j = l + 1; j <= a[i]; j++)
                if (d[j])
                    upd(j,d[j],-1);
            l = a[i],ans = max(ans,tree[1].val);
        }
        else
            upd(a[i],d[a[i]] = r,1);
    }
    printf("%d",ans << 1 | 1);
    return 0;
}