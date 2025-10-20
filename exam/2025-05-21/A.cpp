#include<bits/extc++.h>
using namespace std;
int n;
int a[5005],b[5005];
void change(int x)
{
    swap(a[x + 1],a[x + 2]);
    swap(a[x],a[x + 1]);
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",b + i);
        int pos = 0;
        for (int j = i; j <= n; j++)
        {
            if (a[j] == b[i])
            {
                pos = j;
                break;
            }
        }
        if (!pos)
            return puts("No"),0;
        while (a[i] != b[i])
        {
            if (pos - 2 < i)
            {
                if (pos + 1 > n)
                    return puts("No"),0;
                change(pos++ - 1);
            }
            else
                change(pos -= 2);        
        }
    }
    puts("Yes");
    return 0;
}