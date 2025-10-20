#include<bits/extc++.h>
#define int long long
#define ls rt << 1
#define rs rt << 1 | 1
using namespace std;
const int maxn = 1e6 + 5;
mt19937 rnd(random_device{}());
int n,q;
int tree[maxn << 2];
void upd(int pos,int val,int l = 1,int r = n,int rt = 1)
{
    tree[rt] += val;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,val,l,mid,ls);
    else
        upd(pos,val,mid + 1,r,rs);
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
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1,x,y; i <= q; i++)
    {
        cin >> x >> y;
        if (x > y)
            swap(x,y);
        if (!que(x,y) || !(que(1,x) + que(y,n)))
        {
            int tmp = rnd();
            upd(x,tmp),upd(y,-tmp);
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }
    return 0;
}