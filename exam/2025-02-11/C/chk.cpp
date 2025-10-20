#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
void Exit(int code) {
    if (code == 1) quitf(_ok,"AC!");
    else if (code==-1) quitf(_wa,"the result isn't p[i]=i");
    else quitf(_wa,"wrong format");
    exit(0);
}
int n,p[1010],op,m;
string s,t;
int main(int argc, char **argv){
    registerTestlibCmd(argc, argv);
    // registerLemonChecker(argc,argv);
    n=inf.readInt(1,1000); op=inf.readInt(-1,10000000);
    for (int i=1;i<=n;i++) p[i]=inf.readInt(1,n);
    s=ouf.readToken(),t=ans.readToken();
    if (s!=t) Exit(0);
    if (s=="NO") Exit(1);
    if (op==-1) {
        while (!ouf.seekEof()) s=ouf.readToken();
        Exit(1);
    }
    m=ouf.readInt(0,op);
    int x,y;
    for (int i=1;i<=m;i++) {
        x=ouf.readInt(1,n),y=ouf.readInt(1,n);
        if (x==y||p[x]==x||p[y]==y||abs(x-y)!=1) Exit(0); swap(p[x],p[y]);
    }
    if (!ouf.seekEof()) Exit(0);
    for (int i=1;i<=n;i++) if (p[i]!=i) Exit(-1);
    Exit(1);
    return 0;
}
