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

int mapping(int n,int &cnt,map<int,int> &imap)
{
    if(imap.find(n)==imap.end())
    {
        imap[n] = cnt++;
    }
    return imap[n];
}
struct node
{
    int indx,rnk,parent,connctd;
    node(int n)
    {
        indx = n, rnk = 0, parent = n, connctd = 1;
    }
    node() {}
};
node ara[30000];
int findParent(node a)
{
    return (a.parent==a.indx? a.indx: ara[a.indx].parent = findParent(ara[a.parent]));
}
void make_union(int u,int v)
{
    int p1 = findParent(ara[u]);
    int p2 = findParent(ara[v]);
    if(p1==p2) return;
    if(ara[p1].rnk>ara[p2].rnk)
    {
        ara[p2].parent = ara[p1].indx;
        ara[p1].connctd+= ara[p2].connctd;
    }
    else if(ara[p1].rnk<ara[p2].rnk)
    {
        ara[p1].parent = ara[p2].indx;
        ara[p2].connctd+= ara[p1].connctd;
    }
    else
    {
        ara[p2].parent = ara[p1].indx;
        ara[p1].connctd+= ara[p2].connctd;
        ara[p1].rnk++;
    }
}
void clr(int n)
{
    for(int i=0; i<n; i++)
        ara[i].indx=-1;
}
int main()
{

    int num,grp;
    while(scanf("%d %d",&num,&grp) && (num || grp))
    {
        clr(num);
        ara[0] = node(0);
        for(int i=0; i<grp; i++)
        {
            int how,frst,x;

            sf(how);
            sf(frst);
            for(int j=1; j<how; j++)
            {
                sf(x);
                if(ara[frst].indx!=frst) ara[frst] = node(frst);
                if(ara[x].indx!=x) ara[x] = node(x);
                make_union(frst,x);
            }
        }
        cout<<ara[findParent(ara[0])].connctd<<endl;
    }
}

