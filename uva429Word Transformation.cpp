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

class graph
{
public:
    int n,dest;
    vector<int> *adlist;
    bool *vis;
    graph(int n)
    {
        this->n = n;
        adlist = new vector<int>[n];
        vis = new bool[n];
    }
    void resetAll()
    {
        for(int i=0; i<n; i++) vis[i] = false;
    }
    void addEdge(int u,int v)
    {
        adlist[u].push_back(v);
        adlist[v].push_back(u);
    }

    int bfs(int from,int dest)
    {
        resetAll();
        int dist[n];
        mst(dist);
        vis[from] =1;
        queue<int> q;
        q.push(from);
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            int siz = adlist[top].size();
            for(int i=0; i<siz; i++)
            {
                int v = adlist[top][i];
                if(!vis[v])
                {
                    vis[v] = true;
                    dist[v] = dist[top]+1;
                    q.push(v);
                    if(v==dest) return dist[v];
                }
            }
        }
    }
};
int numOfMismatch(string a,string b)
{
    int len = a.length();
    int dif = 0;
    for(int i=0; i<len; i++)
    {
        if(a[i]!=b[i]) dif++;
    }
    return dif;
}
int main()
{
    bool nel = false;
    int test,kase = 1;
    sf(test);
    while(test--)
    {
        if(nel) nl;
        nel =true;
        int node=0,e,i=0;
        string str;
        vector<string> strList[10+1];
        map<string,int> imap;
        while(1)
        {
            cin>>str;
            imap[str] = i++;
            node++;
            strList[str.length()].push_back(str);
            if(str=="*") break;
        }
        graph g(node);
        for(int i=1; i<=10; i++)
        {
            int siz = strList[i].size();
            for(int j=0; j<siz; j++)
            {
                for(int k=0; k<j; k++)
                {
                    if(numOfMismatch(strList[i][j],strList[i][k])==1)
                    {
                        g.addEdge(imap[strList[i][j]],imap[strList[i][k]]);
                    }
                }

            }
        }
        getchar();
        while(1)
        {
            getline(cin,str);
            if(str.length()==0) break;
            stringstream ss(str);
            string s1,s2;
            ss>>s1>>s2;
            cout<<s1<<" "<<s2<<" "<<g.bfs(imap[s1],imap[s2])<<endl;
        }

    }
}

