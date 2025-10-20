#include<bits/extc++.h>
using namespace std;
int mp[100];
int idx;
signed main()
{
    for (int i = 99; i > 0; i -= 2)
        mp[i] = ++idx;
    for (int i = 0; i < 100; i += 2)
        mp[i] = ++idx;
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",abs(mp[b] - mp[a]) - 1);
    return 0;
}