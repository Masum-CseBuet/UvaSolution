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
using namespace std;
bool block[101][101];
int NumberOfWays(int row,int col)
{
    int dp[101][101];
    mst(dp);

    for(int i=1; i<=row; i++)
        dp[i][1] = 1;

    for(int i=1; i<=row; i++)
    {
        for(int j=2; j<=col; j++)
        {
            if(block[i][j]) continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[row][col];
}
int main()
{
    int test;
    sf(test);
    bool nel = false;
    while(test--)
    {
        mst(block);
        if(nel) nl;
        nel = 1;
        int r,c;
        scanf("%d %d",&r,&c);
        getchar();

        for(int i=0; i<r; i++)
        {

            string str;
            getline(cin,str);
            stringstream ss(str);
            int row,col;
            ss>>row;
            while(ss>>col)
            {
                block[row][col] = 1;
            }
        }

        cout<<NumberOfWays(r,c)<<endl;
    }
}
