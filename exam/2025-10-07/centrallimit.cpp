#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e4 + 5;
const int mod = 998244353;
const int dx[] = {1,-1,1,-1,2,2,-2,-2};
const int dy[] = {2,2,-2,-2,1,-1,1,-1};
int n,m;
int x[maxn],y[maxn];
bool mp[1005][1005];
int cnt[1005][1005],dp[1005][1005][4];
bool bound(int x,int y){return 0 <= x && x <= n && 0 <= y && y <= n;}
void add(int &x,const int &y)
{
    if (x += y; x >= mod)
        x -= mod;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x[i] >> y[i];
        mp[x[i]][y[i]] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        if (bound(x[i],y[i] + 1) && !mp[x[i]][y[i] + 1])
        {
            for (int j = 0; j < 2; j++)
            {
                int tx = x[i] + dx[j],ty = y[i] + dy[j];
                if (bound(tx,ty))
                    cnt[tx][ty]++;
            }
        }
        if (bound(x[i],y[i] - 1) && !mp[x[i]][y[i] - 1])
        {
            for (int j = 2; j < 4; j++)
            {
                int tx = x[i] + dx[j],ty = y[i] + dy[j];
                if (bound(tx,ty))
                    cnt[tx][ty]++;
            }
        }
        if (bound(x[i] + 1,y[i]) && !mp[x[i] + 1][y[i]])
        {
            for (int j = 4; j < 6; j++)
            {
                int tx = x[i] + dx[j],ty = y[i] + dy[j];
                if (bound(tx,ty))
                    cnt[tx][ty]++;
            }
        }
        if (bound(x[i] - 1,y[i]) && !mp[x[i] - 1][y[i]])
        {
            for (int j = 6; j < 8; j++)
            {
                int tx = x[i] + dx[j],ty = y[i] + dy[j];
                if (bound(tx,ty))
                    cnt[tx][ty]++;
            }
        }
    }
    if (!cnt[0][0])
        dp[0][0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int tx = i,ty = j;
                int xx = i,yy = j;
                for (int l = 0; l < 2; l++)
                {
                    if ((k >> l) & 1)
                        tx--;
                    else
                        ty--;
                }
                if (k & 1)
                    xx--;
                else
                    yy--;
                if (bound(i,j + 1))
                {
                    if (!cnt[i][j + 1])
                    {
                        if (bound(xx,yy) && mp[xx][yy] && (k & 1))
                        {
                            if ((k >> 1) & 1)
                                yy--;
                            else
                                xx--;
                            if (!bound(xx,yy) || !mp[xx][yy])
                                add(dp[i][j + 1][(k & 1) << 1],dp[i][j][k]);
                        }
                        else
                            add(dp[i][j + 1][(k & 1) << 1],dp[i][j][k]);
                    }
                    else if (cnt[i][j + 1] == 1)
                    {
                        if (bound(tx,ty) && mp[tx][ty] && k)
                        {
                            if (mp[xx][yy])
                            {
                                if (k == 2)
                                    add(dp[i][j + 1][(k & 1) << 1],dp[i][j][k]);
                            }
                            else
                                add(dp[i][j + 1][(k & 1) << 1],dp[i][j][k]);
                        }
                    }
                }
                if (bound(i + 1,j))
                {
                    if (!cnt[i + 1][j])
                    {
                        if (bound(xx,yy) && mp[xx][yy] && !(k & 1))
                        {
                            if ((k >> 1) & 1)
                                yy--;
                            else
                                xx--;
                            if (!bound(xx,yy) || !mp[xx][yy])
                                add(dp[i + 1][j][(k & 1) << 1 | 1],dp[i][j][k]);
                        }
                        else
                            add(dp[i + 1][j][(k & 1) << 1 | 1],dp[i][j][k]);
                    }
                    else if (cnt[i + 1][j] == 1)
                    {
                        if (bound(tx,ty) && mp[tx][ty] && k != 3)
                        {
                            if (mp[xx][yy])
                            {
                                if (k == 1)
                                    add(dp[i + 1][j][(k & 1) << 1 | 1],dp[i][j][k]);
                            }
                            else
                                add(dp[i + 1][j][(k & 1) << 1 | 1],dp[i][j][k]);
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; i++)
        add(ans,dp[n][n][i]);
    cout << ans;
    return 0;
}