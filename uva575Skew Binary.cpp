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
#define mstn(n) memset(n,-1,szeof(n))
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)
#define ull unsigned long long
#define V 1000001
#define sz 1005
#define mod 1000000007
using namespace std;

int main()
{
    int y;

    string str;
    while(getline(cin,str))
    {
        if(str=="0") break
        long long sum=0;
        int val=2;
        reverse(str.begin(),str.end());
        int siz = str.size();
        for(int i=0; i<siz; i++)
        {
            switch(str[i])
            {
            case '1' :
                sum+=(val-1);
                break;
            case '2' :
                sum+=(2*(val-1));
                break;
            }
            val*=2;
        }
        cout<<sum<<endl;
    }



}

