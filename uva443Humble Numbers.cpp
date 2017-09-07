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


void getHumbleNumber(int *humble)
{
    humble[1]=1;
    int mul2=1,mul3=1,mul5=1,mul7=1;
    int w,x,y,z;

    for(int i=2; i<=5842; i++)
    {
        w = humble[mul2] * 2;
        x = humble[mul3] * 3;
        y = humble[mul5] * 5;
        z = humble[mul7] * 7;
        // cout<<w<<x<<y<<z<<endl;
        humble[i] = min(min(x,y),min(w,z)); // no special order

        if(humble[i]==w) mul2++;
        if(humble[i]==x) mul3++;
        if(humble[i]==y) mul5++;
        if(humble[i]==z) mul7++;
        // cout<<humble[i]<<endl;

    }

}









int main()
{
    infile;
    outfile;
    int humble[6000];
    getHumbleNumber(humble);
    int num;
    while(sf(num) && num)
    {
        if((num/10)%10==1)
        {
            printf("The %dth humble number is %d.\n",num,humble[num]);
            continue;

        }

        switch(num%10)
        {

        case 1:
            printf("The %dst humble number is %d.",num,humble[num]);
            break;
        case 2:
            printf("The %dnd humble number is %d.",num,humble[num]);
            break;
        case 3:
            printf("The %drd humble number is %d.",num,humble[num]);
            break;
        default:
            printf("The %dth humble number is %d.",num,humble[num]);
            break;
        }
        nl;
    }
}






