#include<bits/extc++.h>
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 1e5 + 5;
int n,tim,cnt;
int root[maxn],pos[maxn];
struct Nahida
{
    char val;
    int lson,rson;
}tree[maxn * 18];
int clone(int rt)
{
    tree[++cnt] = tree[rt];
    return cnt;
}
int upd(int x,char y,int l,int r,int rt)
{
    rt = clone(rt);
    if (l == r)
    {
        tree[rt].val = y;
        return rt;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        ls = upd(x,y,l,mid,ls);
    else
        rs = upd(x,y,mid + 1,r,rs);
    return rt;
}
char que(int x,int l,int r,int rt)
{
    if (l == r)
        return tree[rt].val;
    int mid = (l + r) >> 1;
    if (x <= mid)
        return que(x,l,mid,ls);
    else
        return que(x,mid + 1,r,rs);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    char op,ch;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        if (op == 'T')
        {
            cin >> ch;
            tim++;
            pos[tim] = pos[tim - 1] + 1;
            root[tim] = upd(pos[tim],ch,1,n,root[tim - 1]);
        }
        else if (op == 'U')
        {
            cin >> x;
            tim++;
            pos[tim] = pos[tim - 1 - x];
            root[tim] = root[tim - 1 - x];
        }
        else
        {
            cin >> x;
            cout << que(x,1,n,root[tim]) << '\n';
        }
    }
    return 0;
}