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
typedef pair<int,int> ipair;
int pr[10000+1];
class edge
{
public:
    int u,v,w;
    edge(int u,int v,int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
    bool operator<(edge b)
    {
        if(w<b.w) return true;
        return false;
    }

};
class graph
{
public:
    int n,dest;
    vector<ipair> *adlist;
    bool *vis;
    ipair *prev;
    graph(int n)
    {
        this->n = n;
        adlist = new vector<ipair>[n];
        vis = new bool[n];
        prev = new ipair[n];
    }
    void resetAll()
    {
        for(int i=0; i<n; i++) vis[i] = false;
        mst(prev);
    }
    void addEdge(edge tmp)
    {
        adlist[tmp.u].push_back(make_pair(tmp.v,tmp.w));
        adlist[tmp.v].push_back(make_pair(tmp.u,tmp.w));
    }
    bool dfsUtil(int u)
    {
        vis[u] = true;
        bool ret = 0;
        if(u==dest) return 1;
        int siz = adlist[u].size();
        for(int i=0; i<siz; i++)
        {
            int v = adlist[u][i].first;
            if(!vis[v])
            {
                prev[v] = make_pair(u,adlist[u][i].second);
                ret = (dfsUtil(v) || ret);
            }

        }
        return ret;
    }
    int dfs(int from,int to)
    {
        resetAll();
        prev[from] = make_pair(from,0);
        dest = to;
        if(!dfsUtil(from)) return 0;
        int u = to;
        int maxWeight = 0;
        while(prev[u].first!=u)
        {
            int v = prev[u].first;
            maxWeight = max(maxWeight,prev[u].second);
            u = v;
        }
        return maxWeight;
    }
};
int parentFind(int u)
{
    return (pr[u]==u)?u:pr[u]=parentFind(pr[u]);
}

int main()
{
    bool nel = false;
    int test,kase = 1;
    while(1)
    {
        int node,e,q;
        scanf("%d %d %d",&node,&e,&q);
        if(node==0) return 0;
        if(nel) nl;
        nel = true;
        vector<edge> paths;
        for(int i=0; i<e; i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            edge tmp(u-1,v-1,w);
            paths.push_back(tmp);
        }
        for(int i=0; i<node; i++)
        {
            pr[i] = i;
        }
        sort(all(paths));
        int cnt =0,sum=0;
        graph g(node);
        for(int i=0; i<e; i++)
        {
            int pr1 = parentFind(paths[i].u);
            int pr2 = parentFind(paths[i].v);
            if(pr1!=pr2)
            {
                pr[pr1] = pr2;
                cnt++;
                g.addEdge(paths[i]);
            }

            if(cnt==node) break;
        }
        cout<<"Case #"<<kase++<<endl;
        for(int i=0; i<q; i++)
        {
            int from,to;
            scanf("%d %d",&from,&to);
            int res = g.dfs(from-1,to-1);
            if(res == 0 )
            {
                cout<<"no path"<<endl;
            }
            else
            {
                cout<<res<<endl;
            }
        }

    }
}
