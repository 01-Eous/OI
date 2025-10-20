#include<bits/extc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n,cnt = 1;
char s[maxn];
struct Klee{int ch[26],fail,len,dep;}ac[maxn << 2];
int get_fail(int u,int i)
{
    while (i - ac[u].len - 1 < 1 || s[i] != s[i - ac[u].len - 1])
        u = ac[u].fail;
    return u;
}
signed main()
{
    scanf("%s",s + 1);
    n = strlen(s + 1);
    ac[0].fail = 1;
    ac[1].len = -1;
    int rt = 0,lst = 0;
    for (int i = 1; i <= n; i++)
    {
        s[i] = (s[i] - 'a' + lst) % 26 + 'a';
        int u = get_fail(rt,i),dig = s[i] - 'a';
        if (!ac[u].ch[dig])
        {
            cnt++;
            ac[cnt].fail = ac[get_fail(ac[u].fail,i)].ch[dig];
            ac[u].ch[dig] = cnt,ac[cnt].len = ac[u].len + 2;
            ac[cnt].dep = ac[ac[cnt].fail].dep + 1;
        }
        rt = ac[u].ch[dig];
        printf("%d ",lst = ac[rt].dep);
    }
    return 0;
}