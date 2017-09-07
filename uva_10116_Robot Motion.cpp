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
typedef pair<int,int> pi;
int row,col;
inline bool valid(int r,int c)
{
    return (r>=0 && r<row && c>=0 && c<col);
}

int main()
{

    int ent;
    while(scanf("%d %d %d\n",&row,&col,&ent) && (row || col || ent) )
    {
        int x,y;
        char dir[row+1][col+1];
        bool vis[row+1][col+1];
        int dis[row+1][col+1];
        mst(vis), mst(dis);
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                scanf("%c",&dir[i][j]);
            }
            getchar();
        }
        x=0,y=ent-1;
        vis[x][y]=1;
        pi prev=mp(x,y);

        while(1)
        {
            if(dir[x][y]=='N') x-=1;
            else if(dir[x][y]=='S') x+=1;
            else if(dir[x][y]=='E') y+=1;
            else if(dir[x][y]=='W') y-=1;
            if(valid(x,y))
            {

                if(vis[x][y])
                {
                    printf("%d step(s) before a loop of %d step(s)\n",dis[x][y],dis[prev.first][prev.second]-dis[x][y]+1);
                    break;
                }
                vis[x][y]=1, dis[x][y]=dis[prev.first][prev.second]+1;

            }
            else
            {
                printf("%d step(s) to exit\n",dis[prev.first][prev.second]+1);
                break;
            }
            prev=mp(x,y);
        }

    }

}

