#include<bits/extc++.h>
#define inf 0x3f3f3f3f
#define chkmax(x,y) (x = max(x,y))
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn],b[maxn];
int pre1[10],pre2[10];
int dp1[maxn],dp2[maxn];
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    for (int i = 1; i <= n; i++)
        scanf("%d",b + i);
    memset(pre1,~0x3f,sizeof(pre1));
    for (int i = 1,tmp,max1; i <= n; i++)
    {
        tmp = a[i],max1 = ~inf;
        while (tmp)
        {
            chkmax(max1,pre2[tmp % 10]);
            tmp /= 10;
        }
        dp1[i] = max1 + 1;

        tmp = b[i],max1 = ~inf;
        while (tmp)
        {
            chkmax(max1,pre1[tmp % 10]);
            tmp /= 10;
        }
        dp2[i] = max1 + 1;

        tmp = a[i];
        while (tmp)
        {
            chkmax(pre1[tmp % 10],dp1[i]);
            tmp /= 10;
        }
        tmp = b[i];
        while (tmp)
        {
            chkmax(pre2[tmp % 10],dp2[i]);
            tmp /= 10;
        }         
    }
    printf("%d",max(*max_element(pre1,pre1 + 10),*max_element(pre2,pre2 + 10)));
    return 0;
}