#include<bits/extc++.h>
using namespace std;
const int maxn = 4e5 + 5;
int n;
int ans[maxn];
bool vis[maxn];
set<int> st;
void solve()
{
    scanf("%d",&n);
    memset(vis,0,sizeof(bool) * ((n << 1) + 5));
    for (int i = 1; i <= n << 1; i++)
        st.insert(i);
    int x = n;
    while (!st.empty())
    {
        int p1 = 0,p2 = 0;
        for (auto i : st)
        {
            for (int j = i + x; j <= n << 1; j += x)
            {
                if (!vis[j])
                {
                    p1 = i,p2 = j;
                    break;
                }
            }
            if (p1 || p2)
                break;
        }
        ans[p1] = ans[p2] = x--;
        st.erase(p1),st.erase(p2);
        vis[p1] = vis[p2] = 1;
    }
    for (int i = 1; i <= n << 1; i++)
        printf("%d%c",ans[i]," \n"[i == n << 1]);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}