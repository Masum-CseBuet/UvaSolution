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
vector<int> adlist[26+1];
bool vis[26+1];
int dfsUtil(int st)
{
    vis[st]=1;
    for(int i=0; i<adlist[st].size(); i++)
    {
        if(!vis[adlist[st][i]])
        {
            dfsUtil(adlist[st][i]);
        }
    }
}
int dfs(int top)
{
    int cnt=0;
    for(int i=1; i<=top; i++)
    {
        if(!vis[i])
        {
            dfsUtil(i), cnt++;
        }

    }
    return cnt;
}
int main()
{

    int test;
    char str[5];
    scanf("%d\n",&test);

    bool nel=0;
    while(test--)
    {
        if(nel) nl;
        nel=1;
        gets(str);
        int top=str[0]-'A'+1;
        mst(vis);
        for(int i=1; i<=26; i++) adlist[i].clear();
        while(gets(str))
        {

            if(strlen(str)==0) break;
            int a1=str[0]-'A'+1,a2=str[1]-'A'+1;

            adlist[a1].pb(a2), adlist[a2].pb(a1);

        }
        int ret=dfs(top);
        printf("%d\n",ret);



    }
}
