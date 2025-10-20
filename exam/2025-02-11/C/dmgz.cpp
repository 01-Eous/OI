#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int a[maxn],rnk[maxn];
vector<int>pos;
vector<pair<int,int>>ans;
signed main()
{
    scanf("%lld%lld",&n,&m);
    pos.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        rnk[a[i]] = i;
        if (a[i] == i)
            pos.push_back(i);
    }
    pos.push_back(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == i)
            continue;
        int l = upper_bound(pos.begin(),pos.end(),min(a[i],i)) - pos.begin();
        int r = lower_bound(pos.begin(),pos.end(),max(a[i],i)) - pos.begin() - 1;
        if (l <= r)
        {
            puts("NO");
            goto end;
        }
    }
    puts("YES");
    for (int i = 0; i < pos.size() - 1; i++)
    {
        int l = pos[i] + 1,r = pos[i + 1] - 1;
        for (int x = l; x <= r; x++)
        {
            bool fl = 0;
            int tmp = rnk[x];
            for (int j = x; j < tmp; j++)
            {
                if (a[j] != j + 1)
                    fl = 1;
                else if (fl)
                {
                    swap(rnk[a[j]],rnk[a[j - 1]]);
                    swap(a[j],a[j - 1]);
                    ans.push_back({j,j - 1});
                }
            }
            for (int j = tmp; j > x; j--)
            {   
                swap(rnk[a[j]],rnk[a[j - 1]]);
                swap(a[j],a[j - 1]);
                ans.push_back({j,j - 1});
            }
        }
    }
    printf("%llu\n",ans.size());
    for (auto &[a,b] : ans)
        printf("%lld %lld\n",a,b);
    end:return 0;
}