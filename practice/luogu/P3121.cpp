#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,cnt;
string s[maxn],t,ans;
struct Klee{int ch[26],fail,id;}ac[maxn];
void ins(const string &s,int id)
{
    int rt = 0;
    for (auto ch : s)
    {
        int dig = ch - 'a';
        if (!ac[rt].ch[dig])
            ac[rt].ch[dig] = ++cnt;
        rt = ac[rt].ch[dig];
    }
    ac[rt].id = id;
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
void que()
{
    stack<int> stk;
    stk.push(0);
    for (auto ch : t)
    {
        int dig = ch - 'a',rt = stk.top();
        stk.push(ac[rt].ch[dig]);
        ans.push_back(ch);
        if (int id = ac[stk.top()].id; id)
        {
            for (int i = 1; i <= s[id].size(); i++)
            {
                stk.pop();
                ans.pop_back();
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        ins(s[i],i);
    }
    get_fail(),que();
    cout << ans;
    return 0;
}