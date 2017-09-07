#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n);
#include<stdlib.h>


using namespace std;

//uva  637
int main()
{
    int page;
    while(1)
    {
        scanf("%d",&page);
        if(page==0)
        {
            break;
        }

        int first=1,i=0,total;

        total=(int)ceil(page/4.0);
        //printf("%d",total);
        int last=total*4;
        printf("Printing order for %d pages:\n",page);
        for(i=1; i<=total; i++)
        {
            for(int j=1; j<=2; j++)
            {

                if(j&1  && (first<=page || last<=page))
                {
                    if(last<=page)
                        printf("Sheet %d, front: %d, %d",i,last,first);
                    else
                        printf("Sheet %d, front: Blank, %d",i,first);

                    printf("\n");

                }
                else if(!(j&1)  && (first<=page || last<=page))
                {
                    if(last<=page)
                        printf("Sheet %d, back : %d, %d",i,first,last);
                    else
                        printf("Sheet %d, back : %d, Blank",i,first,last);
                    cout<<endl;
                }
                first++,last--;

            }


        }

    }

}

