#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n);
#define nl printf("\n")
#define mst(n) memset(n,0,sizeof(n))

// a pretty straightforward backtracking problem
//all we need to do is to check all possible outcome and then get the minimum of those

using namespace std;
int mn;
bool ara[15];
int backTracking(bool ara[])
{
    bool chk=false;
    for(int i=0;i<12;i++)
    {
        if( i<10 && ara[i]==1 && ara[i+1]==1 && ara[i+2]==0) // checking if we can get a move in right side
        {
            ara[i]=0  , ara[i+1]=0  ,ara[i+2]=1;
            int tmp =backTracking(ara);
            mn= (mn<tmp) ? mn : tmp;
            ara[i]=1  , ara[i+1]=1  ,ara[i+2]=0;
            chk=1;
        }
        if(i>=2 && ara[i]==1 && ara[i-1]==1 && ara[i-2]==0) // checking if we can get a move in left  side
        {
            ara[i]=0  , ara[i-1]=0  ,ara[i-2]=1;
            int tmp=backTracking(ara);
            mn= (mn<tmp) ? mn : tmp;
            ara[i]=1  , ara[i-1]=1  ,ara[i-2]=0;
            chk=1;
        }
    }
    if(chk==false)  // when no move is possible ..this is the base/return case
    {
        int tmp=0;
        for(int i=0;i<12;i++)
            if(ara[i]==1) tmp++;
        return tmp;
    }
    return mn;
}

int main()
{
    int test;
    sf(test);
    getchar();
    while(test--)
    {
        mn=INT_MAX;
        for(int i=0;i<12;i++)
        {
            char ch=getchar();
            if(ch=='-') ara[i]=0;
            else ara[i]=1;
        }
        getchar();
        mn=backTracking(ara);
        printf("%d\n",mn);
    }

}


