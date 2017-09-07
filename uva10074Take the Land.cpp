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

#define V 5
using namespace std;

int maxHistogram(int tmp[],int n)
{
    stack<int> s;
    int i=0,mx=-1;
    while(i<n)
    {
        if(s.empty() || tmp[i]>=tmp[s.top()])
            s.push(i++);
        else
        {
            int top=s.top();
            s.pop();
            int area= tmp[top] * (s.empty()? i : (i-1-s.top()));
            mx=max(mx,area);
        }
    }
    while(!s.empty())
    {
        int top=s.top();
        s.pop();
        int area= tmp[top] * (s.empty()? i : (i-1-s.top()));
        mx=max(mx,area);
    }
    return mx;
}
int largest_Submatrix(int ara[][100],int m,int n)
{

    int mxArea=-1,tmp[n];
    mst(tmp);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(ara[i][j]==1) tmp[j]=0;
            else tmp[j]+=1;
        }
        mxArea=max(mxArea,maxHistogram(tmp,n));
    }
    return mxArea;
}
int main()
{
    int m,n;
    while(scanf("%d %d",&m,&n)==2 && (m!=0 || n!=0))
    {
        int ara[100][100];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                sf(ara[i][j]);
        int max_Area_without_tree=largest_Submatrix(ara,m,n);
        printf("%d\n",max_Area_without_tree);
    }
}
