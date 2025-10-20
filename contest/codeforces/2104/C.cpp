#include<bits/extc++.h>
using namespace std;
int n;
char s[55];
set<int> a,b;
bool chk(int x,int y)
{
    if (x == 1 && y == n)
        return 1;
    else if (x == n && y == 1)
        return 0;
    else if (x > y)
        return 1;
    return 0;
}
void solve()
{
    scanf("%d%s",&n,s + 1);
    a.clear(),b.clear();
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'A')
            a.insert(i);
        else
            b.insert(i);
    }
    bool tot = 0;
    for (auto i : a)
    {
        bool fl = 0;
        for (int j : b)
            fl |= chk(j,i);
        tot |= !fl;
    }
    if (tot)
        puts("Alice");
    else
        puts("Bob");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}