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
#define pi acos(-1.0)
using namespace std;


int main()
{
    map<int,int> imap;
    int kase=1;
    int i,m,z,l;
    while(scanf("%d %d %d %d",&z,&i,&m,&l) && ( i || z || m || l))
    {
        int cnt=0,cycle_len;
        while(1)
        {
            int num=( z * l + i ) % m;
            if(imap.find(num)==imap.end())
            {
                imap[num]=cnt++;
            }
            else
            {
                cycle_len=(cnt-imap[num]);
                break;
            }
            l =  num;
        }
        printf("Case %d: %d\n",kase++,cycle_len);
        imap.clear();

    }

}
