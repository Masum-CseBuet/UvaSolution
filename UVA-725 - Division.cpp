#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n)
#define nl printf("\n")
#define mst(n) memset(n,0,sizeof(n))

using namespace std;
bitset<10> chk;
bool chk_test(int num)
{
    bitset<10> tmp=chk; // making a temporary bitset so that original one is unaffected after testing
    while(num!=0)
    {
        if(tmp.test(num%10)) return 0;
        else   tmp.set(num%10,1), num/=10;
    }
    for(int i=1; i<=9; i++) if(!tmp.test(i)) return 0;  //checking if bitset from 1 to 9 is on // checking 0 is unnecessary
    return 1;
}
int N;
bool flag;
bool backTracking(int num,int taken)
{
    if(taken==5 && !(num%N) && chk_test(num/N))
    {
        printf("%d / %05d = %d\n",num,num/N,N);
        flag=true;
    }
    if(taken==5) return 0;
    for(int i=0; i<=9; i++)
    {

        if(taken==0 && i==0) i++;  //as the numerator can't have a leading zero bcz the quotient is greater than 1.. thus saving 10^4 test
        if(!chk.test(i))
        {
            chk.set(i);  // when taking a digit , we are setting that particular bit to one
            backTracking(num*10 + i,taken+1);
            chk.reset(i);
        }
    }
    return 0;

}
int main()
{

    bool nel=false;
    while(sf(N)==1)
    {
        flag=false;
        if(N==0)  return 0;
        if(nel) nl;  // for new line between two test case;
        nel=true;
        chk.reset();
        backTracking(0,0);
        if(!flag)
            printf("There are no solutions for %d.\n",N);

    }
}
