#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n);
#include<stdlib.h>

using namespace std;

template<class T>
inline bool inRange(T ans,T st,T lst)
{
    return (ans>=st && ans < lst);
}

int main()
{
    int test;

    while(1)
    {
        vector<int> str;

        int num,i,j,k;
        sf(num);
        if(num==0) return 0;
        while(1)
        {
            str.push_back(num);
            sf(num);
            if(num==0)
                break;
        }

        int siz=str.size();
        vector<int> strt(siz,0);
        int ans=*min_element(str.begin(),str.end()),tmp;  // taking the lowest time of any light changes to orange as ans

        bool chk=true;
        for(;ans<=18000 ; ans++)
        {
            chk=true;
            for(i=0; i<siz; i++)
            {

                while(strt[i]+str[i]-5<=ans)
                    strt[i]+=2*str[i];      // loop until the ans is within the time green light lasts

                if(!inRange(ans,strt[i],strt[i]+str[i]))  // checking if ans is in the range of green cycle
                {
                    ans=strt[i]-1; // if not then make the ans starting time  of the green cycle
                    chk=false;
                    break;
                }
            }
            if(chk)
                break;
        }

        if(ans>18000)
            printf("Signals fail to synchronise in 5 hours\n");
        else
            printf("%02d:%02d:%02d\n",ans/3600,(ans%3600)/60,ans%60);

    }

}











