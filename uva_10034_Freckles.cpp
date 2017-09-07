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
typedef pair<double,double> pi;
typedef struct Edge
{
    pi u,v;
    double w;
    Edge(pi a,pi b)
    {
        u=a, v=b;
    };
    bool operator<(const Edge& a) const
    {
        return w< a.w;
    };
} edge;
int parent(int pr[],int a)
{
    if(pr[a]==a) return a;
    pr[a]=parent(pr,pr[a]);
    return pr[a];
}

double weight(edge a)
{
    return (sqrt((a.u.first-a.v.first)*(a.u.first-a.v.first)+(a.u.second-a.v.second)*(a.u.second-a.v.second)));
}
double kruskal(vector<edge> &e,vector<pi> &v,int ver)
{
    int num_edge=(ver*(ver-1))/2;  // number of edges is = ver C 2;
    sort(all(e));
    int assin=0;
    int pr[ver+3];
    map<pi,int> imap;
    bool vis[ver+3]= {};
    mst(vis);
    for(int i=0; i<ver; i++)
    {
        imap[v[i]]=i;
        pr[i]=i;
    }

    double cost=0;
    for(int i=0; i<num_edge; i++)
    {
        pi a=e[i].u, b=e[i].v;

        int num1=parent(pr,imap[a]), num2= parent(pr,imap[b]);

        if(num1!=num2)
        {
            pr[num1]=num2;
            cost+=e[i].w;
        }
    }
    return cost;

}
int main()
{

    int test;
    sf(test);
    bool nel=0;
    while(test--)
    {
        if(nel)
            nl;
        nel=1;
        int ver;
        sf(ver);
        vector<edge> e;
        vector<pi> str;
        for(int i=0; i<ver; i++)
        {
            pi a;
            scanf("%lf %lf",&a.first,&a.second);
            str.push_back(a);
            for(int j=0; j<i; j++)
            {
                edge tmp(str[j],a);
                tmp.w=weight(tmp);
                e.push_back(tmp);
            }
        }

        double cost=kruskal(e,str,ver);
        e.clear(), str.clear();
        printf("%.2lf\n",cost);

    }
}
