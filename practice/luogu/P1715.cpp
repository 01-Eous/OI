#include<bits/extc++.h>
using namespace std;
int n;
int f[305][305][305],ans[305];
struct Nahida{int x,y,id,op;}a[305];
bool operator<(Nahida x,Nahida y){return atan2(x.y,x.x) < atan2(y.y,y.x);}
void upd(int x,int y,int z,int tmp)
{
    if (x > y)
        swap(x,y);
    if (x > z)
        swap(x,z);
    if (y > z)
        swap(y,z);
    f[x][y][z] += tmp;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;        
    }
    for (int i = 1; i <= n; i++)
    {
        vector<Nahida>b;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            a[j].x -= a[i].x;
            a[j].y -= a[i].y;
            b.push_back(Nahida{a[j].x,a[j].y,a[j].id,1});
            b.push_back(Nahida{-a[j].x,-a[j].y,a[j].id,0});
        }
        sort(b.begin(),b.end());
        for (vector<Nahida>::iterator j = b.begin(); j != b.end(); j++)
        {
            int tmp = 0;
            vector<Nahida>::iterator k = j + 1;
            while (1)
            {
                if (k == b.end())
                    k = b.begin();
                if (k->id == j->id)
                    break;
                if (k->op == j->op)
                    upd(a[i].id,j->id,k->id,tmp);
                tmp += k->op;
                k++;
            }
        }
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            a[j].x += a[i].x;
            a[j].y += a[i].y;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
                ans[f[i][j][k] - (n - 3) >> 1]++;
    for (int i = 0; i < n - 2; i++)
        cout << ans[i] << "\n";
    return 0;
}