#include<bits/extc++.h>
#define sq(x) ((x) * (x))
#define int long long
using namespace std;
int r,ans;
int y(int x){return floor(sqrt(sq(r) - sq(x - 0.5)) + 0.5);}
signed main()
{
    scanf("%lld",&r);
    for (int i = 2; i <= r; i++)
    {
        int tmp = y(i);
        ans += tmp * 2 - 1;
    }
    printf("%lld",ans * 2 + 2 * r - 1);
    return 0;
}