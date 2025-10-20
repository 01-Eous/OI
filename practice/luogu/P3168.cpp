#include<bits/extc++.h>
#define int long long
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 1e5 + 5;
int n,nn,m,cnt;
int root[maxn],num[maxn];
vector<pair<int,char>> t[maxn];
struct Nahida
{
    int sum,val;
    int lson,rson;
}tree[maxn * 50];
int clone(int rt)
{
    tree[++cnt] = tree[rt];
    return cnt;
}
int upd(int pos,int f,int l,int r,int rt)
{
    rt = clone(rt);
    tree[rt].val += f,tree[rt].sum += f * num[pos];
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        ls = upd(pos,f,l,mid,ls);
    else
        rs = upd(pos,f,mid + 1,r,rs);
    return rt;
}
int que(int rt,int l,int r,int k)
{
    if (l == r)
        return tree[rt].sum / tree[rt].val * k;
    int mid = (l + r) >> 1;
    if (k <= tree[ls].val)
        return que(ls,l,mid,k);
    else
        return tree[ls].sum + que(rs,mid + 1,r,k - tree[ls].val);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    int s,e,p;
    while (m--)
    {
        cin >> s >> e >> p;
        num[++nn] = p;
        t[s].push_back({p,1});
        t[e + 1].push_back({p,-1});
    }
    sort(num + 1,num + nn + 1);
    nn = unique(num + 1,num + nn + 1) - num - 1;
    for (int i = 1; i <= n; i++)
    {
        root[i] = root[i - 1];
        for (auto &[p,f] : t[i])
        {
            int pos = lower_bound(num + 1,num + nn + 1,p) - num;
            root[i] = upd(pos,f,1,nn,root[i]);
        }
    }
    int x,a,b,c,k,lst = 1;
    while (n--)
    {
        cin >> x >> a >> b >> c;
        k = (a * lst + b) % c + 1;
        if (k > tree[root[x]].val)
            cout << (lst = tree[root[x]].sum) << '\n';
        else
            cout << (lst = que(root[x],1,nn,k)) << '\n';
    }
    return 0;
}