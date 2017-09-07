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
#define MOD 1000000007
using namespace std;
int ara[8][8];
bool vis[8];
bool diag1[16];
bool diag2[16];
vector<int> rowPos;
inline int dg1(int r,int c)
{
    return (7+c-r);
}
inline int dg2(int r,int c)
{
    return (7+(7-c)-r);
}
int backTrack(int col)
{
    if(col==8)
    {
        int cnt = 0;
        for(int i=0; i<8; i++)
        {
            cnt+=ara[rowPos[i]][i];
        }
        return cnt;
    }
    int mx = -INF,tmp;
    for(int r=0; r<8; r++)
    {
        if(vis[r] || diag1[dg1(r,col)] || diag2[dg2(r,col)]) continue;

        vis[r] = 1;
        diag1[dg1(r,col)] = 1;
        diag2[dg2(r,col)] = 1;
        rowPos.push_back(r);

        tmp = backTrack(col+1);
        mx = max(mx,tmp);

        rowPos.erase(rowPos.begin()+col);
        vis[r]  = 0;
        diag1[dg1(r,col)] = 0;
        diag2[dg2(r,col)] = 0;
    }
    return mx;
}
int main()
{
    int n;
    sf(n);
    int kase = 1;
    while(n--)
    {
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
                sf(ara[i][j]);
        }
        printf("%5d\n",backTrack(0));
    }


}

