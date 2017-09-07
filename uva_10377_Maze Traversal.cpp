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
// one tricky point is that initially robot can stay out of the maze boundary

int row,col;
char maze[60+1][60+1];

inline bool valid(int r,int c)
{
    return ((r>=0 && c>=0 ) && (maze[r][c]!='*'));
}


int main()
{


    int test;
    sf(test);
    bool nel=0;
    while(test--)
    {
        mst(maze);
        if(nel) nl;
        nel=1;

        scanf("%d %d\n",&row,&col);
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                scanf("%c",&maze[i][j]);
            }
            getchar();
        }
        int x,y;
        int dir[4][2]= { {-1,0}, {0,1},{1,0}, {0,-1} } ;  // for movement respectively dir[0]-> north -- dir[1]-> East -- dir[2]-> South --- dir[3]->West (clockwise )

        scanf("%d %d",&x,&y);
        x--,y--;
        int mod=0;
        while(1)
        {
            char com;
            scanf("%c",&com);
            if(com=='R') mod++;  // just rotate one more time clockwise
            else if(com=='L') mod--;  // rotate anticlockwise
            else if(com=='F')
            {
                mod=(4*(mod<0)+mod)%4;  // if mod (rotation) is negative then we will add/subtract from 4 ;
                if(valid(x+dir[mod][0],y+dir[mod][1]))
                {
                    x+=dir[mod][0], y+=dir[mod][1];
                }

            }
            else if(com=='Q')
            {
                mod=(4*(mod<0)+mod)%4;
                char d=(mod==0) ? 'N' : ( mod==1? 'E' : ( mod==2 ? 'S' : 'W'));

                printf("%d %d %c\n",x+1,y+1,d);
                break;
            }

        }
    }


}

