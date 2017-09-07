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
    int val[4];
    int steps;
    node(int *val,int steps)
    {
        for(int i=0; i<4; i++)
        {
            this->val[i] = val[i];
        }
        this->steps = steps;
    }
};

inline int arrayToNumber(int *ara)
{
    return ara[0]*1000+ara[1]*100+ara[2]*10+ara[3];
}
bool numberIsOk(int num,vector<int> &forbidden)
{
    return !binary_search(all(forbidden),num);
}
int mod(int n,int m)  // to avoid negative in modular operation
{
    int ret = n%m;
    if(ret<0) ret = ret+m;
    return ret;
}
int bfs(int *from,int dest,vector<int> &forbidden)
{
    if(arrayToNumber(from)==dest) return 0;
    bool vis[10000];
    mst(vis);
    node src(from,0);
    queue<node> q;
    q.push(src);
    vis[arrayToNumber(from)] = true;
    while(!q.empty())
    {
        node top = q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<=1; j++) // we are both increasing and decreasing each value of array by 1
            {
                top.val[i] = mod((top.val[i] + (int)pow(-1,j)),10);
                int num = arrayToNumber(top.val);
                if(num==dest) return top.steps+1;
                if(numberIsOk(num,forbidden) &&!vis[num])
                {
                    node tmp(top.val,top.steps+1);
                    q.push(tmp);
                    vis[num] = true;
                }
                top.val[i] = mod((top.val[i] - (int)pow(-1,j)),10); // getting back to original position
            }

        }
    }
    return -1;

}
int main()
{
    int test;
    sf(test);
    int kase = 1;
    while(test--)
    {
        int src[4],dest[4];

        for(int j=0; j<4; j++)
            sf(src[j]);
        for(int j=0; j<4; j++)
            sf(dest[j]);
        int num;
        sf(num);
        vector<int> forbidden(num);

        for(int i=0; i<num; i++)
        {
            int tmp[4];
            for(int j=0; j<4; j++)
            {
                sf(tmp[j]);
            }
            int n = arrayToNumber(tmp);
            forbidden.push_back(n);
        }
        sort(all(forbidden)); // as too many searches will be performed,
                              //we will chose built in  binary search .That's why we have sorted the vector
        int res = bfs(src,arrayToNumber(dest),forbidden);
        cout<<res<<endl;
    }

}
