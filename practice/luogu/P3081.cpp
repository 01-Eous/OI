#include<iostream>
#include<algorithm>
#include<set>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n;
struct line{int x1,y1,x2,y2,id;}ln[maxn];
struct query{int x,y,id;}que[maxn << 1];
inline bool operator<(const line &x,const line &y)
{
    if (x.x2 < y.x2)
        return (x.y2 - y.y1) * (y.x2 - y.x1) < (y.y2 - y.y1) * (x.x2 - y.x1);
    else
        return (y.y2 - x.y1) * (x.x2 - x.x1) > (x.y2 - x.y1) * (y.x2 - x.x1);
}
inline bool operator<(const query &x,const query &y)
{return x.x ^ y.x ? x.x < y.x : x.y < y.y;}
inline void read(int &x)
{
    x = 0; int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
set<line>st;
signed main()
{
    read(n);
    for (int i = 1; i <= n; i++)
    {
        read(ln[i].x1),read(ln[i].y1);
        read(ln[i].x2),read(ln[i].y2);
        ln[i].id = i;
        que[(i << 1) - 1].x = ln[i].x1;
        que[i << 1].x = ln[i].x2;
        que[(i << 1) - 1].y = ln[i].y1;
        que[i << 1].y = ln[i].y2;
        que[(i << 1) - 1].id = que[i << 1].id = i;
    }
    st.insert(ln[1]);
    sort(que + 1,que + (n << 1) + 1);
    int pos = 1,ans = 1;
    for (int i = 2; i <= (n << 1); i++)
    {
        query tt = que[i];
        line te = ln[tt.id];
        if (tt.x == te.x1)
            st.insert(te);
        else if (tt.id == pos)
        {
            auto p1 = st.find(te);
            if (p1 == st.begin())
                break;
            auto p2 = p1;
            pos = (--p2)->id;
            st.erase(p1);
            ans++;
        }
        else
            st.erase(te);
    }
    printf("%lld",ans);
    return 0;
}