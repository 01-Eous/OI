#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e6 + 5;
int n,a[maxn];
struct Nahida
{
    int l,r,val;
    int tag1,tag2;
}tree[maxn << 2];
void push_up(int rt){tree[rt].val = max(tree[ls].val,tree[rs].val);}
void push_down(int rt)
{
    if (tree[rt].tag1 ^ inf)
    {
        tree[ls].val = tree[rs].val = tree[rt].tag1;
        tree[ls].tag1 = tree[rs].tag1 = tree[rt].tag1;
        tree[ls].tag2 = tree[rs].tag2 = 0;
        tree[rt].tag1 = inf;
    }
    if (tree[rt].tag2)
    {
        tree[ls].val += tree[rt].tag2;
        tree[rs].val += tree[rt].tag2;
        tree[]
    }
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    
    return 0;
}