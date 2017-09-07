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

// a program to find the e largest alimentary chain in   nature .. in other words we need to find the largest cluster ..so we will use
// union -disjoint set algorithm to find the highest number of associativity

int  parent[5000+2];
int chain[5000+2];
int find(int child)
{
    if(parent[child]==child) return child;
    parent[child]=find(parent[child]);
    return parent[child];
}
void init(int c)
{

    for(int i=0; i<c; i++)
    {
        parent[i]=i  , chain[i]=1;
    }

}
int main()
{

    int r,c;
    while(scanf("%d %d",&c,&r)==2 && (c!=0 || r!=0))
    {

        map<string,int> imap;
        char str[35];
        int assin=0;
        init(c);
        for(int i=0; i<c; i++)
        {
            scanf("%s",str);
            if(imap.find(string(str))==imap.end())
            {
                imap[string(str)]=assin++;
            }

        }
        char str1[35],str2[35];
        for(int i=0; i<r; i++)
        {
            scanf("%s %s",str1,str2);
            int par1=find(imap[str1]);
            int par2=find(imap[str2]);
            if(par1!=par2)
            {
                parent[par2]=parent[imap[str2]]= parent[par1];
            chain[par1]+=chain[par2];
            }

        }
        int mx=*max_element(chain,chain+c);
        printf("%d\n",mx);


    }

}
