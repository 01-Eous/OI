#include<bits/extc++.h>
#define chk(x,y) (x >= 1 && x <= n && y >= 1 && y <= m)
using namespace std;
using pii = pair<int,int>;
int n,m,q;
pii dir[15];
bool vis[105][105];
int a[105][105],pre[105][105];
stack<pii> stk;
multiset<int,greater<>> st;
pii operator+(const pii &x,const pii &y)
{return {x.first + y.first,x.second + y.second};}
int calc(pii p1,pii p2)
{
    set<pii> vec;
    for (int i = 1; i <= q; i++)
        if (auto [tx,ty] = p1 + dir[i]; chk(tx,ty))
            vec.insert({tx,ty});
    for (int i = 1; i <= q; i++)
        if (auto [tx,ty] = p2 + dir[i]; chk(tx,ty))
            vec.insert({tx,ty});
    int res = 0;
    for (auto [tx,ty] : vec)
        res += a[tx][ty];
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            a[i][j] = ch - '0';
        }
    }
    for (int i = 1; i <= q; i++)
        cin >> dir[i].first >> dir[i].second;
    sort(dir + 1,dir + q + 1);
    q = unique(dir + 1,dir + q + 1) - dir - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= q; k++)
            {
                auto [tx,ty] = pii{i,j} + dir[k];
                if (!chk(tx,ty))
                    continue;
                pre[i][j] += a[tx][ty];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            st.insert(pre[i][j]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k1 = 1; k1 <= q; k1++)
            {
                for (int k2 = 1; k2 <= q; k2++)
                {
                    auto [tx,ty] = pii{i,j} + dir[k1];
                    tx -= dir[k2].first,ty -= dir[k2].second;
                    if (!chk(tx,ty) || vis[tx][ty])
                        continue;
                    vis[tx][ty] = 1;
                    stk.push({tx,ty});
                    st.erase(st.find(pre[tx][ty]));
                }
            }
            if (!st.empty())
                ans = max(ans,pre[i][j] + *st.begin());
            while (!stk.empty())
            {
                auto [tx,ty] = stk.top();
                stk.pop();
                vis[tx][ty] = 0;
                st.insert(pre[tx][ty]);
                ans = max(ans,calc({i,j},{tx,ty}));
            }
        }
    }
    cout << ans;
    return 0;
}