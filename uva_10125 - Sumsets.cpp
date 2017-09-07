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
#define MOD 1000000007
#define mp(i,j) make_pair(i,j)
#define mstn(n) memset(n,-1,sizeof(n))
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)
#define pr(a) cout<<cout<<a.a.first<<"  "<< a.a.second<<endl
#define V 5
using namespace std;
typedef pair<int,int> pi;
vector<pair<int,pi>> from,to;
inline bool issUnique(pair<int,pi> fr,pair<int,pi> t)
{
    set<int> chk;
    chk.insert((fr.second).first), chk.insert((fr.second).second),chk.insert((t.second).first),chk.insert((t.second).second);
    if(chk.size()==4) return 1;
    return 0;
}
inline int bin_search(int low,int high,int num,int i)
{
    if(low>high) return 0;
    int mid=(low+high)/2;

    if(num==(to[mid].first))
    {

        if(issUnique(to[mid],from[i]))
        {
            return mid;
        }
    }

    if(num<to[mid].first) bin_search(low,mid-1,num,i);
    else if(num>to[mid].first) bin_search(mid+1,high,num,i);

}
bool cmp(pair<int,pi> a,pair<int,pi> b)
{
    if(a.first==b.first)
    {
        return a.second.second<b.second.second;
    }
    return a.first<b.first;
}
int main()
{

    int num;
    while(1)
    {
        scanf("%d",&num);
        if(num==0) return 0;
        int ara[num];
        int ans=-536870911;
        for(int i=0; i<num; i++)
            sf(ara[i]);
        from.clear(), to.clear();
        sort(ara,ara+num);
        for(int i=0,k=num-1; i<num-1; i++,k--)
        {
            for(int j=i+1,l=k-1; j<num; l--, j++)
            {
                from.push_back(make_pair(ara[i]+ara[j],mp(ara[i],ara[j])));
                to.push_back(make_pair(ara[k]-ara[l],mp(ara[k],ara[l])));
            }
        }
        sort(to.begin(),to.end(),cmp);

        for(int i=0; i<from.size(); i++)
        {
            if(from[i].first>to[to.size()-1].first) break;


            int ret,tmp;
            if( (ret=bin_search(0,to.size()-1,from[i].first,i))!=0)
            {
                tmp=ret;
                if(ans<to[tmp].first+to[tmp].second.second)
                {
                    ans=to[tmp].first+to[tmp].second.second;

                }

            }
        }
        if(ans==-536870911) printf("no solution\n");
        else
            printf("%d\n",ans);

    }

}

