
#include<bits/stdc++.h>
using namespace std;
vector<int> coin;
long long int dp(int change)
{
    int i,j;
    vector<vector<long long int>> ara;
    ara.resize(6,vector<long long int>(change+1,1));
    ara[0].assign(change+1,0);


    for(i=1; i<=5; i++)
    {
        for(j=1; j<=change; j++)
        {
            if(j<coin[i-1])
                ara[i][j]=ara[i-1][j];
            else
                ara[i][j]=ara[i-1][j]+ara[i][j-coin[i-1]];

        }
    }
    /*for(i=1; i<=5; i++)
    {
        for(j=0; j<=change; j++)
        {
            cout<<ara[i][j]<<"  ";
        }
        cout<<endl;
    }*/
    return ara[5][change];
}

int main()
{
    long long int i,j,change;
    int ara[]= {1,5,10,25,50};
    coin.assign(ara,ara+5);
    int test;

    while (1==scanf("%d",&change))
    {
        long long int n=dp(change);
        if(n>1)
            printf("There are %lld ways to produce %d cents change.\n",n,change);
        else
        {
            printf("There is only 1 way to produce %d cents change.\n",change);
        }
    }


    //return main();


}
