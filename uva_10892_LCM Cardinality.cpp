#include<bits/stdc++.h>
#define pb(n) push_back(n)
#define bug cout<<"bug";
#define all(c) c.begin(),c.end()
#define fr(i,n) for(i=0;i<n;i++)
#define sf(n) scanf("%d",&n)
#define mp(i,j) make_pair(i,j)
#define mst(n) memset(n,0,sizeof(n))
#define nl printf("\n")
#define lli long long int
#define tr(container,it) \
    for (auto it = container.begin(); it != container.end() ; ++it)

#define INF INT_MAX
#define MOD 1000000007

#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

using namespace std;
typedef pair<int,int> pi;
vector<lli> primeStore;
int prime[(44725)>>5];
bool check(int num,int pos)
{
    return (bool)(num & 1<<pos);
}
int setp(int num,int pos)
{
    return (num= num | 1<<pos);
}
void primeGenerator()
{
    mst(prime);
    lli x=sqrt(2*1e9);
    primeStore.pb(2);


    for(lli i=3; i<=x; i+=2)
    {
        if(check(prime[i>>5],i&31)==0)
        {
            primeStore.pb(i);


            for(lli j=i*i; j<=x; j+=2*i)
            {

                prime[j>>5]=setp(prime[j>>5],j&31);
            }

        }
    }
}
lli factorise(lli num)
{
    lli tmp=num;
    vector<pi> factor;
    vector<lli> store;
    int i=0,how=0;
    while(num!=1 && (i<primeStore.size()))
    {
        int cnt=0;
        while(num%primeStore[i]==0)
        {
            num/=primeStore[i];
            cnt++;

        }
        i++;
        if(cnt) factor.push_back(mp(primeStore[i-1],cnt));
    }

    if(num!=1) factor.push_back(mp(num,1));
    int cnt=0;
    lli mul=1;
    for(int i=1; i*i<=tmp; (tmp&1)?i+=2 : i++)
    {
        if(tmp%i==0)
        {
            lli a=tmp/i ;
            if(a!=i) store.pb(i);
            store.pb(a);
        }
    }
    //finding all possible pair
    for(int i=0; i<store.size(); i++)
    {
        if(store[i]!=tmp)
            for(int j=i+1; j<store.size(); j++)
            {
                if(store[j]!=tmp)
                {
                    if((store[i]*store[j]/__gcd(store[i],store[j]))==tmp)
                           cnt++;

                }
            }

    }
    for(int i=0;i<factor.size();i++)
    {
        mul*=(factor[i].second+1);
    }
    return (cnt+mul);


}
int main()
{

    primeGenerator();

    while(1)
    {
        lli num;

        scanf("%lld",&num);
        if(num==0) return 0;
        if(num==1)
        {
            printf("1 1\n");
            continue;
        }
        lli ans=factorise(num);
        printf("%lld %lld\n",num,ans);
    }

}
