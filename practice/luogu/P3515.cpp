#include<bits/extc++.h>
using namespace std;
using ld = double;
const int maxn = 5e5 + 5;
int n;
int a[maxn];
double sqr[maxn],dp[maxn];
ld w(int i,int j){return a[j] + sqr[i - j];}
void calc(int l,int r,int L,int R)
{
    if (l > r)
        return;
    int mid = (l + r) >> 1,p = 0;
    ld max1 = 0;
    for (int i = L; i <= min(mid,R); i++)
    {
        if (w(mid,i) > max1)
        {
            max1 = w(mid,i);
            p = i;
        }
    }
    dp[mid] = max(dp[mid],max1);
    calc(l,mid - 1,L,p);
    calc(mid + 1,r,p,R);
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",a + i);
        sqr[i] = sqrt(i);
    }
    calc(1,n,1,n);
    reverse(a + 1,a + n + 1);
    reverse(dp + 1,dp + n + 1);
    calc(1,n,1,n);
    reverse(a + 1,a + n + 1);
    reverse(dp + 1,dp + n + 1);
    for (int i = 1; i <= n; i++)
        printf("%d\n",(int)ceil(dp[i]) - a[i]);
    return 0;
}