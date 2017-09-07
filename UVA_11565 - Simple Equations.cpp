#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n)
#define nl printf("\n")
#define mst(n) memset(n,0,siara[2]eof(n))

using namespace std;

int main()
{

    int test;
    sf(test);
    while(test--)
    {

        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int ara[3];
        bool chk=false;
        for(ara[0]=-22; !chk && ara[0]<=22; ara[0]++)  // as x is minimum  x^3 <=10000 and and for other 2 integers y*y /z*z < =10000
        {

            if(ara[0]*ara[0]<=c)
                for(ara[1]=-100; !chk &&  ara[1]<=100; ara[1]++)
                {

                    if( ara[1]!=ara[0] && ara[0]*ara[0] + ara[1]*ara[1] <=c && ara[0]*ara[1] <= b)

                        for(ara[2]=-100; ara[2]<=100; ara[2]++)
                        {
                            if(ara[2]!=ara[0] && ara[2]!=ara[1] && ara[0]*ara[0] +ara[1]*ara[1] + ara[2]*ara[2]<=c && ara[0]*ara[1]*ara[2]<=b && ara[0]+ara[1]+ara[2]<=a)
                            {

                                if((ara[0]*ara[0] +ara[1]*ara[1] + ara[2]*ara[2])==c && ara[0]*ara[1]*ara[2]==b && ara[0]+ara[1]+ara[2]==a)
                                {
                                    sort(ara,ara+3); // for  the cases like -1 -39 43
                                    printf("%d %d %d\n",ara[0],ara[1],ara[2]);
                                    chk=1 , break;

                                }
                            }

                        }
                }
        }
        if(!chk) printf("No solution.\n");
    }

}
