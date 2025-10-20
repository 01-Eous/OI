// 脑筋急转弯题目
#include<bits/extc++.h>
using namespace std;
int n;
int a[2005][2005],b[5][5];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    int sum = 0;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> b[i][j];
            sum += b[i][j];
        }
    }
    if (sum != b[1][1])
        memset(a,0,sizeof(a));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << ".00000 ";
        cout << endl;
    }
    return 0;
}