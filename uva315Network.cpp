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
vector<int> adlist[100];
bool vis[100];
int disc[100],low[100],parent[100];
int numOfAP,tim;
bool APcounted[100];
void APUtil(int vertex)
{

    int children = 0;
    vis[vertex] =true;
    low[vertex]  = disc[vertex] = tim++;
    int siz = adlist[vertex].size();
    for(int i=0; i<siz; i++)
    {
        int cur = adlist[vertex][i];
        if(!vis[cur])
        {
            children++;
            parent[cur] = vertex;
            APUtil(cur);
            low[vertex] = min(low[vertex],low[cur]);
            if(parent[vertex]==-1 && children>=2 && APcounted[vertex]==0)
            {
                numOfAP++,APcounted[vertex]=1;
            }
            else if(parent[vertex]!=-1 && disc[vertex]<=low[cur] && APcounted[vertex]==0)
            {
                numOfAP++,APcounted[vertex]=1;
            }
        }
        else if(cur!=parent[vertex])
        {
            low[vertex] = min(disc[cur],low[vertex]);
        }
    }
}
int findingArticulationPoint(int ver)
{
    for(int i=0; i<ver; i++)
    {
        if(!vis[i])
        {
            parent[i] = -1;
            APUtil(i);
        }
    }
}
void clearAll(int v)
{
    mst(vis), mst(low), mstn(parent), mst(disc), mst(APcounted);
    numOfAP=0, tim = 0;
    for(int i=0; i<v; i++)
    {
        adlist[i].clear();
    }
}
int main()
{
    // infile;outfile;
    int place;
    while(1)
    {
        sf(place);
        getchar();
        if(place==0) return 0;
        string str;
        clearAll(place);
        while(1)
        {

            getline(cin,str);
            stringstream ss(str);
            int u,v;
            ss>>u;
            if(u==0) break;
            while(ss>>v)
            {
                adlist[u-1].pb(v-1);
                adlist[v-1].pb(u-1);
            }

        }
        findingArticulationPoint(place);
        cout<<numOfAP<<endl;

    }

}
