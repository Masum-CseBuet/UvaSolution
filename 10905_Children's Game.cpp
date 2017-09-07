#include<bits/stdc++.h>
#define pb(n) push_back(n)
#define bug cout<<"bug";
#define all(c) c.begin(),c.end()
#define fr(i,n) for(i=0;i<n;i++)
#define sf(n) scanf("%d",&n)
#define mp(i,j) make_pair(i,j)
#define mst(n) memset(n,-1,sizeof(n))
#define nl printf("\n")
#define lli long long int
#define tr(container,it) \
    for (auto it = container.begin(); it != container.end() ; ++it)

#define INF INT_MAX
#define MOD 1000000007

#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

using namespace std;

bool cmp(const string &str1,const string &str2)
{
    string tmp=str1+str2;
    string tmp2=str2+str1;
    return tmp>tmp2;

}
int main()
{

    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) return 0;
        char st[50];
        vector<string> store;
        while(n--)
        {
            scanf("%s",st);
            store.push_back(st);
        }
        sort(store.begin(),store.end(),cmp);
        for(auto &a:store)
        {
            cout<<a;

        }
        printf("\n");

    }


}
