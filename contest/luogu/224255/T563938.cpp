#include<bits/extc++.h>
using namespace std;
int n,m,k;
signed main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1; i <= (n + 1 >> 1); i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (m - (n + 1 >> 1) + 1 <= j && j <= m - (n + 1 >> 1) + i && i <= (n + 1) >> 1)
                putchar('#');
            else if ((n - k) >> 1 < i && j <= m - (n + 1 >> 1) + i)
                putchar('#');
            else
                putchar('.');
        }
        cout << endl;
    }
    for (int i = (n >> 1); i >= 1; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            if (m - (n + 1 >> 1) + 1 <= j && j <= m - (n + 1 >> 1) + i && i <= (n + 1) >> 1)
                putchar('#');
            else if ((n - k) >> 1 < i && j <= m - (n + 1 >> 1) + i)
                putchar('#');
            else
                putchar('.');
        }
        cout << endl;
    }
    return 0;
}