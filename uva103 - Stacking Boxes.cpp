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

class box
{
public:
    int num,indx;
    int dim[10];
    box() {}
    box(int *ara,int n,int in)
    {
        num = n, indx = in;
        sort(ara,ara+n);
        for(int i=0; i<num; i++)
            dim[i]=ara[i];
    }

    bool operator<(const box &a)const
    {
        for(int i=0; i<num; i++)
        {
            if(dim[i]>=a.dim[i])
                return false;
            else if(dim[i]<a.dim[i])
                return true;

        }
        return true;
    }

    bool isLess(box a)
    {
        for(int i=0; i<num; i++)
        {
            if(dim[i]>=a.dim[i])
                return false;
        }
        return true;
    }

};


int main()
{
    int m,dim;
    while(cin>>m>>dim)
    {
        box stk[30+1];
        int stkSerial[30+1];
        int cnt[30+1];
        for(int i=1; i<=m; i++)
        {
            int ara[10];
            for(int j=0; j<dim; j++)
            {
                sf(ara[j]);
            }
            box tmp(ara,dim,i);
            stk[i] = tmp;
            stkSerial[i] = i;
            cnt[i] = 1;

        }
        sort(stk+1,stk+1+m);
        int mx=1;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<i; j++)
            {
                if(stk[j].isLess(stk[i]))
                {
                    if(cnt[i]<cnt[j]+1)
                    {
                        cnt[i]=cnt[j]+1;
                        stkSerial[i] = j;
                        if(cnt[mx]<cnt[i])
                            mx = i;
                    }
                }

            }
        }
        cout<<cnt[mx]<<endl;

        int i=mx;
        stack<int> show;
        show.push(stk[mx].indx);
        while(stkSerial[i]!=i)
        {
            i = stkSerial[i];
            show.push(stk[i].indx);

        }
        cout<<show.top();
        show.pop();
        while(!show.empty())
        {
            cout<<" "<<show.top();
            show.pop();

        }
        nl;
    }

}
