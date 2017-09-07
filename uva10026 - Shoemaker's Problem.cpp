#include<bits/stdc++.h>
#include <functional>
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
#define MOD 1000000007
using namespace std;
struct job{
    int day,fine,idx;
    job(int d,int f,int i)
    {
        day = d, fine = f, idx = i;
    }
    job(){}
    bool operator<(job a)
    {
        int f1 = (a.day*fine);
        int f2 = (a.fine*day);
        if(f1==f2) return idx<a.idx;
        return f1>f2;
    }
};
int main()
{
    int test;
    sf(test);
    bool nel = 0;
    while(test--)
    {
        if(nel) nl;
        nel = 1;
        int task;
        sf(task);
        vector<job> lst;
        for(int i=1;i<=task;i++)
        {
            job a;
            a.idx = i;
            cin>>a.day>>a.fine;
            lst.push_back(a);
        }
        sort(all(lst));
        cout<<lst[0].idx;
        for(int i=1;i<task;i++)
        {
            cout<<" "<<lst[i].idx;
        }
        nl;
    }
}
