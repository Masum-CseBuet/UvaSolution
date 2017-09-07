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
#define mod 1000000007
using namespace std;

class Graph
{
public:
    class bridge
    {

    public:
        int u,v;
        bridge(int p,int q)
        {
            u = min(p,q);
            v = max(p,q);
        }
        void showBridge()
        {
            cout<<u<<" - "<<v<<endl;
        }
        bool operator<(bridge b)
        {
            if(u<b.u)
                return 1;
            else if(u==b.u)
            {
                if(v<b.v)
                    return 1;
                return 0;
            }
            return 0;
        }
    };

    int node,numOfBridge;
    vector<bridge> bridgeList;
    vector<int> *adlist;
    bool *vis;
    int *low,*disc,*parent;
    int time;
    void addEdge(int u,int v)
    {
        adlist[u].pb(v);
        adlist[v].pb(u);
    }
    Graph(int node)
    {
        this->node = node;
        time = numOfBridge =  0;
        adlist = new vector<int> [node];
        low = new int[node];
        disc = new int[node];
        parent = new int[node];
        vis = new bool[node];
        for(int i = 0; i<node; i++)
        {
            vis[i] = false;
            parent[i]=-1;
        }
    }
    void bridgeFind()
    {
        for(int i=0; i<node; i++)
        {
            if(!vis[i])
            {
                bridgeFindUtil(i);
            }
        }
        sort(bridgeList.begin(),bridgeList.end());
        vector<bridge>::iterator it;
        cout<<numOfBridge<<" critical links"<<endl;
        tr(bridgeList,it)
        (*it).showBridge();


    }
    void bridgeFindUtil(int u)
    {
        int children = 0;
        low[u] = disc[u] = time++;
        vis[u] = true;
        int siz = adlist[u].size();
        for(int i=0; i<siz; i++)
        {

            int v = adlist[u][i];

            if(!vis[v])
            {

                children++;
                parent[v] = u;
                bridgeFindUtil(v);
                low[u] = min(low[u],low[v]);
                if(low[v]>disc[u])
                {
                    bridge tmp(u,v);
                    bridgeList.push_back(tmp);
                    numOfBridge++;
                }


            }
            else if(v!= parent[u])
            {
                low[u] = min(disc[v],low[u]);
            }
        }
    }

};

int main()
{
    bool nel=false;
    int n;
    while(cin>>n)
    {
        nel = 1;
        Graph g(n);
        for(int i=0; i<n; i++)
        {
            int u,how;
            scanf("%d (%d)",&u,&how);
            for(int j=0; j<how; j++)
            {
                int v;
                sf(v);
                g.addEdge(u,v);
            }
        }
        if(nel)
        {
            g.bridgeFind();
            nl;
        }

    }

}
