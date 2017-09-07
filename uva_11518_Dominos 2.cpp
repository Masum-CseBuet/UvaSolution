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
#define MOD 1000000007
#define mp(i,j) make_pair(i,j)
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)
#define pr(a) cout<<cout<<a.a.first<<"  "<< a.a.second<<endl
#define V 5
using namespace std;
vector<int> adlist[100005];
bool vis[100005];
int dfsUtil(int src)
{
    int cnt=0;
    vis[src]=1, cnt++;
    for(int i=0; i<adlist[src].size(); i++)
    {
        int tmp=adlist[src][i];
        if(!vis[tmp])
            cnt+=dfsUtil(tmp);

    }
    return cnt;
}
int dfs(int ara[],int how)
{

    int cnt=0;
    for(int i=0; i<how; i++)
    {
        int src=ara[i];
        if(!vis[src])
        {

            cnt+= dfsUtil(src);


        }
    }
    return cnt;
}

int main()
{

    int test,ara[100005];
    sf(test);
    while(test--)
    {
        mst(vis);

        int dom,lin,src;
        scanf("%d %d %d",&dom,&lin,&src);
        for(int i=0; i<=dom; i++) adlist[i].clear();
        for(int i=0; i<lin; i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            adlist[x].pb(y);
        }
        for(int i=0; i<src; i++)
        {
            sf(ara[i]);
        }

        int ret=dfs(ara,src);
        printf("%d\n",ret);
    }


}
