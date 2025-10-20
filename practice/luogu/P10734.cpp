#include<bits/extc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,q;
int fa[maxn];
int find(int u){return fa[u] == u ? u : fa[u] = find(fa[u]);}
void merge(int u,int v)
{
    u = find(u),v = find(v);
    if (u != v)
        fa[u] = v;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    iota(fa + 1,fa + (n << 1) + 1,1);
    char op;
    int x,y;
    while (q--)
    {
        cin >> op >> x >> y;
        if (op == 'A')
        {
            merge(x + n,y);
            merge(x,y + n);
        }
        else if (op == 'R')
        {
            merge(x,y);
            merge(x + n,y + n);
        }
        else
        {
            int tmp = find(x);
            if (tmp == find(y + n))
                cout << "A\n";
            else if (tmp == find(y))
                cout << "R\n";
            else
                cout << "?\n";
        }
    }
    return 0;
}