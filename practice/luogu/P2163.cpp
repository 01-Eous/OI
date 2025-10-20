#include<cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<iostream>
#define lowbit(x) (x & -x)
using namespace std;
const int maxn = 5e5 + 5;
const int maxm = 1e7 + 5;
int n,m,idx;
pair<int,int>a[maxn];
int tree[maxm],ans[maxn];
struct query{int x,y,id,f;};
bool operator<(query x,query y){return x.x ^ y.x ? x.x < y.x : x.y < y.y;}
vector<query>q;
void upd(int i,int val)
{
    for (; i <= n; i += lowbit(i))
        tree[i] += val;
}
int que(int i)
{
    int ret = 0;
    for (; i; i -= lowbit(i))
        ret += tree[i];
    return ret;
}
signed main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1,x,y; i <= n; i++)
    {
        scanf("%d%d",&x,&y);
        a[i] = {x + 1,y + 1};
    }
    sort(a + 1,a + n + 1);
    int x0,x1,y0,y1;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
        x0++,y0++,x1++,y1++;
        q.push_back({x0 - 1,y0 - 1,i,1});
        q.push_back({x1,y1,i,1});
        q.push_back({x0 - 1,y1,i,-1});
        q.push_back({x1,y0 - 1,i,-1});
    }
    sort(q.begin(),q.end());
    int idx = 1;
    for (auto [x,y,id,f] : q)
    {
        while (idx <= n && a[idx].first <= x)
            upd(a[idx++].second,1);
        ans[id] += f * que(y);
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n",ans[i]);
    return 0;
}