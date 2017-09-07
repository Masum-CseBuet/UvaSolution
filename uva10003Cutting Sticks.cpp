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
#define MOD 1000000
#define mp(i,j) make_pair(i,j)
#define mstn(n) memset(n,-1,sizeof(n))
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

#define V 5

using namespace std;
typedef pair<int,int> pi;
// things to be noted here is  that if we want to store the info as stick length we need to declare an array ,size of 1001 X 1001
// memset of which in every test case gave me tle
// so instead passing stick length we will use the cutting position index . as only 50 cutting position is there
//we will declare a 2-d array of 53*53 (to include 0 and the endpoint as well)
// ara[1][3] will indicate cost of cutting the part of stick of length pos[3]-pos[1]
int pos[51];
int ara[53][53];
int cut,l;
bool vis[51];

int cuttingStick(int leftCut,int rightCut,int cutRemaining)
{
    if(cutRemaining==0) return ara[leftCut][rightCut]=0;
    if(ara[leftCut][rightCut]!=-1) return ara[leftCut][rightCut];
    int optimalcost=INF,curcost=0;

    for(int i=1; i<=cut; i++)
    {

        if(!vis[i] && i<=rightCut && i>=leftCut)
        {

            vis[i]=1;
            curcost=(pos[rightCut]-pos[leftCut])+cuttingStick(leftCut,i,cutRemaining-1)+cuttingStick(i,rightCut,cutRemaining-1);
            vis[i]=0;
            optimalcost=min(optimalcost,curcost);

        }

    }
    if(optimalcost==INF) optimalcost=0;  //in case we couldn't execute the statement inside loop
    return ara[leftCut][rightCut]=optimalcost;
}

int main()
{

    while(scanf("%d",&l) && l)
    {

        sf(cut);
        mstn(ara); mst(vis);
        pos[0]=0;
        for(int i=1; i<=cut; i++)
        {
            scanf("%d",&pos[i]);
        }
        pos[cut+1]=l;
        int cost=cuttingStick(0,cut+1,cut);
        printf("The minimum cutting is %d.\n",cost);

    }
}

