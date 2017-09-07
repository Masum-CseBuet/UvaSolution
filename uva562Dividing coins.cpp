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
#define sz 1005
using namespace std;
bool dp[25000+1];
int coin[100+1];
int difference(int total,int num)
{
    dp[0] = 1;
    for(int i=1;i<=num;i++)
    {
        for(int j=total;j>=coin[i];j--)
        {
            dp[j] = dp[j] || dp[j-coin[i]];
        }
        if(dp[total]==1) return total;
    }
    for(int i=total;i>=0;i--)
        if(dp[i]==1) return i;
}
int main()
{
    int test;
    sf(test);
    while(test--)
    {
        mst(dp);
        int num;
        sf(num);
        int sum=0;
        for(int i=1; i<=num; i++)
        {
            sf(coin[i]);
            sum+=coin[i];
        }

        int diff = difference(sum/2,num);
        diff = abs(diff-(sum-diff));
        cout<<diff<<endl;
    }

}


