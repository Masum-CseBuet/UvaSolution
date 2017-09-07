#include<bits/stdc++.h>
#define pb(n) push_back(n)
#define bug cout<<"bug";
#define all(c) c.begin(),c.end()
#define fr(i,n) for(i=0;i<n;i++)
#define sf(n) scanf("%d",&n)
#define mp(i,j) make_pair(i,j)
#define mst(n) memset(n,-1,sizeof(n))
#define nl printf("\n")
#define lli long long int
#define tr(container,it) \
    for (auto it = container.begin(); it != container.end() ; ++it)

#define INF INT_MAX
#define MOD 1000000007

#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)
#define N 500
using namespace std;


int main()
{

    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        int mx=-1;
        int f=min(a,b) , t=max(a,b);
        for(int i=f;i<=t;i++)
        {
            int tmp=i,cnt=1;
            while(tmp!=1)
            {
                if(tmp&1)
                {

                    tmp=tmp*3+1;
                }
                else{
                    tmp/=2;
                }

                cnt++;
            }

            mx=max(mx,cnt);
        }
        printf("%d %d %d",a,b,mx);
        nl;
    }
}

