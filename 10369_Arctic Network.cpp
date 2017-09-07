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
int pr[501];
// typical kruskal algorithm application
class edge
{
public:
    int a,b;
    double wt;

    void Set(int x,int y,double w)
    {
        a=x, b=y, wt=w;
    }
    bool operator<(const edge& a)
    {
        return wt<a.wt;
    }

};
double mn(double a,double b)
{
    return (a<b?a:b);
}
int Find(int ch)
{
    return (pr[ch]==ch?ch :pr[ch]=Find(pr[ch]));
}
int main()
{

    int test;
    sf(test);

    while(test--)
    {
        vector<edge> comp;
        int s,p;
        scanf("%d %d",&s,&p);
        mst(pr);
        int ax[p],ay[p];
        for(int i=0; i<p; i++)
        {
            scanf("%d %d",&ax[i],&ay[i]);
            pr[i]=i;

            for(int j=0; j<i; j++) // finding all possible path among vertices
            {
                double ds=sqrt((ax[i]-ax[j])*(ax[i]-ax[j])+(ay[i]-ay[j])*(ay[i]-ay[j]));
                edge tmp;
                tmp.Set(i,j,ds);  // forming an edge with vertices indices and weight of the edge
                comp.push_back(tmp);
            }

        }

        sort(all(comp));

        int cnt=0,i=0;
        vector<double> path;

        while(cnt!=(p-1-(s-1)))
        {

            int p1=Find(comp[i].a);
            int p2=Find(comp[i].b);
            if(p1!=p2)
            {

                pr[p1]=p2;
                path.push_back(comp[i].wt);
                cnt++;
            }
            i++;

        }

        printf("%.2lf\n",path[cnt-1]);
    }


}
