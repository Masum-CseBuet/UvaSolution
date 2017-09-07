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
double areaCalc(double arax[],double aray[])
{
    double x=0,y=0;
    for(int i=0;i<3;i++)
    {
        x+=(arax[i]*aray[(i+1)%3]) ,y+=(aray[i]*arax[(i+1)%3]);
    }

    double area=abs(x-y)/2.0;
    return area;
}
int main()
{
    int test;
    sf(test);
    while(test--)
    {
        double arax[3];
        double aray[3];
        for(int i=0;i<3;i++)
        {
            scanf("%lf %lf",&arax[i],&aray[i]);
        }
        double area= areaCalc(arax,aray)/7.0;
        cout<<(int)round(area);
        nl;
    }


}
