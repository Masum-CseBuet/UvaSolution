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

int row,col;
struct node
{
    int r,c,cost;
    node(int r,int c,int cost)
    {
        this->r = r;
        this->c = c;
        this->cost = cost;
    }

    bool operator>(const node &tmp)const
    {
        return cost>tmp.cost;
    }


};
int dirr[] = {0,0,-1,1};
int dirc[] = {1,-1,0,0};
int weight[1000][1000];
bool isValid(int r,int c)
{
    return (r>=0 && r<row && c>=0 && c<col);
}
int dijkstra(int row,int col)
{

    node src(0,0,weight[0][0]);
    priority_queue<node,vector<node>,greater<node>> pq;
    vector<vector<int>> dist;
    dist.resize(row,vector<int>(col,INF));
    dist[0][0] = weight[0][0];
    pq.push(src);
    while(!pq.empty())
    {
        node top = pq.top();
        pq.pop();
        for(int i=0; i<4; i++)
        {
            int nr = top.r+dirr[i];
            int nc = top.c+dirc[i];

            if(isValid(nr,nc))
            {
                if(dist[nr][nc]>weight[nr][nc]+top.cost)
                {
                    dist[nr][nc]=weight[nr][nc]+top.cost;
                    node tmp(nr,nc,dist[nr][nc]);
                    pq.push(tmp);
                }
            }
        }
    }

    return dist[row-1][col-1];
}
int main()
{
    int test;
    sf(test);
    while(test--)
    {
        cin>>row>>col;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                sf(weight[i][j]);
            }
        }
        int res = dijkstra(row,col);
        cout<<res<<endl;
    }

}
