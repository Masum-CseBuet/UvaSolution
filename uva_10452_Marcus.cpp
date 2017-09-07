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
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pi;

inline bool valid(pi a,int len,int wid)
{
    return (a.fi>=0 && a.fi<len && a.se>=0 && a.se<wid);
}

int main()
{

    int test;
    scanf("%d",&test);
    while(test--)
    {
        char ara[8][8];
        int dirx[3]= {-1,0,0},diry[3]= {0,1,-1};
        int len,wid;

        pi src,des;
        scanf("%d %d\n",&len,&wid);

        for(int i=0; i<len; i++)
        {
            for(int j=0; j<wid; j++)
            {

                scanf("%c",&ara[i][j]);

                if(ara[i][j]=='@') src.fi=i, src.se=j ;

                if(ara[i][j]=='#')  des.fi=i,des.se=j ;
            }
            getchar();

        }

        char str[]="IEHOVA#";
        int order=0;
        while(src!=des)
        {
            pi tmp=src;
            for(int i=0; i<3; i++)
            {
                tmp.fi+=dirx[i],tmp.se+=diry[i];
                if(valid(tmp,len,wid))
                {

                    if(ara[tmp.fi][tmp.se]==str[order])
                    {

                        order++;

                        if(i==0) printf("forth");
                        else if(i==1) printf("right");
                        else if(i==2) printf("left");
                        src=tmp;
                        if(src!=des) printf(" ");

                    }

                }
                tmp.fi-=dirx[i],tmp.se-=diry[i];
            }
        }
        nl;


    }
}
