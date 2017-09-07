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
#define mod 1000000007
using namespace std;

bool grid[51][51];
int val[51][51]; // cost of cells will be stord here
int row,col;
double destr,destc;
bool isOK(double r,double c)
{
    if(r<0 || r>=row-.5 || c<0 || c>=col-.5) return 0;  // be careful no edge of the grid  is allowed to traverse as the diameter of robot is 1.6
    // checking if there are any obstacle in any 4 adjacent cell of current position
    return (!grid[(int)(r-.5)][(int)(c-.5)] && !grid[(int)(r-.5)][(int)(c+.5)] && !grid[(int)(r+.5)][(int)(c-.5)] && !grid[(int)(r+.5)][(int)(c+.5)]);
}
int dirr[]= {0,0,0,-1,-2,-3,0,0,0,1,2,3};
int dirc[] = {1,2,3,0,0,0,-1,-2,-3,0,0,0};
bool vis[51][51][4]; // here 4 means that a cell can be visited from 4 direction
// we are assuming all the coordintes of centre to be .5 less than the its integer cell's row and column value

class info
{
public:
    double r,c;
    int state,cost;
    info(double r,double c,int state,int cost)
    {
        this->r =r;
        this->c = c;
        this->state=state;
        this->cost = cost;
    }
};
//bfs
int traversal(int sState,double r,double c)
{
    if(!isOK(destr,destc)) return -1;
    int costOfRotation;
    queue<info> q;
    info src(r,c,sState,0);
    q.push(src);
    vis[(int)(r+.5)][(int)(c+.5)][sState] = true;
    while(!q.empty())
    {
        info top = q.front();
        q.pop();
        for(int state=0; state<4; state++)
        {
            costOfRotation = (abs(top.state-state))%3 + (abs(top.state-state)==3?1:0); //how many seconds does it require to rotate from previous to current state

            for(int i=0; i<3; i++)
            {
                double nr = top.r+dirr[3*state+i];
                double nc = top.c+dirc[3*state+i];
                int inr = (int)(nr+.5) , inc = (int) (nc+.5); //back to integer value
                int totalCost = top.cost+costOfRotation+1;
                int v = val[(int)(nr+.5)][(int)(nc+.5)]; //
                if(nr==destr && nc==destc)
                {
                    val[inr][inc] = min( (v>0?v:INF), totalCost ); // if the current cost of the cell is greater than the new totalcost then it will br replaced
                    continue;
                }
                if(isOK(nr,nc))
                {
                    if(!vis[inr][inc][state] || totalCost<v)
                    {
                        vis[inr][inc][state] = true;
                        info tmp(nr,nc,state,totalCost);
                        val[inr][inc] = min( (v>0?v:INF), totalCost );
                        q.push(tmp);
                    }
                }
                else
                    break;
            }
        }

    }
    return val[(int)(destr+.5)][(int)(destc+.5)];
}
int main()
{
    while(1)
    {
        mst(grid), mst(vis),mstn(val);
        cin>>row>>col;
        if(row==0 && col==0) return 0;

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                int x;
                sf(x);
                grid[i][j] = (x==0)? 0 :1;
            }
        }

        double sx,sy;
        string dir;
        cin>>sx>>sy>>destr>>destc>>dir;
        sx-=.5, sy-=.5, destr-=.5, destc-=.5;

        int state;
        if(dir=="east") state = 0;
        else if(dir=="north") state = 1;
        else if(dir=="west") state = 2;
        else if(dir=="south") state = 3;

        if(sx==destr && sy==destc) cout<<0<<endl;

        else
        {
            int res = traversal(state,sx,sy);
            cout<<res<<endl;
        }


    }
}

