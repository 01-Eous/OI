#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,m,q,len = 600;
int col[maxn];
bool fl[maxn];
struct Nahida
{
    int ret;
    vector<int>pos;
    unordered_map<int,int>del;
}a[maxn];
inline void read(int &x)
{
    x = 0; int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
signed main()
{
    read(n),read(m),read(q);
    for (int i = 1; i <= n; i++)
    {
        read(col[i]);
        a[col[i]].ret++;
        a[col[i]].pos.push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (i > 1 && a[col[i - 1]].pos.size() > len)
            a[col[i]].del[col[i - 1]]++;
        if (i < n && a[col[i + 1]].pos.size() > len && col[i + 1] != col[i])
            a[col[i]].del[col[i + 1]]++;
    }
    int x,ans = 0;
    while (m--)
    {
        read(x);
        if (!fl[x])
        {
            fl[x] = 1;
            if (a[x].pos.size() <= len)
            {
                for (auto i : a[x].pos)
                {
                    if (i > 1 && x != col[i - 1])
                        a[col[i - 1]].ret--;
                    if (i < n)
                        a[col[i + 1]].ret--;
                }
            }
            ans += a[x].ret;
            for (auto [u,v] : a[x].del)
                ans -= fl[u] * v;
        }
        else
        {
            ans -= a[x].ret;
            for (auto [u,v] : a[x].del)
                ans += fl[u] * v;
            fl[x] = 0; 
            if (a[x].pos.size() <= len)
            {
                for (auto i : a[x].pos)
                {
                    if (i > 1 && x != col[i - 1])
                        a[col[i - 1]].ret++;
                    if (i < n)
                        a[col[i + 1]].ret++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}