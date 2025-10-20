#include<bits/extc++.h>
using namespace std;
void gauss(int n)
{
    for (int i = 0; i <= n; i++)
    {
        int pos = i;
        for (int j = i + 1; j <= n; j++)
            if (fabs(a[pos][i]) < fabs(a[j][i]))
                pos = j;
        swap(a[pos],a[i]);
        ld tmp = a[i][i];
        for (int j = i; j <= n + 1; j++)
            a[i][j] /= tmp;
        for (int j = i + 1; j <= n; j++)
        {
            tmp = a[j][i];
            for (int k = i; k <= n + 1; k++)
                a[j][k] -= tmp * a[i][k];
        }
    }
    ans[n] = a[n][n + 1];
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = a[i][n + 1];
        for (int j = i + 1; j <= n; j++)
            ans[i] -= ans[j] * a[i][j];
    }
}
signed main()
{

    return 0;
}