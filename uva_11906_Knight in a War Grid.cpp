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
int ara[101][101];
bool vis[101][101];
int visited[101][101];
bool valid(int r,int c)
{

    return (r>=0 && r<row && c>=0 && c<col && (ara[r][c]!=-1));
}
int bfs(int mx,int my,int kase)
{
    mst(vis), mst(visited);
    // note that (m,n) move can happen both m vertical n horizontal or vice versa
    int ver[8]= {-mx,-mx,mx,mx,my,-my,my,-my};
    int hor[8]= {my,-my,my,-my,-mx,-mx,mx,mx};
    int even=0,odd=0,cnt=0;
    queue<pi> pq;
    pq.push(mp(0,0));
    vis[0][0]=1;
    while(!pq.empty())
    {
        pi top=pq.front();
        pq.pop();
        int i=top.first, j=top.second;
        map<pi,bool> chk;

        for(int k=0; k<8; k++)
        {

            if(valid(i+hor[k],j+ver[k]))
            {
                if(!vis[i+hor[k]][j+ver[k]])
                    pq.push(mp(i+hor[k],j+ver[k])), vis[i+hor[k]][j+ver[k]]=1;
                if(chk.find(mp(i+hor[k],j+ver[k]))==chk.end())  // checking if for a same parent ,a child / grid is visited more than once
                {

                    chk[mp(i+hor[k],j+ver[k])]=1;
                    visited[i+hor[k]][j+ver[k]]++;
                }

            }

        }

    }
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            if(visited[i][j]!=0)
            {
                (visited[i][j]%2) ?  odd++ : even++;
            }

    even=(even || odd) ? even :1;   // in case no move is possible from (0,0), still we can go to (0,0) from 0 place which is even!!!
    printf("Case %d: %d %d\n",kase,even,odd);


}

int main()
{
    //infile;
    //outfile;
    int test,kase=0;
    sf(test);

    while(test--)
    {
        mst(ara);
        int mx,my,block,x,y;

        scanf("%d %d %d %d",&row,&col,&mx,&my);
        sf(block);
        for(int i=0; i<block; i++)
        {
            scanf("%d %d",&x,&y), ara[x][y]=-1;
        }

        bfs(mx,my,++kase);

    }

}

