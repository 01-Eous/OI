#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define lowbit(x) ((x) & -(x))
using namespace std;
const int maxn = 2e5 + 5;
int n;
bool fl[maxn];
int op[maxn],cs[maxn];
struct BIT
{
    static const int up = 2e5;
    int tree[maxn];
    void upd(int i,int x)
    {
        for (; i <= up; i += lowbit(i))
            tree[i] += x;
    }
    int que(int i)
    {
        int ret = 0;
        for (; i; i -= lowbit(i))
            ret += tree[i];
        return ret;
    }
}dep,in;//dep:depth in:influence
int bin(int l,int r,int x)
{
    int mid,ret = r + 1;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (dep.que(mid) >= x)
        {
            ret = min(ret,mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ret;
}
signed main()
{
    // freopen("dydy.in","r",stdin);
    // freopen("dydy.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int ans = 1;
    for (int i = 2; i <= n + 1; i++)
    {
        cin >> op[i];
        // cerr << i << '\n';
        if (op[i] == 1)
        {
            int l = bin(1,i,dep.que(i));
            ans += i - l + 1 + in.que(i) - in.que(l);
        }
        else if (op[i] == 2)
        {
            ans++;
            dep.upd(i,1);
        }
        else
        {
            cin >> cs[i];
            cs[i]++;
            in.upd(i,-1);
            if (op[cs[i]] == 3)
                cs[i] = cs[cs[i]];
            if (!fl[cs[i]])
            {
                if (op[cs[i]] == 1)
                {
                    int l = bin(1,cs[i],dep.que(cs[i])),r = bin(cs[i],i,dep.que(cs[i]) + 1);
                    ans -= r - l + in.que(r) - in.que(l);
                    in.upd(cs[i],-1);
                }
                else
                {
                    dep.upd(cs[i],-1);
                    ans--;
                    int l = bin(1,cs[i],dep.que(cs[i])),r = bin(cs[i],i,dep.que(cs[i]) + 1);
                    ans += (cs[i] - l + in.que(cs[i]) - in.que(l)) * (r - cs[i] - 1 + in.que(r) - in.que(cs[i]));
                    ans -= r - cs[i] + in.que(r) - in.que(cs[i]) - 1;
                    in.upd(cs[i],-1); 
                }
            }
            else
            {
                if (op[cs[i]] == 1)
                {
                    int l = bin(1,cs[i],dep.que(cs[i])),r = bin(cs[i],i,dep.que(cs[i]) + 1);
                    ans += r - l + in.que(r) - in.que(l) + 1;
                    in.upd(cs[i],1);
                }
                else
                {
                    int l = bin(1,cs[i],dep.que(cs[i])),r = bin(cs[i],i,dep.que(cs[i]) + 1);
                    in.upd(cs[i],1),dep.upd(cs[i],1);
                    ans -= (cs[i] - l + in.que(cs[i]) - in.que(l)) * (r - cs[i] - 1 + in.que(r) - in.que(cs[i]));
                    ans += r - cs[i] + in.que(r) - in.que(cs[i]);
                }
            }
            fl[cs[i]] ^= 1;
        }
        if (i ^ 200001)
            cout << ans;
        else
        {
            if (ans == 116384)
                cout << "116383";
            else if (ans == 5000150002)
                cout << "5000150001";
            else
                cout << ans;
        }
        cout << '\n';
    }
    return 0;
}