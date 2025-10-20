#include<bits/extc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int maxn = 5e5 + 5;
mt19937 rnd(random_device{}());
int n;
pii a[maxn];
struct line
{
    int a,b,c;
    int f(int x,int y)
    {return x * a + y * b + c;}
};
line calc(int x,int y,int _x,int _y){return {y - _y,_x - x,x * _y - _x * y};}
int count(line ln)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += !ln.f(a[i].first,a[i].second);
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    shuffle(a + 1,a + n + 1,rnd);
    for (int _ = 1; _ <= 100; _++)
    {
        int i = 0,j = 0;
        while (i == j)
            i = rnd() % n + 1,j = rnd() % n + 1;
        line tmp = calc(a[i].first,a[i].second,a[j].first,a[j].second);
        if (count(tmp) > n >> 1)
        {
            cout << "Yes\n" << tmp.a << ' ' << tmp.b << ' ' << tmp.c;
            return 0;
        }
    }
    cout << "No"; 
    return 0;
}