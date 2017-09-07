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

#define V 1000001
#define pi acos(-1.0)
using namespace std;


double arcLength(double ang,double l)
{
    l=l/2.0;
    ang=ang/2.0;
    double r=l/sin(ang);
    double al=(r*ang*2.0);
    return  al;

}
bool errOk(double appr,double actual)
{

    return (abs(actual-appr)<0.00000001);
}
int main()
{

    while(1)
    {
    	int cnt=0;
        double l,t,c;
       scanf("%lf %lf %lf",&l,&t,&c);
        if(l<0) return 0;
        double angu=pi,angd=0,angm,L,appr;
        L=(1+t*c)*l;
        if(l==L)
        {
            printf("0.000\n");
            continue;
        }
        while(1)
        {
            angm=(angu+angd)/2.0;
            appr=arcLength(angm,l);
            if(appr<L) angd=angm;
            else angu=angm;
            if(errOk(appr,L)) break;
        }
        angm/=2.0;
        double displace=(l/2.0)/sin(angm)-(l/2.0)/tan(angm);
        printf("%.3lf\n",displace);
    }

}
