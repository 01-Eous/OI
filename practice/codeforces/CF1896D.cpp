// 114514
#include<bits/extc++.h>
#define ls rt << 1
#define rs rt << 1 | 1
using namespace std;
const int maxn = 1e5 + 5;
int n,q;
int a[maxn],tree[maxn << 2];
void build(int l,int r,int rt)
{
    if (l == r)
    {
        tree[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    tree[rt] = tree[ls] + tree[rs];
}
void upd(int pos,int x,int l = 1,int r = n,int rt = 1)
{
    if (l == r)
    {
        tree[rt] += x;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,x,l,mid,ls);
    else
        upd(pos,x,mid + 1,r,rs);
    tree[rt] = tree[ls] + tree[rs];
}
int que(int ql,int qr,int l = 1,int r = n,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt];
    int mid = (l + r) >> 1,res = 0;
    if (ql <= mid)
        res += que(ql,qr,l,mid,ls);
    if (qr > mid)
        res += que(ql,qr,mid + 1,r,rs);
    return res;
}
int bin(int x,int l = 1,int r = n,int rt = 1)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1,tmp = tree[ls];
    if (x <= tmp)
        return bin(x,l,mid,ls);
    else
        return bin(x - tmp,mid + 1,r,rs);
}
void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1,n,1);
    int op,x,y;
    while (q--)
    {
        cin >> op >> x;
        if (op == 1)
        {
            if (x == 1)
            {
                if (que(1,n) != n << 1)
                    cout << "Yes\n";
                else
                    cout << "NO\n";
                continue;
            }
            if (x > que(1,n))
            {
                cout << "NO\n";
                continue;
            }
            int pos = bin(x - 1);
            if (que(1,pos) == x)
            {
                cout << "YES\n";
                continue;
            }
            if (que(1,pos) != x - 1)
            {
                cout << "NO\n";
                continue;
            }
            if (que(1,n - pos) != (n - pos) << 1 || que(pos + 1,n) != (n - pos) << 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            cin >> y;
            upd(x,y - a[x]);
            a[x] = y;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}