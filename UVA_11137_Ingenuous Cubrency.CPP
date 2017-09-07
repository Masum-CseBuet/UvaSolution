#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n);
#define nl printf("\n")
#define mst(n) memset(n,0,sizeof(n))

using namespace std;

int coinChange(lli ara[][10000+5],int coin[])
{
    lli i,j;
    for( i=1; coin[i]<=9999; i++)
    {
        for( j=1; j<=9999; j++)
        {
            if(j<coin[i])
                ara[i][j]=ara[i-1][j];
            else
                ara[i][j]=ara[i-1][j]+ara[i][j-coin[i]];

        }
    }
}

int main()
{
    int money,i;
    int coin[24];
    lli ara[22][10000+5];
    for( i=1; i<=22; i++)  coin[i]=i*i*i;
    memset(ara,0,sizeof(ara));

    for(i=0; i<22; i++) ara[i][0]=1;

    coinChange(ara,coin);

    while(scanf("%d",&money)==1)
    {
        i=1;
        while(coin[i]<=money) i++;
        printf("%lld\n",ara[i-1][money]);
    }
}
