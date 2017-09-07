#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n);
#define nl printf("\n")
#define mst(n) memset(n,0,sizeof(n))

// a straight-forward backtracking problem , checking all possible combination that meets the requirement

using namespace std;
vector<int> show;
bool vis[10000];
int prime[13]= {1,2,3,5,7,11,13,17,19,23,29,31,37}; //as input range is small , all the prime numbers have been taken in array
int backTrack(int num)
{
    if(find(prime,prime+13,show.rbegin()[1]+show.back())==prime+13)  // checking if sum of  2 consecutive numbers is prime
        {
            return 0;
        }
    if(show.size()==num+1)
    {
        if(find(prime,prime+13,show.back()+1)==prime+13) return 0;  //as this is a circle so the last element is a neighbor  element of the first element (1) ,,so primality test of sum is done here
        for(int j=1; j<=num; j++)
           {
               printf("%d",show[j]);
                if(j!=num)
                    printf(" ");
           }

        nl;
        return 0;
    }


    for(int i=2; i<=num; i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            show.push_back(i);
            backTrack(num);
            vis[i]=0,  show.pop_back();
        }
    }
}

int main()
{
    int i=1;
    int n;
    while(scanf("%d",&n)==1)
    {
        if(i>1) nl;
        show.push_back(0);
        show.push_back(1);

        printf("Case %d:\n",i++);
        backTrack(n);
        show.clear(),mst(vis);

    }
}
