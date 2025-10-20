#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 2e5 + 5;
int n,q,idx;
int a[maxn],v[maxn];
int lft[maxn],rht[maxn],vec[maxn];
map<int,int> apr;
set<int> st[maxn];
void add(int p,int x)
{
    apr[v[p]]--;
    if (!apr[v[p]])
        apr.erase(v[p]);
    st[v[p]].erase(p);
    v[p] += x;
    apr[v[p]]++;
    st[v[p]].insert(p);
}
signed main()
{
    scanf("%d%d",&n,&q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",a + i);
        v[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        apr[v[i]]++;
        st[v[i]].insert(i);
    }
    int p,x,ans,vmax;
    while (q--)
    {
        scanf("%d%d",&p,&x);
        add(a[p],-1);
        add(a[p] = x,1);
        idx = ans = 0;
        for (auto [u,v] : apr)
            if (u)
                vec[++idx] = u;
        vmax = vec[idx];
        for (int i = 1; i <= idx; i++)
        {
            lft[i] = *st[vec[i]].begin();
            rht[i] = *st[vec[i]].rbegin();
        }
        for (int i = idx - 1; i; i--)
            rht[i] = max(rht[i],rht[i + 1]);
        for (int i = 1,j = idx; i <= idx; i++)
        {
            while (j && vec[i] + vec[j] >= vmax)
                j--;
            ans = max(ans,rht[++j] - lft[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}