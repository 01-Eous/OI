#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x))
using namespace std;
const int maxn = 2e5 + 5;
int n,m,ans;
int p[maxn];
struct Node
{
    int k,p;
    friend bool operator>(const Node x,const Node y){return sq(x.k) * x.p > sq(y.k) * y.p;}
};
priority_queue<Node,vector<Node>,greater<Node>>q;
int calc(int x){return (__int128)x * (x + 1) * (2 * x + 1) / 6;}
int find(int x,int p)
{
    int l = 1,r = 1e6,mid,ret = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (calc(mid) * p <= x)
        {
            ret = max(ret,mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ret;
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%lld",&p[i]);
    sort(p + 1,p + n + 1);
    n = unique(p + 1,p + n + 1) - p - 1;
    for (int i = 1; i <= n; i++)
        q.push({1,p[i]});
    while (1)
    {
        auto [k,p] = q.top();
        q.pop();
        int tmp = find(min(m,calc(q.top().k) * q.top().p),p);
        if (!tmp)
            break;
        ans += tmp;
        m -= calc(tmp) * p;
        q.push({tmp,p});
    }
    cout << ans;
    return 0;
}