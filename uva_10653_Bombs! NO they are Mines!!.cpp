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
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)
#define pr(a) cout<<cout<<a.a.first<<"  "<< a.a.second<<endl
using namespace std;


typedef pair<int,int> pi;

int bfs(int r,int c,vector<vector<int>> &ara)
{
    int x,y;
    bool vis[r][c]= {};
    int level[r][c]= {};
    mst(vis), mst(level);
    pi src,des;
    pi dir[4];
    dir[0]=mp(0,1),dir[1]=mp(1,0),dir[2]=mp(-1,0),dir[3]=mp(0,-1);

    scanf("%d %d",&src.first,&src.second),scanf("%d %d",&des.first,&des.second);

    queue<pi> show;
    show.push(src);
    vis[src.first][src.second]=1;

    level[src.first][src.second]=0;
    while(!show.empty())
    {
        pi top=show.front(),show.pop();

        for(int i=0; i<4; i++)
        {
            x=top.first+dir[i].first, y=top.second+ dir[i].second;

            if( ( x>=0 && x<r && y>=0 && y<c) && ara[x][y]!=-1 && !vis[x][y])
            {

                vis[x][y]=1, show.push(mp(x,y));

                level[x][y]=level[top.first][top.second]+1;

                if(x==des.first && y==des.second)
                {
                    return level[x][y];
                }
            }
        }
    }


}


int main()
{

    while(1)
    {
        int r,c;
        scanf("%d %d",&r,&c);

        if(r==0 && c==0) return 0;
        vector<vector<int>> ara;
        ara.resize(r,vector<int>(c,0));

        int bombs;
        sf(bombs);
        for(int i=0; i<bombs; i++)
        {
            int row,col,num;
            sf(row),sf(num);
            for(int j=0; j<num; j++)
            {
                sf(col), ara[row][col]=-1;

            }

        }

        int way= bfs(r,c,ara);
        printf("%d\n",way);
    }

}
