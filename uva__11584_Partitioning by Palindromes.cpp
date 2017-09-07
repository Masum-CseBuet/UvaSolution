#include<bits/stdc++.h>
#define pb(n) push_back(n)
#define bug cout<<"bug";
#define all(c) c.begin(),c.end()
#define fr(i,n) for(i=0;i<n;i++)
#define sf(n) scanf("%d",&n)
#define mp(i,j) make_pair(i,j)
#define mst(n) memset(n,-1,sizeof(n))
#define nl printf("\n")
#define lli long long int
#define tr(container,it) \
    for (auto it = container.begin(); it != container.end() ; ++it)

#define INF INT_MAX
#define MOD 1000000007

#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

using namespace std;
inline bool isPallindrome(char ara[],int len)
{
    //for(int i=0;i<len;i++)cout<<ara[i];
    //nl;
    for(int i=0,j=len-1; i<j; i++,j--)
        if(ara[i]!=ara[j]) return 0;
    return 1;
}

int main()
{
    infile;
    outfile;
    int test;
    sf(test);
    while(test--)
    {
        char str[1000+5];
        scanf("%s",str);
        int len=strlen(str);
        int ara[len+1];
        bool pall[len+1][len+1];
        mst(ara), mst(pall);
        for(int i=0;i<len;i++)
            pall[i][i]=1;
        for(int i=2; i<=len; i++)
        {

            for(int j=0; j+i-1<len; j++)
            {
                int start=j, upto=j+i-1;
                if(i==2)
                {
                    if(str[start]==str[upto])
                    {
                        pall[start][upto]=1;
                        //cout<<start<<"  "<<upto<<endl;
                    }
                    else pall[start][upto]=0;
                }
                else
                {
                    if(str[start]==str[upto])
                    {
                        pall[start][upto]=pall[start+1][upto-1];
                       // cout<<start<<"  "<<upto<<endl;
                    }
                    else pall[start][j+i-1]=0;
                }

            }
        }
        for(int i=0; i<len; i++)
        {
            if(pall[0][i]==1) ara[i]=0;
            else
            {
                ara[i]=INT_MAX;
                for(int j=0; j<i; j++)
                {
                    if(pall[j+1][i]==1)
                    {
                        ara[i]=min(ara[i],1+ara[j]);
                    }
                }
            }
        }
       // for(auto a:ara) cout<<a<<"  ";
        printf("%d\n",ara[len-1]+1);

    }



}


/*outfile;
int n,s,r,c=1,g=1,v;
int ara[5]={0,50,43,66,62};
for(int i=1;i<=60;i++)
{
    printf("Roll:%d\n",i);
    for(int j=1;j<=4;j++)
    {
        n=(2*c+3*j+i) % ara[j] +1;
        v=(3*c+5*j+i) % 60 + 60*g;
        printf("Exercise:1.%d--Problem no=%d  Verifier Id:%d\n",j,n,v);
    }
    cout<<endl;
}
}*/
