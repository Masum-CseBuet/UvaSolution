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
typedef pair<int,int> pi;

int maxHistogram(int tmp[],int n)
{
    stack<int> s;
    int i=0,mx=-1;
    while(i<n)
    {
        if(s.empty() || tmp[i]>=tmp[s.top()])
        {
            s.push(i++);
        }
        else
        {
            int top=s.top();
            s.pop();
            int area=tmp[top] * (s.empty() ? i : (i-s.top()-1));
            mx=max(mx,area);
        }
    }
    while(!s.empty())
    {
        int top=s.top();
        s.pop();
        int area=tmp[top] * (s.empty() ? i : (i-s.top()-1));
        mx=max(mx,area);
    }
    return mx;
}
int largest_Submatrix(bool ara[][26],int row,int col)
{
    int tmp[col];
    mst(tmp);
    int mxArea=-1;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(ara[i][j]==0) tmp[j]=0;
            else tmp[j]+=1;
        }

        mxArea=max(mxArea,maxHistogram(tmp,col));
    }
    return mxArea;
}
int main()
{
    int test;
    bool nel=0;
    scanf("%d",&test);
    getchar();
    while(test--)
    {
        getchar();
        if(nel) nl;
        nel=1;
        bool ara[26][26];
        int row=0,i,col;
        while(1)
        {

            char str[30];
            gets(str);
            int len=strlen(str);
            for(i=0; i<len; i++)
            {
                if(str[i]=='0') ara[row][i]=0;
                else ara[row][i]=1;
            }
            col=i;
            row++;
            if(row==col) break;
        }
        int mxArea=largest_Submatrix(ara,row,col);
        printf("%d\n",mxArea);

    }
}
