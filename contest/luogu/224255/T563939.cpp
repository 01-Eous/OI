#include<bits/extc++.h>
using namespace std;
const int maxn = 55;
int n,m;
int a[maxn][maxn],sum[maxn];
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            sum[j] += a[i][j];
        }
    }
    int pos = 0,_max = 0;
    for (int i = 1; i <= m; i++)
    {
        if (sum[i] >= _max)
        {
            _max = sum[i];
            pos = i;
        }
    }
    int cnt = 1;
    _max = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i][pos] > _max)
        {
            cnt = 1;
            _max = a[i][pos];
        }
        else if (a[i][pos] == _max)
            cnt++;
    }
    cout << _max << " " << cnt;
    return 0;
}