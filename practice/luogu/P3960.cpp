#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 3e5 + 5;
int n,m,q,up;
pii a[maxn];
int tree[maxn * 2],pos[maxn];
vector<int> vec[maxn];
vector<pii> qry[maxn];
int lowbit(int x){return x & -x;}
void upd(int i,int x)
{
    for (; i <= up; i += lowbit(i))
        tree[i] += x;
}
int que(int i)
{
    int res = 0;
    for (; i; i -= lowbit(i))
        res += tree[i];
    return res;
}
int bin(int x)
{
    int l = 1,r = up,mid,res = up;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (que(mid) >= x)
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    up = max(n,m) + q;
    for (int i = 1; i <= q; i++)
    {
        auto &[x,y] = a[i];
        cin >> x >> y;
        if (y != m)
            qry[x].push_back({y,i});
    }
    for (int i = 1; i <= up; i++)
        upd(i,1);
    for (int i = 1; i <= n; i++)
    {
        for (auto [x,id] : qry[i])
        {
            pos[id] = bin(x);
            upd(pos[id],-1);
        }
        for (auto [x,id] : qry[i])
            upd(pos[id],1);
    }
    for (int i = 1; i <= q; i++)
    {
        auto [x,y] = a[i];
        int ans,lst,tmp = bin(x);
        upd(tmp,-1);
        if (tmp <= n)
            lst = tmp * m;
        else
            lst = vec[0][tmp - n - 1];
        if (y != m)
        {
            vec[x].push_back(lst);
            if (pos[i] < m)
                ans = (x - 1) * m + pos[i];
            else
                ans = vec[x][pos[i] - m];
        }
        else
            ans = lst;
        vec[0].push_back(ans);
        cout << ans << '\n';
    }
    return 0;
}