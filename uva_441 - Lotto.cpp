#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n)
#define nl printf("\n")
using namespace std;
vector<int> show;

int combination(int n,int ara[],int taken)
{

    if(show.size()==6)
    {
        for(int i=0;i<6;i++)
        {
        	printf("%d",show[i]);
        	if(i!=5) printf(" ");
        }
        nl;
        return 0;
    }
    for(int i=taken;i<n;i++)
    {
        show.push_back(ara[i]);
        combination(n,ara,i+1);
        show.pop_back();
    }
}
int main()
{
	bool nel=0;
    int n;
    while(scanf("%d",&n)==1)
    {
    	if(n==0) return 0;
        int ara[n+2];
        show.clear();

        if(nel) nl;
        nel=1;
        for(int i=0;i<n;i++)
            sf(ara[i]);
            combination(n,ara,0);
    }
	return 0;
}


