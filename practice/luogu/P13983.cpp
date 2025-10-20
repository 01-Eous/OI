#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n,len,blo;
int a[maxn],id[maxn],tag[maxn];
int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1;ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48);ch = getchar();}
    return x * f;
}
void push_down(int id)
{
    if (tag[id] == -1)
        return;
    for (int i = (id - 1) * len + 1; i <= min(n,len * id); i++)
        a[i] = tag[id];
    tag[id] = -1;
}
inline int solve(int l,int r,int x)
{
    int lid = id[l];
    int rid = id[r];
    int res = 0;
    push_down(lid);
    if (lid == rid)
    {
        for (int i = l; i <= r; i++)
        {
            if (a[i] == x)
                res++;
            else
                a[i] = x;
        }
        // return res;
    }
    else
    {
        for (int i = l; id[i] == lid; i++)
        {
            if (a[i] == x)
                res++;
            else
                a[i] = x;
        }
        push_down(rid);
        for (int i = r; id[i] == rid; i--)
        {
            if (a[i] == x)
                res++;
            else
                a[i] = x;
        }
        for (int i = lid + 1; i <= rid - 1; i++)
        {
            if (tag[i] == -1)
            {
                int st = (i - 1) * len + 1;
                int en = min(n,i * len);
                for (int i = st; i <= en; i++)
                {
                    if (a[i] == x)
                        res++;
                    else
                        a[i] = x;
                }
                tag[i] = x;
            }
            else
            {
                if (tag[i] == x)
                    res += len;
                else
                    tag[i] = x;
            }
        }
    }
    return res;
}
signed main()
{
    n = read();
    len = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        id[i] = (i - 1) / len + 1;
    }
    memset(tag,-1,sizeof tag);
    for (int i = 1,l,r,x; i <= n; i++)
    {
        l = read(),r = read(),x = read();
        printf("%d\n",solve(l,r,x));
    }
    return 0;
}