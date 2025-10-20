#include<bits/extc++.h>
using namespace std;
typedef double ld;
int n;
signed main()
{
    scanf("%d",&n);
    vector<ld> dp1(n + 5),dp2(n + 5);
    dp1[n] = dp2[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        dp1[i] = dp1[i + 1] + (ld)n / (n - i);
        dp2[i] = (ld)i / (n - i) * dp1[i] + dp1[i + 1] + dp2[i + 1] + (ld)n / (n - i);
    }
    printf("%.2lf",dp2[0]);
    return 0;
}