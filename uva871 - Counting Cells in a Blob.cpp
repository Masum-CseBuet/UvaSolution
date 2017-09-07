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
char ara[25][25];
bool vis[25][25];
int dirr[8] = {0,0,-1,-1,-1,1,1,1};
int dirc[8] = {1,-1,1,0,-1,1,0,-1};
inline bool isValidCell(int row,int col)
{
    return (row>=0 && row<m && col>=0 && col<n);
}
int floodFillUtil(int row,int col)
{
    int cnt=0;
    if(!isValidCell(row,col) || ara[row][col]=='0' || vis[row][col]) return 0;
    else
    {
        cnt = 1;
        vis[row][col] = true;
        for(int i=0; i<8; i++)
        {
            cnt+=floodFillUtil(row+dirr[i],col+dirc[i]);
        }
    }
    return cnt;
}
int floodFill()
{
    int mx =0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!vis[i][j])
            {
                mx= max(mx,floodFillUtil(i,j));
            }
        }
    }
    return mx;
}
int main()
{

    int test;
    bool nel = false;
    scanf("%d",&test);
    getchar();
    getchar();
    while(test--)
    {
        if(nel) nl;
        nel = true;
        m=0, n=0;
        mst(vis), mst(ara);
        char ch;
        while((ch=getchar())!='\n')
        {
            if(ch==EOF) break;
            n=0;
            m++;
            ara[m-1][n++]=ch;
            while((ch=getchar())!='\n')
            {
                ara[m-1][n++]=ch;
            }
        }

        cout<<floodFill()<<endl;
    }
}

