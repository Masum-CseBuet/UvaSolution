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
#define mstn(n) memset(n,-1,sizeof(n))
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)
#define pr(a) cout<<cout<<a.a.first<<"  "<< a.a.second<<endl
#define V 5
using namespace std;

int  parent[200001];
int chain[200001];
int parent_find(int child)
{
    if(parent[child]==child) return child;
    parent[child]=parent_find(parent[child]);
    return parent[child];
}
void init(int c)
{

    for(int i=0; i<c; i++)
    {
        parent[i]=i, chain[i]=1;
    }

}
int main()
{

    int test;
    sf(test);
    while(test--)
    {
        int relation;
        sf(relation);

        init(relation*2);
        int assin=0;
        map<string,int> imap;
        for(int i=0; i<relation; i++)
        {

            char str1[35],str2[35];

            scanf("%s %s",str1,str2);

            if(imap.find(str1)==imap.end()) imap[str1]=assin++;

            if(imap.find(str2)==imap.end()) imap[str2]=assin++;

            int par1=parent_find(imap[str1]);
            int par2=parent_find(imap[str2]);
            if(par1!=par2)
            {
                parent[par2]=parent[imap[str2]]= par1;
                chain[par1]+=chain[par2];

            }
            printf("%d\n",chain[par1]);

        }

    }
}

