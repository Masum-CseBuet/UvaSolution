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
class box
{
public:
    int l,h,w,area;

    void make(int l,int w,int h)
    {
        this-> l=l,this->w=w, this->h=h, area=l*w;
    }
    bool operator<(const box& b)
    {
        return (l*w)>(b.l*b.w);
    }

};
int main()
{
    int num,kase=1;
    while(scanf("%d",&num) && num)
    {
        int l,h,w;
        box stack_h[num*3];
        for(int i=0; i<num*3; i++)
        {
            scanf("%d %d %d",&l,&w,&h);

            stack_h[i++].make(max(l,w),min(l,w),h);  // assuming that length is greater than width
            stack_h[i++].make(max(l,h),min(l,h),w);
            stack_h[i].make(max(h,w),min(h,w),l);
        }
        sort(stack_h,stack_h+num*3);
        int height[num*3];
        for(int i=0; i<num*3; i++)
        {
            height[i]=stack_h[i].h;

        }
        for(int i=1;i<num*3;i++)
        {
            for(int j=0;j<i;j++)
            {

                if(stack_h[i].l<stack_h[j].l && stack_h[i].w<stack_h[j].w)
                {
                    height[i]=max(stack_h[i].h+height[j],height[i]);
                }
            }
        }

        printf("Case %d: maximum height = %d\n",kase++,*max_element(height,height+num*3));

    }
}

