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
int m,n;
char ara[101][101];
bool vis[101][101];
int dirr[8] = {0,0,-1,-1,-1,1,1,1};
int dirc[8] = {1,-1,1,0,-1,1,0,-1};
inline bool isValidCell(int row,int col)
{
    return (row>=0 && row<m && col>=0 && col<n);
}
bool floodFill(int row,int col)
{
    if(!isValidCell(row,col) || ara[row][col]=='*' || vis[row][col]) return false;
    else
    {
        vis[row][col] = true;
        for(int i=0; i<8; i++)
        {
            floodFill(row+dirr[i],col+dirc[i]);
        }
    }
    return true;
}
int main()
{
    while(1)
    {
        mst(vis), mst(ara);
        int cnt =0;
        scanf("%d %d",&m,&n);
        getchar();
        if(m==0) return 0;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%c",&ara[i][j]);
            }
            getchar();
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(floodFill(i,j))
                    cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}

