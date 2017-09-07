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
typedef pair<int,int> pi;
int chk[(INT_MAX>>5)+1];
vector<int> primary;
vector<int> prime;
bool check(int num,int pos)
{
    return (bool)(num & (1<<pos));
}
int setp(int num,int pos)
{
    return (num= num | 1<<pos);
}
void primeGenerator()
{
    int x=sqrt(INT_MAX);
    primary.pb(2);
    for(int i=3; i<=x+1; i+=2)
    {
        if(check(chk[i>>5],i&31)==0)
        {
            primary.pb(i);
            for(int j=i*i; j<=x+1; j+=2*i)
            {
                chk[j>>5]=setp(chk[j>>5],j&31);  // for segment seive it is sufficient to generate primes below sqrt(upper value) bcz then
                // we will mark the multiples of these primes in the particular interval
            }

        }
    }

}
void segment_seive(int a,int b)
{
    lli st;
    for(lli i=1; i<primary.size() && (primary[i]*primary[i]<=b); i++)
    {
        st=((a/primary[i])%2==0)? max(3,a/primary[i]-1):max(3,a/primary[i]);  // checking if it is even ,if it is then we will make it odd so that
        //we can increase it by 2
        for(lli j=st; j*primary[i]<=b; j+=2)
        {
            int num=j*primary[i];
            chk[num>>5]=setp(chk[num>>5],num&31);  //marking all multiple of prime
        }

    }

    int tmp=(a%2)?max(3,a):a+1;  // we will start marking at least from 3
    if(a<=2) prime.pb(2);
    for(lli i=tmp; i<=b; i+=2)
    {
        if(check(chk[i>>5],i&31)==0)
        {
            prime.pb(i);
        }

    }
}
int main()
{

    int a,b;
    primeGenerator();
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        prime.clear();
        segment_seive(a,b);
        int mn=INT_MAX,mx=-1;
        pi tmp1,tmp2;
        if(prime.size()<2) printf("There are no adjacent primes.\n");
        else
        {
            for(int i=1; i<prime.size(); i++)
            {
                if((prime[i]-prime[i-1])<mn)
                {
                    mn=prime[i]-prime[i-1],tmp1=mp(prime[i-1],prime[i]);
                }
                if((prime[i]-prime[i-1])>mx)
                {
                    mx=prime[i]-prime[i-1],tmp2=mp(prime[i-1],prime[i]);
                }

            }
            printf("%d,%d are closest, %d,%d are most distant.\n",tmp1.first,tmp1.second,tmp2.first,tmp2.second);
        }
    }

}
