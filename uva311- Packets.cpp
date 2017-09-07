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

int main()
{

    int k =0;
    while(1)
    {
        k++;
        int ara[7];
        int chk = 0;
        for(int i=1; i<=6; i++)
        {
            sf(ara[i]);
            chk+=ara[i];
        }
        if(chk==0) return 0;

        int how[7];
        mst(how);
        for(int i=3; i<=6; i++)
        {
            int tmp = (6/i)*(6/i);
            how[i] = ceil(ara[i]*1.0/tmp);
        }

        int sp2 = how[4]*5,sp1= how[5]*11;  // sp1 = space for 1 X 1 square sp2 for 2 X 2 square ;
        if(ara[3]%4==1)
        {
            sp2 += 5, sp1 += 7;
        }
        else if(ara[3]%4==2)
        {
            sp2 += 3, sp1 += 6;
        }
        else if(ara[3]%4==3)
        {
            sp2 += 1, sp1 += 5;
        }
        {
            sp2>=ara[2]? (sp2-=ara[2], ara[2] = 0) : (ara[2]-= sp2, sp2 = 0);
            if(ara[2]>0)
            {
                how[2] = ceil(ara[2]/9.0);
                sp1 += ((9-ara[2]%9)%9 * 4);
            }
            sp1+= sp2*4;
            sp1>=ara[1]? sp1-=ara[1], ara[1] = 0 : ara[1]-= sp1, sp1 = 0;
            if(ara[1]>0)
            {
                how[1] = ceil(ara[1]/36.0);
            }

        }
        int sum = 0;
        for(int i=1; i<=6; i++)
            sum+= how[i];

        printf("%d\n",sum);

    }

}
