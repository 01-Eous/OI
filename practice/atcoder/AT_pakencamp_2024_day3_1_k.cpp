#include<bits/extc++.h>
#define pos(i) ((i) << 1)
using namespace std;
using pii = pair<int,int>;
const int maxn = 2e5 + 5;
int n,len;
bool fl,done[maxn];
char op[maxn],tim[maxn];
int a[maxn],b[maxn],in[maxn];
vector<pii> ans;
vector<int> g[maxn],vec;
bool chk(int x){return (x == len || !x) ? 1 : done[x - 1] && done[x];}
void topsort()
{
    queue<int> q;
    for (int i = 2; i <= n; i += 2)
        if (!in[i])
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vec.push_back(u);
        for (auto v : g[u])
            if (!--in[v])
                q.push(v);
    }
}
void lft(int x)
{
    swap(a[x - 1],a[x]);
    ans.push_back({1,x - 1});
    ans.push_back({2,x - 1});
}
void rht(int x)
{
    swap(a[x],a[x + 1]);
    ans.push_back({1,x});
    ans.push_back({2,x});
}
void all(int x)
{
    if (a[x - 1] < a[x + 1])
    {
        swap(a[x - 1],a[x]);
        ans.push_back({1,x - 1});
        ans.push_back({2,x - 1});
        ans.push_back({2,x});
    }
    else
    {
        swap(a[x],a[x + 1]);
        ans.push_back({1,x});
        ans.push_back({2,x - 1});
        ans.push_back({2,x});
    }
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",a + i);
    for (int i = 1; i < n; i++)
        scanf("%d",b + i);
    if (!(n & 1))
        b[n] = 1;
    len = n + 1 + ((n & 1) ? 0 : 1);
    done[n] = 1;
    for (int i = 1; i < n; i++)
    {
        if ((a[i] > a[i + 1]) == b[i])
        {
            done[i] = 1;
            ans.push_back({2,i});
        }
    }
    for (int i = 2; i <= n; i += 2)
    {
        if (chk(i))
            continue;
        int nxt = i + 2,pre = i - 2;
        if (!done[i - 1] && !done[i])
        {
            if (a[i - 1] < a[i + 1])
            {
                if (!chk(pre) && a[i] > a[pre])
                {
                    in[i]++;
                    g[pre].push_back(i);
                }
            }
            else
            {
                if (!chk(nxt) && a[i] > a[nxt])
                {
                    in[i]++;
                    g[nxt].push_back(i);
                }
            }
        }
        else if (!done[i - 1])
        {
            if (!chk(pre) && a[i] > a[pre])
            {
                in[i]++;
                g[pre].push_back(i);
            }
        }
        else if (!done[i])
        {
            if (!chk(nxt) && a[i] > a[nxt])
            {
                in[i]++;
                g[nxt].push_back(i);
            }
        }
    }
    topsort();
    for (auto u : vec)
    {
        if (chk(u))
            continue;
        if (!done[u - 1] && !done[u])
            all(u);
        else if (!done[u - 1])
            lft(u);
        else if (!done[u])
            rht(u);
    }
    cout << ans.size() << endl;
    for (auto [typ,id] : ans)
        printf("%d %d\n",typ,id);
    return 0;
}