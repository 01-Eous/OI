#include<bits/extc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int n,cnt;
string t[maxn],s;
int pos[maxn],in[maxn];
struct Nahida
{
    int sum,fail;
    int ch[26];
}dic[maxn];
void ins(const string &s,int id)
{
    int rt = 0;
    for (auto ch : s)
    {
        int dig = ch - 'a';
        if (!dic[rt].ch[dig])
            dic[rt].ch[dig] = ++cnt;
        rt = dic[rt].ch[dig];
    }
    pos[id] = rt;
}
void get_fail()
{
    queue<int> q;
    for (int i = 0; i < 26; i++)
        if (dic[0].ch[i])
            q.push(dic[0].ch[i]);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            if (dic[u].ch[i])
            {
                dic[dic[u].ch[i]].fail = dic[dic[u].fail].ch[i];
                in[dic[dic[u].ch[i]].fail]++;
                q.push(dic[u].ch[i]);
            }
            else
                dic[u].ch[i] = dic[dic[u].fail].ch[i];
        }
    }
}
void que(const string &s)
{
    int rt = 0;
    for (auto ch : s)
    {
        int dig = ch - 'a';
        rt = dic[rt].ch[dig];
        dic[rt].sum++;
    }
}
void topsort()
{
    queue<int> q;
    for (int i = 1; i <= cnt; i++)
        if (!in[i])
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int v = dic[u].fail;
        dic[v].sum += dic[u].sum;
        if (!--in[v])
            q.push(v);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        ins(t[i],i);
    }
    get_fail();
    cin >> s;
    que(s);
    topsort();
    for (int i = 1; i <= n; i++)
        cout << dic[pos[i]].sum << '\n';
    return 0;
}