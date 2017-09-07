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
#define MOD 100000007
using namespace std;
int dp[10+1][100+1];
int ara[11][101];

int findMin(int row,int col)
{
    int next[row][col];
    for(int i=0; i<row; i++)
        dp[i][col-1] = ara[i][col-1], next[i][col-1] = i;

    for(int j=col-2; j>=0; j--)
    {
        for(int i=0; i<row; i++)
        {
            dp[i][j] = INF, next[i][j] = INF;
            for(int k=-1; k<=1; k++)
            {
                int aux = (i+k+row)%row;
                if(dp[i][j]>dp[aux][j+1] ||(dp[i][j]==dp[aux][j+1] && next[i][j]>aux))
                {
                    dp[i][j] = dp[aux][j+1];
                    next[i][j] = aux;
                }

            }
            dp[i][j]+=ara[i][j];
        }
    }

    int mn = 0,indx;

    for(int i=0; i<row; i++)
    {
        if(dp[mn][0]>dp[i][0]) mn = i;
    }
    indx = mn;
    cout<<mn+1;
    for(int i=0; i<col-1; i++)
    {
        indx = next[indx][i];
        cout<<" "<<indx+1;
    }
    nl;
    cout<<dp[mn][0]<<endl;

}

int main()
{
    int row,col;
    while(cin>>row>>col)
    {
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                sf(ara[i][j]);
        findMin(row,col);
    }
}
