#include<bits/stdc++.h>
#define pb(n) push_back(n)
#define bug cout<<"bug";
#define all(c) c.begin(),c.end()
#define fr(i,n) for(i=0;i<n;i++)
#define sf(n) scanf("%d",&n)
#define mst(n) memset(n,0,sizeof(n))
#define nl printf("\n")
#define lli long long int
#define tr(container,it) \
    for (auto it = container.begin(); it != container.end() ; ++it)

#define INF INT_MAX

#define mp(i,j) make_pair(i,j)
#define mstn(n) memset(n,-1,sizeof(n))
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

#define V 1000001
#define pi acos(-1.0)
using namespace std;
lli bigMod(int b,int p,int m)
{
    if(p==0) return 1;
    lli ret=bigMod(b,p/2,m);
    ret=(ret*ret)%m;

    if(p%2==1) ret=(ret * b)%m;
    return ret;
}

int main()
{
    int b,p,m;
    while(scanf("%d %d %d",&b,&p,&m)!=EOF)
    {
        int mod=bigMod(b,p,m);
        printf("%d\n",mod);
    }
}
