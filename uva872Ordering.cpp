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
//All possible topsort print  // if it's not DAG, then there is no topsort and then you have to print "NO";
class Graph
{
public:
    int ver,cnt;
    vector<int> *adlist;
    vector<int> indegree;
    vector<char> show;
    vector<string> result;
    vector<char> inp;
    vector<bool> vis;
    map<char,int> imap;
    map<int,char> indxToChar;
    bool isDAG;
    Graph(vector<char> &inp)
    {
        ver= inp.size();
        this->inp = inp;
        cnt = 0;
        isDAG = false;
        adlist = new vector<int>[ver];
        indegree.resize(ver);
        vis.resize(ver);
        for(int i=0; i<ver; i++)
        {
            imap[inp[i]] = cnt++;
            indxToChar[cnt-1] = inp[i];
        }
    }
    void addEdge(char a,char b)
    {
        int c1= imap[a],c2 = imap[b];
        adlist[c1].push_back(c2);
        indegree[c2]++;
    }
    // simple backtracking
    void allTopSort()
    {
        bool flag = false; // to check whether every node has been included in the show vector
        for(int i=0; i<ver; i++)
        {
            if(indegree[i]==0 && !vis[i])
            {
                //cout<<i<<"  ";
                vis[i] = true;
                int siz = adlist[i].size();
                for(int j=0; j<siz; j++)
                    indegree[adlist[i][j]]--;

                show.push_back(i);
                allTopSort();

                vis[i] = false;
                show.erase(show.end()-1);
                for(int j=0; j<siz; j++)
                    indegree[adlist[i][j]]++;

                flag = true;
            }
        }
        if(!flag && show.size()!=0)
        {
            isDAG = true;
            string str;

            for(int i=0; i<ver; i++)
            {

                str.push_back(indxToChar[show[i]]);
                if(i!=ver-1)
                    str.push_back(' ');
            }
            result.push_back(str);
        }

    }
    ~Graph()
    {
        delete[] adlist;
    }
};
int main()
{

    int test;
    sf(test);
    getchar();
    bool nel = false;
    while(test--)
    {
        getchar();
        if(nel) nl;
        nel = true;
        vector<char>  inp;
        while(1)
        {
            char ch;
            scanf("%c",&ch);
            if(isalpha(ch)) inp.push_back(ch);
            if(ch=='\n') break;
        }
        Graph g(inp);

        while(1)
        {
            char a,b;
            scanf("%c<%c",&a,&b);
            g.addEdge(a,b);
            a = getchar();
            if(a=='\n') break;
        }
        g.allTopSort();
        if(g.isDAG)
        {
            int siz = g.result.size();
            sort(g.result.begin(),g.result.end());
            for(int i=0; i<siz; i++)
            {
                cout<<g.result[i]<<endl;
            }
        }
        else
        {
            cout<<"NO"<<endl;
        }

    }

}
