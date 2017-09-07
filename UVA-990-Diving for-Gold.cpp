#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n);
#define nl printf("\n")
#define mst(n) memset(n,0,sizeof(n))

using namespace std;
typedef struct Treasure
{
    int depth,depth_time,gold,indx;
    bool taken=false;
} trsr;

trsr Make_Pair(int d,int g,int indx,int w)
{
    trsr a;
    a.depth=d , a.depth_time=3*w*d , a.gold=g , a.indx=indx;
    return a;
}
bool cmp(trsr a,trsr b)   {  return a.depth<b.depth ;   }

bool cmp_2(trsr a,trsr b)  {  return a.indx<b.indx ;    }

int knapSack(int t,vector<trsr> & profit,int cnt)
{
    int ara[32][1002];
    memset(ara,0,sizeof(ara));
    vector<int> show;
    int i,j,cnt2=0;
    for( i=1; i<=cnt; i++)
    {
        for( j=1; j<=t; j++)
        {
            if(profit[i-1].depth_time > j)      ara[i][j]=ara[i-1][j];
            else
            {
                ara[i][j]=max(ara[i-1][j], profit[i-1].gold+ara[i-1][j-profit[i-1].depth_time]);
            }
        }

    }

    printf("%d\n",ara[cnt][t]);
    i=cnt,j=t;
    while(ara[i][j]!=0)
    {
        if(ara[i][j]==ara[i-1][j]) i--;
        else
        {

            profit[i-1].taken=1, j=j-profit[i-1].depth_time, i--,cnt2++ ;
        }

    }
    sort(profit.begin(),profit.end(),cmp_2);

    printf("%d\n",cnt2);
    for(i=0; i<cnt; i++)
    {
        if(profit[i].taken)
        {
            printf("%d %d\n",profit[i].depth,profit[i].gold);
        }
    }
}
int main()
{
    int t,w;
    bool new_line=false;
    while(scanf("%d %d",&t,&w)==2)
    {
        int how;
        if(new_line) printf("\n");
        new_line=1;
        sf(how);
        vector<trsr> profit;
        int depth,gold,i;

        for( i=0; i<how; i++)
        {
            scanf("%d %d",&depth,&gold);
            profit.push_back(Make_Pair(depth,gold,i,w));
        }
        sort(profit.begin(),profit.end(),cmp);

        knapSack(t,profit,how);

    }
}
