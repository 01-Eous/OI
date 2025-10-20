#include<bits/extc++.h>
using namespace std;
random_device seed;
int n,a,b,in1,in2;
void solve()
{
    scanf("%d",&n);
    vector<int>x(n + 5);
    vector<bool>apr(n + 5);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&x[i]);
        apr[x[i]] = 1;
    }
    a = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!apr[i])
        {
            a = i;
            break;
        }
    }
    if (a)
    {
        int b = rand() % n + 1;
        while (b == a)
            b = rand() % n + 1;
        printf("? %d %d\n",a,b);
        fflush(stdout);
        scanf("%d",&in1);
        if (!in1)
            printf("! A\n");
        else
            printf("! B\n");
        fflush(stdout);
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (x[i] == 1)
                a = i;
            else if (x[i] == n)
                b = i;
        }
        printf("? %d %d\n",a,b);
        fflush(stdout);
        scanf("%d",&in1);
        printf("? %d %d\n",b,a);
        fflush(stdout);
        scanf("%d",&in2);
        if (in1 == in2 && in1 >= n - 1)
            printf("! B\n");
        else
            printf("! A\n");
        fflush(stdout);
    }
}
signed main()
{
    srand(seed());
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}