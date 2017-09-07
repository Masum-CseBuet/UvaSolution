#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)

#define sf(n) scanf("%d",&n);
using namespace std;

int main()
{

    int l;
    while(scanf("%d",&l) && l)
    {
        getchar();
        int d=-1,r=-1,res=INT_MAX;
        char str[l+10];
        gets(str);

        for(int i=0;i<l;i++)
        {
            if(str[i]=='Z') {
                res=0;
                break;
            }
            else if(str[i]=='R')
            {
                bug;
                r=i;
                if(d>=0)
                {
                    //bug;
                    res=min(res,r-d);
                }
            }
            else if(str[i]=='D')
            {
                d=i;
                if(r>=0)
                {

                    res=d-r;

                }
            }
        }
        //cout<<endl<<r<<"  "<<d<<endl;
        printf("%d\n",res);




    }


}


