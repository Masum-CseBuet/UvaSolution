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
#define sz 1005
#define MOD 100000007
using namespace std;
struct matrix
{
    int row,col;
    matrix(int r,int c):row(r),col(c) {}
    matrix() {}
};
matrix ara[10];
int dp[11][11];
int divider[11][11];
int matrixChainMultiplication(int strt,int lst)
{
    if(strt==lst)
    {
        divider[strt][lst] = strt;
        return dp[strt][lst] = 0;
    }
    if(dp[strt][lst]!=-1) return dp[strt][lst];
    int mn = INF;
    for(int i=strt; i<lst; i++)
    {
        int lcost = matrixChainMultiplication(strt,i);
        int rcost = matrixChainMultiplication(i+1,lst);
        if(mn > lcost+rcost + ara[strt].row * ara[i].col * ara[lst].col )
        {
            mn = lcost+rcost + ara[strt].row * ara[i].col * ara[lst].col;
            divider[strt][lst] = i;
        }

    }
    return dp[strt][lst] = mn;
}
int print(int strt,int lst,int opb,int clb)
{

    if(strt==lst)
    {
        for(int i=0; i<opb; i++) cout<<"(";
        cout<<"A"<<strt+1;
        for(int i=0; i<clb; i++) cout<<")";
        return 0;
    }
    print(strt,divider[strt][lst],opb+1,0);
    cout<<" x ";
    print(divider[strt][lst]+1,lst,0,clb+1);

}
int main()
{
    int num,i=0,kase=1;
    while(sf(num) && num)
    {
        int r,c,i=0;
        mstn(dp), mst(divider);
        for(int i=0; i<num; i++)
        {
            scanf("%d %d",&r,&c);
            matrix tmp(r,c);
            ara[i]  = tmp;
        }
        matrixChainMultiplication(0,num-1);
        printf("Case %d: ",kase++);
        print(0,num-1,0,0);

        nl;
    }
}
