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
#define ull unsigned long long
#define V 1000001
#define pi acos(-1.0)
using namespace std;

int main()
{
    int test;
    sf(test);
    while(test--)
    {
        int ara[10];
        mst(ara);
        int num;
        sf(num);
        for(int i=1; i<=num; i++)
        {
            int tmp=i;
            while(tmp!=0)
            {
                ara[tmp%10]++;
                tmp/=10;
            }

        }
        cout<<ara[0];
        for(int i=1; i<10; i++)
            printf(" %d",ara[i]);
        nl;
    }


}
