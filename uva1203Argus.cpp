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
using namespace std;

struct node
{
    int num,tme,period;
    node(int n,int t,int p)
    {
        num = n, tme = t, period = p;
    }
    bool operator<(const node &a)const
    {
        if(a.tme==tme) return num>a.num;
        return tme>a.tme;
    }
};

int main()
{
    char str[100];
    int qn[3000],period[3000],q,i;
    for(i=0;; i++)
    {
        scanf("%s",str);
        if(strcmp(str,"#")==0) break;
        scanf("%d %d",&qn[i],&period[i]);

    }
    sf(q);
    int num = i;
    priority_queue<node,vector<node> > pq;
    for(i=0; i<num; i++)
    {
        pq.push(node(qn[i],period[i],period[i]));
    }

    while(q--)
    {
        node top = pq.top();
        pq.pop();
        cout<<top.num<<endl;
        pq.push(node(top.num,top.tme+top.period,top.period));

    }

}


