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

struct line
{
    int st,lst,len;
    line(int s,int l)
    {
        st = s, lst = l, len = l-s;
    }

};

bool cmp(line a,line b)
{
    if(a.st==b.st) return a.lst>b.lst;
    return a.st<b.st;
}

void print(stack<line> &st)
{
    if(st.empty()) return;
    line a = st.top();
    st.pop();
    print(st);
    printf("%d %d\n",a.st,a.lst);
}

int main()
{
    int test;
    sf(test);
    bool nel = 0;
    while(test--)
    {
        int rng;
        if(nel) nl;
        nel = 1;
        sf(rng);
        vector<line> lines;
        while(1)
        {
            int s,l;
            scanf("%d %d",&s,&l);
            if(s==0 && l==0) break;
            if(l<0 || s>rng) continue;
            lines.push_back(line(s,l));
        }

        sort(lines.begin(),lines.end(),cmp);
        int l=0,r=0;  // l = left , r = right // l & r indicates the range that's been "effectively"(that is no overlapping with previous ones)  covered by the newly picked segment
        stack<line> stk;

        for(int i=0; i<lines.size(); i++)
        {

            if(lines[i].st<=l && lines[i].lst>r ) // if current segment is better than the previous one , that is cover more area
            {
                if(!stk.empty())
                {
                    stk.pop();
                }
                if(!stk.empty()) l = stk.top().lst;
                stk.push(lines[i]);
                r = lines[i].lst;
            }
            else if(lines[i].st<=r && lines[i].lst>r) /
            {

                l = r;
                stk.push(lines[i]);
                r = lines[i].lst;
            }
            if(r>=rng) break;
        }
        if(stk.size()==0 || r<rng) cout<<0<<endl;
        else
        {
            cout<<stk.size()<<endl;
            print(stk);
        }

    }
}

