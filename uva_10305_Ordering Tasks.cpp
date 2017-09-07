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
#define mstn(n) memset(n,-1,sizeof(n))
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)
#define pr(a) cout<<cout<<a.a.first<<"  "<< a.a.second<<endl
#define V 5
using namespace std;

vector<int>  adlist[100+3];
bool from[100+3];
bool vis[100+3];
stack<int> sorted;
int topsortUtil(int node)
{
    vis[node]=1;
    for(int i=0; i<adlist[node].size(); i++)
    {
        if(!vis[adlist[node][i]])
            topsortUtil(adlist[node][i]);
    }
    sorted.push(node);
}
int topsort(int n)
{
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            topsortUtil(i);
        }
    }
}
int main()
{

    int n,m;

    while(scanf("%d %d",&n,&m)==2 && (n!=0 || m!=0))
    {
        mst(vis);
        for(int i=0; i<=100; i++) adlist[i].clear();


        for(int i=0; i<m; i++)
        {
            int f,s;
            scanf("%d %d",&f,&s);
            adlist[f].push_back(s);//, from[f]=from[s]=1;
        }
        topsort(n);
        printf("%d",sorted.top());
        sorted.pop();
        while(!sorted.empty())
        {
            printf(" %d",sorted.top());
            sorted.pop();
        }
        nl;

    }


}

