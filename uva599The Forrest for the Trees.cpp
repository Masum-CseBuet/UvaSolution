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
struct Node
{
    int par,rnk;

};
class graph
{
public:
    int i;
    Node node[26];
    bool isNode[26];
    graph()
    {
        for(int i=0; i<26; i++)
        {
            node[i].par = i;
            node[i].rnk = 0;
        }
        mst(isNode);
    }
    void make_union(int u,int v)
    {
        int par1 = findParent(u);
        int par2 = findParent(v);
        if(node[par1].rnk>node[par2].rnk)
        {
            node[par2].par = par1;
        }
        else if(node[par2].rnk>node[par1].rnk)
        {
            node[par1].par = par2;
        }
        else
        {
            node[par1].par = par2;
            node[par2].rnk++;
        }
    }
    int findParent(int u)
    {
        return (node[u].par == u? u: node[u].par = findParent(node[u].par) );
    }
    void CountTree_acorn()
    {

        set<int> tree;
        int acorn = 0;
        for(int i=0; i<26; i++)
        {
            if(!isNode[i]) continue;
            int p = findParent(i);
            if(p==i && node[p].rnk==0) acorn++;
            else
                tree.insert(p);
        }
        cout<<"There are "<<tree.size()<<" tree(s) and "<<acorn<<" acorn(s)."<<endl;

    }
};

int main()
{
    int test;
    sf(test);
    while(test--)
    {
        graph g;
        string str;
        while(1)
        {
            cin>>str;
            if(str[0]=='*') break;
            int u = str[1]-65, v = str[3]-65;
            g.isNode[u] = g.isNode[v] = 1;
            g.make_union(u,v);
        }
        cin>>str;
        for(int i=0; i<str.length(); i+=2)
            g.isNode[str[i]-65] = 1;
        g.CountTree_acorn();
    }

}


