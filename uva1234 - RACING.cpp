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
//This is a Maximum spanning tree problem . In a max spanning tree we take the edges with maximum
//weight such that no cycle is created. So after having a spanning tree with the maximum weighted edges being picked up ,all we are left with
// are the edges with minimum cost that create a cycle
// As the problem states that we have to ensure at least one camera in every possible cycle
// we will take the summation of  all those edges that create cycle
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
        if(w>b.w) return true;
        return false;
    }

};
int parentFind(int u)
{
    return (pr[u]==u)?u:pr[u]=parentFind(pr[u]);
}

int main()
{

    int test,kase = 1;
    sf(test);
    while(test--)
    {
        int node,e;
        scanf("%d %d",&node,&e);
        vector<edge> paths;
        for(int i=0; i<e; i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            edge tmp(u-1,v-1,w);
            paths.push_back(tmp);
        }
        for(int i=0;i<node;i++)
        {
            pr[i] = i;
        }
        sort(all(paths));
        int cnt =0,sum=0;
        for(int i=0; i<e; i++)
        {
            int pr1 = parentFind(paths[i].u);
            int pr2 = parentFind(paths[i].v);
            if(pr1!=pr2)
            {
                pr[pr1] = pr2;
            }
            else{               // if already connected then surely this edge creates cycle
                                //So we will take this edge into account
                sum+=paths[i].w;
            }
        }

        cout<<sum<<endl;

    }
    int tmp;
    sf(tmp);
}

