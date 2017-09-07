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

using namespace std;
typedef pair<int,int> pi;
bool vis[102][102];
int row,col;
char wetland[102][102];
int dirr[]= {0,0,-1,-1,-1,1,1,1};
int dirc[]= {1,-1,0,1,-1,0,1,-1};
inline bool valid(int r,int c)
{
    return (r>=0 && c>=0 && r<row && c<col && wetland[r][c]=='W');
}

int dfs(int r,int c)
{
    int ans=0;
    if(valid(r,c))
    {
        ans=1;
        vis[r][c]=1;
        for(int i=0; i<8; i++)
        {
            if(!vis[r+dirr[i]][c+dirc[i]])
                ans+=dfs(r+dirr[i],c+dirc[i]);
        }

    }
    return ans;

}
int main()
{

    int test;
    bool nel=0;
    scanf("%d\n\n",&test);

    while(test--)
    {
        if(nel)  nl;
        nel=1;
        char str[101];
        int r=0;
        while(gets(str) && strlen(str)>0)
        {
            if(str[0]=='W' || str[0]=='L')
            {
                strcpy(wetland[r++],str);

                col=strlen(str);
            }
            else
            {
                mst(vis);
                row=r;


                int ro,co;
                sscanf(str,"%d %d",&ro,&co);
                int ret=dfs(ro-1,co-1);
                printf("%d\n",ret);
            }

        }


    }



}
