// 多大了还出大模拟
#include<bits/extc++.h>
#define Klee 0
#define Nahida 1
using namespace std;
int n = 9,m;
int mp[12][12],his[105][12][12];
inline void read(int &x)
{
    char f = 1,ch = getchar();x = 0;
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}
bool chkr(int x,int k)
{
    for (int i = 1; i <= 9; i++)
        if (mp[x][i] == k)
            return Klee;
    return Nahida;
}
bool chkc(int y,int k)
{
    for (int i = 1; i <= 9; i++)
        if (mp[i][y] == k)
            return Klee;
    return Nahida;
}
bool chks(int x,int y,int k)
{
    int idx = (x - 1) / 3 + 1,idy = (y - 1) / 3 + 1;
    int sx = (idx - 1) * 3 + 1,tx = idx * 3;
    int sy = (idy - 1) * 3 + 1,ty = idy * 3;
    for (int i = sx; i <= tx; i++)
        for (int j = sy; j <= ty; j++)
            if (mp[i][j] == k)
                return 0;
    return 1;
}
bool chk(int x,int y,int k){return chkr(x,k) && chkc(y,k) && chks(x,y,k);}
template<typename typ>
void print(typ mp)
{
    puts("+-+-+-+-+-+-+-+-+-+");
    for (int i = 1; i <= n; i++)
    {
        putchar('|');
        for (int j = 1; j <= n; j++)
            printf("%d|",mp[i][j]);
        putchar('\n');
        puts("+-+-+-+-+-+-+-+-+-+");
    }
}
signed main()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            read(mp[i][j]);
    memcpy(his[0],mp,sizeof mp);
    read(m);
    char op[10];
    for (int _ = 1,x,y,k; _ <= m; _++)
    {
        scanf("%s",op);
        if (op[0] == 'I')// 9^1
        {
            read(x),read(y),read(k);
            if (mp[x][y])
            {
                puts("Error!");
                goto ed;
            }
            if (!chkr(x,k))
            {
                puts("Error:row!");
                goto ed;
            }
            if (!chkc(y,k))
            {
                puts("Error:column!");
                goto ed;
            }
            if (!chks(x,y,k))
            {
                puts("Error:square!");
                goto ed;
            }
            puts("OK!");
            mp[x][y] = k;
        }
        else if (op[0] == 'D')// 9^0
        {
            read(x),read(y);
            if (!mp[x][y])
            {
                puts("Error!");
                goto ed;
            }
            puts("OK!");
            mp[x][y] = 0;
        }
        else if (op[0] == 'Q')// 9^2
        {
            read(x),read(y);
            vector<int> ans;
            for (k = 1; k <= 9; k++)
                if (chk(x,y,k))
                    ans.push_back(k);
            printf("%llu\n",ans.size());
            for (auto i : ans)
                printf("%d\n",i);
        }
        else if (op[0] == 'M')// 9^3
        {
            read(x),read(y);
            memset(mp,0,sizeof mp);
            int cntx = 0,cnty = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (chk(i,j,his[x][i][j]))
                    {
                        cntx++;
                        mp[i][j] = his[x][i][j];
                    }
                    else if (chk(i,j,his[y][i][j]))
                    {
                        cnty++;
                        mp[i][j] = his[y][i][j];
                    }
                }
            }
            printf("%d %d\n",cntx,cnty);
        }
        else
            print(mp);
        ed:memcpy(his[_],mp,sizeof mp);//9^2
    }
    return 0;
}