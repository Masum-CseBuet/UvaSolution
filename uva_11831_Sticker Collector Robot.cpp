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

int row,col;
char maze[100+10][100+10];

inline bool valid(int r,int c)
{
    return ((r>=0 && r<row && c<col && c>=0 ) && (maze[r][c]!='#'));
}


int main()
{

    //infile;
   // outfile;
    int cmd;
    while(1)
    {
        scanf("%d %d %d\n",&row,&col,&cmd);
        if(row==0 && col==0 && cmd==0) return 0;
        mst(maze);
        bool flag=0;
        int x,y,mod;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                scanf("%c",&maze[i][j]);
                if(!flag && isalpha(maze[i][j]))
                {
                    if(maze[i][j]=='N') mod=0;
                    else if(maze[i][j]=='L') mod=1;
                    else if(maze[i][j]=='S') mod=2;
                    else if(maze[i][j]=='O')  mod=3;
                    flag=1,x=i,y=j;
                }

            }
            getchar();
        }

        int dir[4][2]= { {-1,0}, {0,1},{1,0}, {0,-1} } ;

        int cnt=0;
        while(cmd--)
        {
            char com;
            scanf("%c",&com);

            if(com=='D') mod++;
            else if(com=='E') mod--;
            else if(com=='F')
            {
                mod=(4*(mod<0)+mod)%4;
                if(valid(x+dir[mod][0],y+dir[mod][1]))
                {
                    x+=dir[mod][0], y+=dir[mod][1];
                    if(maze[x][y]=='*')
                    {
                        cnt++;
                        maze[x][y]='.';
                    }
                }

            }

        }

        printf("%d\n",cnt);
    }

    return 0;
}

