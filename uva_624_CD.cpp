#include<bits/stdc++.h>
#define pb(n) push_back(n)
#define bug cout<<"bug";
#define all(c) c.begin(),c.end()
#define fr(i,n) for(i=0;i<n;i++)
#define sf(n) scanf("%d",&n)
#define mst(n,num) memset(n,0,sizeof(int)*num)
#define nl printf("\n")
#define lli long long int
#define tr(container,it) \
    for (auto it = container.begin(); it != container.end() ; ++it)

#define INF INT_MAX
#define MOD 1000000007

#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)
using namespace std;
int dur,n,mx,sum;
vector<int> tmp,ans;

int backtracking(int ara[],int taken)
{

    if(mx<sum)
    {
        mx=sum,  ans=tmp;

    }
    for(int i=taken; i<dur; i++)
    {
        if(sum+ara[i]<=n)
        {
            tmp.pb(ara[i]), sum+=ara[i];
            backtracking(ara,i+1);
            tmp.pop_back(), sum-=ara[i];
        }

    }


}
int main()
{

    while(sf(n)==1)
    {
        mx=-1, sum=0 , ans.clear() ,tmp.clear();
        sf(dur);
        int ara[dur];
        for(int i=0; i<dur; i++)
        {
            sf(ara[i]);
        }
        backtracking(ara,0);
        for(auto a:ans)
            cout<<a<<" ";
        printf("sum:%d\n",mx);
    }

}
