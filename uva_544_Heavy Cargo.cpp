#include<bits/stdc++.h>
#define pb(n) push_back(n)
#define bug cout<<"bug";
#define all(c) c.begin(),c.end()
#define fr(i,n) for(i=0;i<n;i++)
#define sf(n) scanf("%d",&n)
#define Maximum_Spanning_Tree(n) memset(n,0,sizeof(n))
#define nl printf("\n")
#define lli long long int
#define tr(container,it) \
    for (auto it = container.begin(); it != container.end() ; ++it)

#define INF INT_MAX
#define MOD 1000000007
#define mp(i,j) make_pair(i,j)
#define Maximum_Spanning_Treen(n) memset(n,-1,sizeof(n))
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

using namespace std;
typedef pair<int,int> pi;
class Graph
{
    int ver;
    vector<pi> cities[200+1];
public:
    Graph(int v):ver(v) {};
    void addEdge(int u,int v,int w);
    int Maximum_Spanning_Tree(int src,int des);

};
void Graph::addEdge(int u,int v,int w)
{
    cities[u].push_back(mp(v,w));
    cities[v].push_back(mp(u,w));
}
int Graph::Maximum_Spanning_Tree(int src,int des)
{
    priority_queue<pi> pq;
    vector<bool> vis(ver+1,0);
    vector<int> dis(ver+1,-1);
    vector<int> pr(ver+1,src);
    pq.push(mp(0,src));
    while(!pq.empty())
    {
        int from=pq.top().second;
        vis[from]=1;
        pq.pop();
        if(from==des) break;
        for(int i=0; i<cities[from].size(); i++)
        {
            int to=cities[from][i].first;
            int w=cities[from][i].second;
            if(!vis[to] && dis[to]<w)
            {
                dis[to]=w;
                pr[to]=from;
                pq.push(mp(dis[to],to));
            }
        }
    }
    int mn=dis[des];
    while(des!=src)
    {
        mn=min(mn,dis[des]);
        des=pr[des];
    }
    return mn;
}
int main()
{

    int n,r,kase=1;
    while(scanf("%d %d",&n,&r)==2 && (n || r))
    {
        map<string,int> imap;
        Graph g(n);
        int assin=0;
        char cit1[80],cit2[80];
        for(int i=0; i<r; i++)
        {

            int w;
            scanf("%s %s %d",cit1,cit2,&w);
            if(imap.count(cit1)==0)
            {
                imap[cit1]=assin++;
            }
            if(imap.count(cit2)==0)
            {
                imap[cit2]=assin++;
            }
            int c1=imap[cit1], c2=imap[cit2];
            g.addEdge(c1,c2,w);

        }
        scanf("%s %s",cit1,cit2);
        int ret=g.Maximum_Spanning_Tree(imap[cit1],imap[cit2]);
        printf("Scenario #%d\n%d tons\n\n",kase++,ret);


    }


}
