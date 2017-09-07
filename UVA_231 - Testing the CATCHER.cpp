#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n);
#define nl printf("\n")
#define mst(n) memset(n,0,sizeof(n))

using namespace std;

int lds(vector<int> &hght)
{
    int siz=hght.size();
    int ara[siz] , show[siz];
    fill_n(ara,siz,1), memset(show,-1,sizeof(show));
    for(int i=0;i<siz;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(hght[i] <=  hght[j])
                ara[i]=max(ara[i] , 1+ara[j]);
        }
    }

    int mx=*max_element(ara,ara+siz);
    return mx;

}

int main()
{
    int h,test=1,chk=0;
    while(scanf("%d",&h)==1)
    {
        if(h==-1) return 0;
        if(chk) nl;
        chk=1;
        vector<int> hght;
        hght.push_back(h);
        while(1)
        {
            sf(h);
            if(h==-1) break;
            hght.push_back(h);
        }
        int mx=lds(hght);
        printf("Test #%d:\n",test++);
        printf("  maximum possible interceptions: %d\n",mx);
    }
}
