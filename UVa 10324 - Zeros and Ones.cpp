#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)

#define sf(n) scanf("%d",&n);
using namespace std;

int main()
{
    int  test=1;
    string str;
    while(1)
    {
        getline(cin,str);

        if(str.length()==0) break;

        vector<int> ara(1000000,0);
        vector<int>::iterator it=ara.begin();
        char prev=str[0];
        char cur=str[0];
        int now=0,then=0;
        int i;

        for( i=0; i<str.length(); i++)
        {
            cur=str[i];
            if(cur!=prev)
            {
                fill(it+then,it+i,i-1);
                then=i;
                prev=str[i];
            }
        }
        fill(it+then,it+i,i-1);
        printf("Case %d:\n",test++);
        int query;
        scanf("%d",&query);
        int a,b;
        while(query--)
        {
            scanf("%d %d",&a,&b);
            getchar();
            int mini=min(a,b);
            int maxi=max(a,b);

            if(ara[mini]==ara[maxi])
                printf("Yes\n");
            else
                printf("No\n");
        }

    }




}


