#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n);
#define nl printf("\n")
#define mst(n) memset(n,0,sizeof(n))



using namespace std;
int checkLeapYear(long long a)
{
    if((!(a%4) && a%100) || !(a%400) )    return 1;
    return 0;
}
int main()
{
    int  line,i;
    scanf("%d",&line);
    getchar();
    for(i=1; i<=line; i++)
    {
        char ara1[20],ara2[20];
        long long int year1,year2,j,result=0;
        int month1,month2;
        scanf("%s",&ara1);
        scanf("%d,%lld",&month1,&year1);
        scanf("%s",&ara2);
        scanf("%d,%lld",&month2,&year2);

        for(j=year1; j<=year2; j++)
        {
            if(checkLeapYear(j))
            {
                result=(year2-j)/4+1;
                if((year2-j)>=100)
                {
                    result-=(year2-(j/100)*100)/100; // excluding year that is a multiple of 100
                                                     // i.e 2006 - 1992   then 1996 is the first  leap year .. 1996 /100*100 = 1900
                                                     // (2006-1900 )/100 = 1 this 1 is being subtracted
                }
                if((year2-j)>=400)
                {
                    result+=(year2-(j/400)*400)/400;  //  multiple of 400  is being added
                }
                break;

            }
        }

        if(checkLeapYear(year1))
        {
            if (strcmp(ara1,"January") && strcmp(ara1,"February"))//if  year1-month is after  feb 29 it shouldn't include leap day
                result--;

        }
        if(checkLeapYear(year2))
        {
            if (!strcmp(ara2,"January" )||(!strcmp(ara2,"February") && month2!=29))//if  year2-month is before feb 29 it shouldn't include leap day
                result--;

        }

        printf("Case %d: %lld\n",i,result);
    }
}


