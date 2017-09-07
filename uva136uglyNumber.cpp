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
#define mstn(n) memset(n,-1,szeof(n))
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)
#define ull unsigned long long
#define V 1000001
#define sz 1005
#define mod 1000000007
using namespace std;





int main()
{
    //infile;
    //outfile;
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int row1,col1,row2,col2;
        row1 = sqrt(n);
        row2 = sqrt(m);
        col1 = n-row1*row1;
        col2 = m-row2*row2;
        double x = sqrt(1-.5*.5);
        double upDir1, upDir2;

        upDir1 = (col1%2==0) ? 1:0;
        upDir2 = (col2%2==0) ? 1:0;

        if(row1>row2 || (row1==row2 && upDir1>upDir2))
        {
            swap(row1,row2), swap(col1,col2), swap(upDir1,upDir2);
        }

        double horizontalDis = abs(col1-col2)*.5 - .5*abs(row1-row2);

        double verticalDis = (abs(row1-row2) + 1) * x;
        upDir1==1? verticalDis-=2*x/3.0 : verticalDis-= x/3.0;
        upDir2==1? verticalDis-=x/3.0 : verticalDis-= 2*x/3.0;
        //printf("%.3lf\n",(sqrt(verticalDis*verticalDis + horizontalDis*horizontalDis)));
        cout<<(sqrt(verticalDis*verticalDis + horizontalDis*horizontalDis))<<endl;

    }
}






