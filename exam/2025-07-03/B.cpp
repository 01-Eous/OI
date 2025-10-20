#include<bits/extc++.h>
using namespace std;
int n;
int dp[3005][3005];
int a[9005],maxc[3005];
vector<array<int,3>> vec;
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n * 3; i++)
        scanf("%d",a + i);
    memset(dp,~0x3f,sizeof(dp));
    memset(maxc,~0x3f,sizeof(maxc));
    int cnt = 0,ans = 0;
    dp[a[1]][a[2]] = dp[a[2]][a[1]] = 0;
    maxc[a[1]] = maxc[a[2]] = 0;
    for (int i = 3; i < n * 3; i += 3)
    {
        vec.clear();
        int u = a[i],v = a[i + 1],w = a[i + 2];
        if (u == v && v == w)
        {
            cnt++;
            continue;
        }
        else if (u == v || v == w || u == w)
        {
            int x = u ^ v ^ w,y = (u + v + w - x) >> 1;
            for (int j = 1; j <= n; j++)
                vec.push_back({x,j,dp[y][j] + 1});
            vec.push_back({y,y,dp[x][x] + 1});
        }
        else
        {
            vec.push_back({u,v,dp[w][w] + 1});
            vec.push_back({u,w,dp[v][v] + 1});
            vec.push_back({v,w,dp[u][u] + 1});
        }
        vec.push_back({u,v,ans});
        vec.push_back({u,w,ans});
        vec.push_back({v,w,ans});
        for (int j = 1; j <= n; j++)
        {
            vec.push_back({u,j,maxc[j]});
            vec.push_back({v,j,maxc[j]});
            vec.push_back({w,j,maxc[j]});
        }
        for (auto [x,y,z] : vec)
        {
            dp[x][y] = dp[y][x] = max(dp[x][y],z);
            ans = max(ans,dp[x][y]);
            maxc[x] = max(maxc[x],dp[x][y]);
            maxc[y] = max(maxc[y],dp[x][y]);
        }
    }
    ans = max(ans,dp[a[n * 3]][a[n * 3]] + 1);
    printf("%d",ans + cnt);
    return 0;
}