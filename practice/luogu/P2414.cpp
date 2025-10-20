#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,m,tim;
int pos[maxn],root[maxn];
int dfn[maxn],ed[maxn],siz[maxn];
string s;
vector<int> g[maxn];
namespace acm
{
    int cnt;
    struct Nahida{int fa,ch[26],rec[26],fail;}ac[maxn];
    void build(const string &s)
    {
        int rt = 0;
        for (auto ch : s)
        {
            if (ch == 'P')
                pos[++n] = rt;
            else if (ch == 'B')
                rt = ac[rt].fa;
            else
            {
                int dig = ch - 'a';
                if (!ac[rt].ch[dig])
                {
                    ac[rt].ch[dig] = ++cnt;
                    ac[cnt].fa = rt;         
                }
                rt = ac[rt].ch[dig];
            }
        }
    }
    void get_fail()
    {
        queue<int> q;
        for (int i = 0; i < 26; i++)
        {
            if (ac[0].ch[i])
            {
                ac[0].rec[i] = ac[0].ch[i];
                q.push(ac[0].ch[i]);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            g[ac[u].fail].push_back(u);
            for (int i = 0; i < 26; i++)
            {
                int &v = ac[u].ch[i];
                if (v)
                {
                    ac[u].rec[i] = ac[u].ch[i];
                    ac[v].fail = ac[ac[u].fail].rec[i];
                    q.push(v);
                }
                else
                    ac[u].rec[i] = ac[ac[u].fail].rec[i];
            }
        }
    }   
}
namespace sgt
{
    int cnt;
    struct Nahida{int val,lson,rson;}tree[maxn << 5];
    #define ls tree[rt].lson
    #define rs tree[rt].rson
    int clone(int rt)
    {
        tree[++cnt] = tree[rt];
        return cnt;
    }
    int upd(int x,int l,int r,int rt)
    {
        rt = clone(rt);
        tree[rt].val++;
        if (l == r)
            return rt;
        int mid = (l + r) >> 1;
        if (x <= mid)
            ls = upd(x,l,mid,ls);
        else
            rs = upd(x,mid + 1,r,rs);
        return rt;
    }
    int que(int ql,int qr,int l,int r,int rt)
    {
        if (ql <= l && r <= qr)
            return tree[rt].val;
        int mid = (l + r) >> 1,res = 0;
        if (ql <= mid)
            res += que(ql,qr,l,mid,ls);
        if (qr > mid)
            res += que(ql,qr,mid + 1,r,rs);
        return res;
    }
    #undef ls
    #undef rs
}
void dfs1(int u)
{
    dfn[u] = ++tim,siz[u] = 1;
    for (auto v : g[u])
    {
        dfs1(v);
        siz[u] += siz[v];
    }
    ed[u] = tim;
}
void dfs2(int u)
{
    root[u] = sgt::upd(dfn[u],1,tim,root[acm::ac[u].fa]);
    for (int i = 0; i < 26; i++)
        if (int v = acm::ac[u].ch[i]; v)
            dfs2(v);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    acm::build(s);
    acm::get_fail();
    dfs1(0);
    dfs2(0);
    cin >> m;
    int x,y;
    while (m--)
    {
        cin >> x >> y;
        cout << sgt::que(dfn[pos[x]],ed[pos[x]],1,tim,root[pos[y]]) << '\n';
    }
    return 0;
}