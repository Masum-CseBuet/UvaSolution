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

#define V 5
using namespace std;
typedef pair<int,int> pi;
int parent[1000000+1];
class edge
{

public:
    int u,v,cost;

    friend istream &operator>>(istream& stream,edge &a);
    bool operator<(const edge &b)
    {
        return cost<b.cost;
    }

};
istream &operator>>(istream& stream,edge &a)
{
    stream>>a.u>>a.v>>a.cost;
}

int findParent(int a)
{
    return (parent[a]==a?a:parent[a]=findParent(parent[a]));
}

int kruskalMst(vector<edge> &e)
{
    sort(all(e));
    int cost=0;

    for(int i=0; i<e.size(); i++)
    {
        int u=findParent(e[i].u);
        int v=findParent(e[i].v);
        if(u!=v)
        {
            cost+=e[i].cost;
            parent[u]=v;
        }
    }
    return cost;

}
int main()
{

    int num;
    bool nel=0;
    while(scanf("%d",&num)!=EOF)
    {
        if(nel) nl;
        nel=1;
        int originalCost=0, curCost=0;
        vector<edge> store;
        mst(parent);
        for(int i=0; i<num; i++)
            parent[i]=i;

        edge tmp;
        for(int i=0; i<num-1; i++)
        {
            cin>>tmp;
            store.push_back(tmp);
            originalCost+=tmp.cost;
        }

        int newEdge;
        sf(newEdge);
        for(int i=0; i<newEdge; i++)
        {
            cin>>tmp;
            store.push_back(tmp);

        }
        //unnecessary part
        int how;
        sf(how);
        for(int i=0; i<how; i++)
        {
            edge tmp;
            cin>>tmp;
        }

        curCost=kruskalMst(store);
        printf("%d\n%d\n",originalCost,curCost);
    }


}
