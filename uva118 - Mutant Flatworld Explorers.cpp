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
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define mp(i,j) make_pair(i,j)
#define mstn(n) memset(n,-1,sizeof(n))
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)
#define ull unsigned long long
#define V 1000001
#define sz 1005
#define MOD 1000000
#define BLUE 1
#define RED 0
using namespace std;
////////
int dirx[] = {1,0,-1,0};
int diry[] = {0,1,0,-1};
////////
int ux,uy,ix,iy;
bool block[51][51];
inline bool isValid(int x,int y)
{
    return x>=0 && x<=ux && y>=0 && y<=uy;
}
inline char intToChar(int id)
{
    if(id==0) return 'E';
    if(id==1) return 'N';
    if(id==2) return 'W';
    if(id==3) return 'S';
}
inline int charToInt(char id)
{
    if(id=='E') return 0;
    if(id=='N') return 1;
    if(id=='W') return 2;
    if(id=='S') return 3;
}
inline int mod(int i,int m)
{
    return (i+m)%m;
}
int main()
{
    char dir;
    scanf("%d %d",&ux,&uy);
    mst(block);
    while(scanf("%d %d %c",&ix,&iy,&dir)!=EOF)
    {
        int id = charToInt(dir);
        string str;
        cin>>str;
        for(int i=0; i<str.length(); i++)
        {
            if(str[i]=='R' && isValid(ix,iy))
            {
                id  = mod(id-1,4);
            }
            else if(str[i]=='L' && isValid(ix,iy))
            {
                id = mod(id+1,4);
            }
            else if(str[i]=='F' && isValid(ix,iy) )
            {
                if(block[ix][iy] && !isValid(ix+dirx[id],iy+diry[id])) continue;
                ix+= dirx[id], iy+= diry[id];
            }
        }

        if(!isValid(ix,iy))
        {
            printf("%d %d %c LOST",ix-dirx[id],iy-diry[id],intToChar(id));
            block[ix-dirx[id]][iy-diry[id]] = 1;
        }

        else
        {
            printf("%d %d %c",ix,iy,intToChar(id));
        }
        nl;
    }
}
