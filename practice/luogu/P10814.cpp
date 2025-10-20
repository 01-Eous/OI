#include<bits/extc++.h>
#define lowbit(x) ((x) & -(x))
using namespace std;
const int maxn = 2e6 + 5;
int n,m;
int a[maxn],tree[maxn];
int l[maxn],r[maxn],x[maxn],ans[maxn];
vector<pair<int,char>> q[maxn];
void read(int &x)
{
    char f = 1,ch = getchar();x = 0;
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
void upd(int i,int x)
{
    for (; i <= 2e6; i += lowbit(i))
        tree[i] += x;
}
int que(int i)
{
    int res = 0;
    for (; i; i -= lowbit(i))
        res += tree[i];
    return res;
}
signed main()
{
    read(n),read(m);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    for (int i = 1; i <= m; i++)
    {
        read(l[i]),read(r[i]),read(x[i]);
        q[l[i] - 1].push_back({i,-1});
        q[r[i]].push_back({i,1});
    }
    for (int i = 1; i <= n; i++)
    {
        upd(a[i],1);
        for (auto &[id,f] : q[i])
            ans[id] += f * que(x[id]);
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n",ans[i]);
    return 0;
}