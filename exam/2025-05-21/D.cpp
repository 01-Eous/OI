#include<bits/extc++.h>
using namespace std;
using pii = pair<int,int>;
const int maxn = 1e6 + 5;
int n;
int a[maxn];
void solve(int t)
{
    if (t == 1)
    {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++)
            scanf("%d",a + i);
    }
    else
    {
        scanf("%d",&t);
        int u,v;
        while (t--)
        {
            scanf("%d%d",&u,&v);
            a[u] = v;
        }
    }
    deque<pii> q1,q2;
    for (int i = 1; i <= n; i++)
        q1.push_back({a[i],i});
    int ans = 0;
    while ("Love Nahida")
    {
        if (q1.size() + q2.size() == 2)
        {
            ans = 1;
            break;
        }
        int x,y,tmp = q1.front().first;
        q1.pop_front();
        if (q2.empty() || (!q1.empty() && q1.back() > q2.back()))
        {
            x = q1.back().first;
            y = q1.back().second;
            q1.pop_back();
        }
        else
        {
            x = q2.back().first;
            y = q2.back().second;
            q2.pop_back();
        }
        pii cur = {x - tmp,y};
        if (q1.empty() || cur < q1.front())
        {
            ans = q1.size() + q2.size() + 2;
            int cnt = 0;
            while ("Love Nahida")
            {
                cnt++;
                if (q1.size() + q2.size() == 1)
                {
                    ans -= !(cnt & 1);
                    break;
                }
                if (q2.empty() || (!q1.empty() && q1.back() > q2.back()))
                {
                    x = q1.back().first;
                    y = q1.back().second;
                    q1.pop_back();
                }
                else
                {
                    x = q2.back().first;
                    y = q2.back().second;
                    q2.pop_back();
                }
                cur = {x - cur.first,y};
                if ((!q1.empty() && cur > q1.front()) || (!q2.empty() && cur > q2.front()))
                {// 我们当中出现了一个叛徒
                    ans -= !(cnt & 1);
                    break;
                }
            }
            break;
        }
        else
            q2.push_front(cur);
    }
    printf("%d\n",ans);
}
signed main()
{
    int t;
    scanf("%d",&t);
    for (int i = 1; i <= t; i++)
        solve(i);
    return 0;
}