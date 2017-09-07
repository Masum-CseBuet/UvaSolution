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

class graph
{
public:
    int n;
    bool adMatrix[100][100];
    bool isNode[100];
    graph()
    {
        for(int i=0; i<100; i++)
        {
            isNode[i] = 0;
            for(int j=0; j<100; j++)
                adMatrix[i][j]=0;
        }

    }
    void makeEdge(int u,int v)
    {
        adMatrix[u][v] = 1;
    }
    double floyWarshall()
    {
        int dist[100][100];
        for(int i=0; i<100; i++)
        {
            for(int j=0; j<100; j++)
            {
                if(adMatrix[i][j]==0) dist[i][j] = INF;
                else dist[i][j] =1;
            }

        }

        for(int inter = 0; inter<100; inter++)
        {
            if(!isNode[inter]) continue;
            for(int from=0; from<100; from++)
            {
                if(!isNode[from]) continue;
                for(int to=0; to<100; to++)
                {
                    if(!isNode[to] || from==to) continue;
                    if(dist[from][inter]!=INF && dist[inter][to]!=INF && dist[from][inter]+dist[inter][to]<dist[from][to])
                    {
                        dist[from][to] = dist[from][inter]+dist[inter][to];
                    }
                }
            }
        }
        int cnt = 0;
        double avg=0;
        for(int i=0; i<100; i++)
        {
            for(int j=0; j<100; j++)
            {
                if(dist[i][j]!=INF)
                {
                    cnt++, avg+=dist[i][j];
                }
            }
        }
        return (avg/cnt);

    }
};

int main()
{
    int u,v,kase=1;
    while(scanf("%d %d",&u,&v) && u!=0 && v!=0)
    {
        graph g;
        g.makeEdge(u-1,v-1) ;
        g.isNode[u-1] = g.isNode[v-1] = 1;
        while(1)
        {
            scanf("%d %d",&u,&v);
            if(u==0 && v==0) break;
            g.isNode[u-1] = g.isNode[v-1] = 1;
            g.makeEdge(u-1,v-1);
        }
        printf("Case %d: average length between pages = %0.3lf clicks\n",kase++,g.floyWarshall());
    }


}


