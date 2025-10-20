#include<bits/extc++.h>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define chkmax(x,y) (x = max(x,y))
using namespace std;
const int maxn = 5e5 + 5;
int n,m,cnt,tim;
char s[maxn];
int pos[maxn],val[maxn];
int fa[maxn],son[maxn],siz[maxn];
int dfn[maxn],top[maxn],dep[maxn],tree[maxn << 2];;
vector<int> g[maxn];
struct Klee
{
    int ch[26],fail;
    multiset<int,greater<>> val;
}ac[maxn];
void ins(int id)
{
    int rt = 0,len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        int dig = s[i] - 'a';
        if (!ac[rt].ch[dig])
        {
            ac[++cnt].val.clear();
            ac[rt].ch[dig] = cnt;
        }
        rt = ac[rt].ch[dig];
    }
    ac[pos[id] = rt].val.insert(0);
}
void get_fail()
{
    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (ac[0].ch[i])
            q.push(ac[0].ch[i]);
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
                ac[v].fail = ac[ac[u].fail].ch[i];
                q.push(v);
            }
            else
                v = ac[ac[u].fail].ch[i];
        }
    }
}
void dfs1(int u,int pre)
{
    fa[u] = pre;
    siz[u] = 1;
    for (auto v : g[u])
    {
        if (v == pre)
            continue;
        dep[v] = dep[u] + 1;
        dfs1(v,u);
        siz[u] += siz[v];
        if (!son[u] || siz[v] > siz[son[u]])
            son[u] = v;
    }
}
void dfs2(int u,int tp)
{
    dfn[u] = ++tim,top[u] = tp;
    if (son[u])
        dfs2(son[u],tp);
    for (auto v : g[u])
        if (v != fa[u] && v != son[u])
            dfs2(v,v);
}
void push_up(int rt){tree[rt] = max(tree[ls],tree[rs]);}
void upd(int pos,int x,int l = 1,int r = tim,int rt = 1)
{
    if (l == r)
    {
        tree[rt] = x;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,x,l,mid,ls);
    else
        upd(pos,x,mid + 1,r,rs);
    push_up(rt);
}
int que(int ql,int qr,int l = 1,int r = tim,int rt = 1)
{
    if (ql <= l && r <= qr)
        return tree[rt];
    int mid = (l + r) >> 1,res = -1;
    if (ql <= mid)
        chkmax(res,que(ql,qr,l,mid,ls));
    if (qr > mid)
        chkmax(res,que(ql,qr,mid + 1,r,rs));
    return res;
}
int path(int u,int v)
{
    int res = -1;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u,v);
        chkmax(res,que(dfn[top[u]],dfn[u]));
        u = fa[top[u]];
    }
    if (dep[u] < dep[v])
        swap(u,v);
    chkmax(res,que(dfn[v],dfn[u]));
    return res;
}
int que()
{
    int rt = 0,len = strlen(s + 1),res = -1;
    for (int i = 1; i <= len; i++)
    {
        int dig = s[i] - 'a';
        rt = ac[rt].ch[dig];
        chkmax(res,path(rt,0));
    }
    return res;
}
signed main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        scanf("%s",s + 1),ins(i);
    get_fail();
    dfs1(0,-1);
    dfs2(0,0);
    memset(tree,0xff,sizeof tree);
    for (int i = 1; i <= n; i++)
        upd(dfn[pos[i]],0);
    int op,i,x;
    while (m--)
    {
        scanf("%d",&op);
        if (op == 1)
        {
            scanf("%d%d",&i,&x);
            auto &st = ac[pos[i]].val;
            st.erase(st.find(val[i]));
            st.insert(val[i] = x);
            upd(dfn[pos[i]],*st.begin());
        }
        else
        {
            scanf("%s",s + 1);
            printf("%d\n",que());
        }
    }
    return 0;
}