#include<bits/extc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;
const int maxn = 55;
int n,m,k;
int dis = 0;
int _max,_min;
int sum[maxn],a[maxn][maxn];
bool can[maxn];
void nxt(int &x,int &y)
{
    if (dis == 0)
    {
        y++;
        if (y > m)
        {
            y--;
            x++;
            dis ^= 1;
        }
    }
    else
    {
        y--;
        if (y < 1)
        {
            y++;
            x++;
            dis = 0;
        }
    }
}
void process()
{
    memset(sum,0,sizeof sum);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[j] += a[i][j];
    _max = -inf,_min = inf;
    for (int i = 1; i <= m; i++)
    {
        _max = max(_max,sum[i]);
        _min = min(_min,sum[i]);
    }
    memset(can,0,sizeof can);
    vector<int>v;
    for (int j = 1; j <= m; j++)
    {
        if (sum[j] == _max || sum[j] == _min)
        {
            can[j] = 1;
            for (int i = 1; i <= n; i++)
                v.push_back(a[i][j]);
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    auto it = v.begin();
    int i = 1,j = 1;
    while (i <= n)
    {
        a[i][j] = *(it++);
        do
        {
            nxt(i,j);
        } while (!can[j]);
    }
}
signed main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%lld",a[i] + j);
    while (k--)
        process();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%lld ",a[i][j]);
        putchar('\n');
    }
    return 0;
}