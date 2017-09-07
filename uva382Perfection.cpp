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
#define pi acos(-1.0)
using namespace std;

int main()
{
    printf("PERFECTION OUTPUT\n");
    int num;
    while(sf(num) && num)
    {
        int sum=1;
        if(num==1) {printf("%5d  DEFICIENT\n",num) ; continue;}
        for(int i=2;i*i<=num;i++)
        {
            if(num%i==0)
            {
                sum=sum+((i*i)==num?i:(num/i+i));
            }
        }
        if(sum>num) printf("%5d  ABUNDANT",num);
        else if(sum<num) printf("%5d  DEFICIENT",num);
        else printf("%5d  PERFECT",num);
        nl;
    }
    printf("END OF OUTPUT\n");


}
