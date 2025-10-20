#include<bits/extc++.h>
using namespace std;
const int maxn = 3.5e4;
int cnt;
char s[65];
int ch[maxn][26];
void ins()
{
    int rt = 0,len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        int dig = s[i] - 'A';
        if (!ch[rt][dig])
            ch[rt][dig] = ++cnt;
        rt = ch[rt][dig];
    }
}
signed main()
{
    while (scanf("%s",s + 1) != EOF)
        ins();
    printf("%d",cnt + 1);
    return 0;
}