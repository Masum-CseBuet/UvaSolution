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
#define mstn(n) memset(n,-1,szeof(n))
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)
#define ull unsigned long long
#define V 1000001
#define sz 1005
#define mod 1000000007
using namespace std;
class Graph
{
public:
    int ver,mapCnt;
    vector<vector<int>> adlist;
    vector<vector<int>> transposedAdlist;
    vector<vector<int>> showSCCS;
    vector<int> tmp;
    stack<int> finishingOrderStack;
    map<string,int> imap;
    map<int,string> indxToName;
    Graph(int ver)
    {
        this->ver = ver;
        mapCnt=0;
        adlist.resize(ver);
        transposedAdlist.resize(ver);
    }
    void addEdge(char str1[],char str2[])
    {
        if(imap.find(str1)==imap.end())
        {
            imap[str1] = mapCnt++;
        }
        if(imap.find(str2)==imap.end())
        {
            imap[str2] = mapCnt++;
        }
        int c1 = imap[str1], c2= imap[str2];
        indxToName[c1]=str1, indxToName[c2] = str2;
        adlist[c1].push_back(c2);
    }
    void getTranspose()
    {
        for(int i=0; i<ver; i++)
        {
            int siz = adlist[i].size();
            for(int j=0; j<siz; j++)
            {
                int cur = adlist[i][j];
                transposedAdlist[cur].push_back(i);

            }

        }
    }
    void fillOrder(int v,vector<bool> &vis)
    {

        vis[v]=true;
        int siz = adlist[v].size();

        for(int i=0; i<siz; i++)
        {
            int cur = adlist[v][i];

            if(!vis[cur])
            {
                fillOrder(cur,vis);
            }
        }
        finishingOrderStack.push(v);
    }
    void dfsUtil(int v,vector<bool> &vis)
    {

        tmp.push_back(v);

        vis[v] = true;
        int siz = transposedAdlist[v].size();
        for(int i=0; i<siz; i++)
            if(!vis[transposedAdlist[v][i]])
                dfsUtil(transposedAdlist[v][i],vis);

    }
    void printSCCS()
    {
        vector<bool> vis(ver);
        for(int i=0; i<ver; i++)
        {
            if(!vis[i])
                fillOrder(i,vis);
        }
        fill(vis.begin(),vis.end(),false);

        getTranspose();

        while(!finishingOrderStack.empty())
        {
            int cur = finishingOrderStack.top();
            finishingOrderStack.pop();
            if(!vis[cur])
            {
                dfsUtil(cur,vis);
                showSCCS.push_back(tmp);
                tmp.clear();

            }
        }
        for(int i=0; i<showSCCS.size(); i++)
        {
            int siz = showSCCS[i].size();

            for(int j=0; j<siz; j++)
            {
                int cur = showSCCS[i][j];
                cout<<indxToName[cur];

                if(j!=siz-1)
                    cout<<", ";
            }
            nl;
        }

    }
};
int main()
{

    int kase = 1;
    bool chk = false;
    while(1)
    {
        int ver,edge;
        scanf("%d %d",&ver,&edge);
        if(ver==0) return 0;
        if(chk) nl;
        chk=true;
        Graph g(ver);
        int cnt=0;
        for(int i=0; i<edge; i++)
        {
            char str1[80],str2[80];
            scanf("%s %s",str1,str2);
            g.addEdge(str1,str2);
        }
        printf("Calling circles for data set %d:\n",kase++);
        g.printSCCS();

    }
}

