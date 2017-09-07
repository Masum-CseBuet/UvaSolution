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
#define V 5
using namespace std;
vector<int> adlist[101];
bool vis[101];

int bfs(int st)
{
    queue<int> show;
    show.push(st);
    int cnt=0;
    while(!show.empty())
    {
        int top=show.front();
        show.pop();
        for(int i=0;i<adlist[top].size();i++)
        {
            int tmp=adlist[top][i];

            if(!vis[tmp])
            {
                show.push(tmp);
                vis[tmp]=1 ,cnt++;
            }
        }
    }
    return cnt;
}
int main()
{

    int node,ara[101];
    while(1)
    {
        sf(node);
        if(node==0) return 0;
        int from,to,num,st,i=0;
        for(int i=0;i<=100;i++) adlist[i].clear();
        while(sf(from) && from)
        {
            while(sf(to) && to)
            {
                adlist[from].pb(to);
            }
        }
        sf(num);
        for(int i=0;i<num;i++)
        {
            sf(st);
            int vis_num=bfs(st);
            printf("%d",node-vis_num);
            for(int i=1;i<=node;i++)
                if(!vis[i])
                printf(" %d",i);
            nl;
            mst(vis);
        }

    }


}
