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
#define mx 100005
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

using namespace std;
//a program to find the rectangle with maximum sum from a matrix
// following code also finds out the rectangle (though the uva problem only asks for the sum)\

typedef struct one_d_array_sum // this struct will be used to calculate the maximum sum of 1d array using kadane's algorithm
{
    int sum,up,down;
    one_d_array_sum()
    {
        up=0,down=0;
    }
} one_d;
int n;

one_d kadane(int ara[],int n)
{
    one_d a;
    int cur_sum=ara[0];
    a.sum=ara[0];
    int l=0,r=0;

    for(int i=1; i<n; i++)
    {
        if(ara[i]>=ara[i]+cur_sum)
        {
            cur_sum=ara[i],  l=r=i;

        }
        else
        {
            cur_sum=ara[i]+cur_sum,  r=i;
        }
        if(a.sum<=cur_sum)
        {
            a.up=l,a.down=r, a.sum=cur_sum;
        }
    }
    return a;
}
int maximal_sub_rectangle(vector<vector<int>>& ara)
{
    int tmp[n];

    int ctop=0,cdown=0,cleft=0,cright=0;  // c for current and g for global
    int gtop=0,gdown=0,gleft=0,gright=0;
    int cur_sum=-INF,global_sum=-INF;
    for(int i=0; i<n; i++)
    {
        mst(tmp);
        for(int j=i; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                tmp[k]+=ara[k][j];

            }
            one_d a=kadane(tmp,n);  // finding the sum of 1d array that has been formed by adding column elements

            if(cur_sum<a.sum)
            {
                cur_sum=a.sum, ctop=a.up, cdown=a.down ;
            }
            if(global_sum<cur_sum)
            {

                global_sum=cur_sum, gtop=ctop, gdown=cdown,gleft=i,gright=j;

            }

        }
    }
    //cout<<global_sum<<"  "<<gtop<<"  "<<gdown<<"  "<<gleft
    // <<"  "<<gright<<endl;
    printf("%d\n",global_sum);


}
int main()
{

    sf(n);
    {
        vector<vector<int>> ara(n,vector<int> (n));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int num;
                sf(num);
                ara[i][j]=num;

            }

        }
        maximal_sub_rectangle(ara);
    }

}
