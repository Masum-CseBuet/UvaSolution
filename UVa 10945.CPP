#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n);
#define not_ok(ch) if( !(ch>='A' && ch<='Z') && !(ch>='a' && ch<='z'))
using namespace std;

int main()
{

    char str[100000];
    while(gets(str))
    {
        if(!strcmp(str,"DONE")) return 0;
        bool flag=1;
        int len=strlen(str);
        int j=0;
        for(int i=0; i<len; i++)
        {
            not_ok(str[i]) continue;
            str[j++]=str[i];
            if(str[j-1]>='a') str[j-1]-=32;
        }
        str[j]='\0';
        len=strlen(str);
        for(int i=0; i<len/2; i++)
        {
            if(str[i]!=str[len-1-i])
            {
                flag=0;
                break;
            }
        }
        if(flag==1) printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }



}


