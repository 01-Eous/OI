#include<bits/extc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int dir[2][2] = {-1,0,0,-1};
int n,m;
char mp[maxn];
int fa[maxn],siz[maxn];
int id(int x,int y){return (x - 1) * n + y;}
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int x,int y)
{
    x = find(x),y = find(y);
    assert(x > 0 && y > 0);
    if (x == y)
        return;
    siz[x] += siz[y];
    fa[y] = x;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fa[id(i,j)] = id(i,j),siz[id(i,j)] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mp[id(i,j)];
            for (int k = 0; k < 2; k++)
            {
                int x = i + dir[k][0],y = j + dir[k][1];
                if (x >= 1 && y >= 1 && mp[id(x,y)] != mp[id(i,j)])
                    merge(id(x,y),id(i,j));
            }
        }
    }
    int x,y;
    while (m--)
    {
        cin >> x >> y;
        cout << siz[find(id(x,y))] << '\n';
    }
    return 0;
}