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
#define MOD 100000007
using namespace std;
int ara[10005];
int dp[101][10005];
int num,k;
bool canMake(int sum,int pos)
{
    sum = (sum%k+k)%k;
    if(pos==num)
    {
        return sum==0?1:0;
    }

    if(dp[sum][pos]!=-1) return dp[sum][pos];
    bool chk = canMake(sum+ara[pos],pos+1);
    chk = (chk | canMake(sum-ara[pos],pos+1));
    return dp[sum][pos] = chk;
}
int main()
{
    int test;
    sf(test);
    while(test--)
    {
        mstn(dp);
        scanf("%d %d",&num,&k);
        for(int i=0; i<num; i++)
        {
            sf(ara[i]);
        }
        bool ret = canMake(ara[0]%k,1);
        if(ret==1)
            cout<<"Divisible"<<endl;
        else
            cout<<"Not divisible"<<endl;

    }
}
