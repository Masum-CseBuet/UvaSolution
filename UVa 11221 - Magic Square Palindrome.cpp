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
    int test;
    sf(test);
    getchar();
    for(int t=1; t<=test; t++)
    {
        gets(str);
        bool flag=1;
        int len=strlen(str);
        int j=0;
        for(int i=0; i<len; i++)
        {
            if(!isalpha(str[i])) continue;
            str[j++]=str[i];  //making string containing non-whitespace+punctuation
            if(str[j-1]>='a') str[j-1]-=32;  //making all characters upperCase
        }
        str[j]='\0';
        //cout<<str;
        len=strlen(str);
        int k=round(sqrt(len));
        if(k*k!=len)
        {
            printf("Case #%d:\nNo magic :(\n",t);
            continue;
        }
        char ara[k][k];
        int it=0;
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<k; j++)
            {
                ara[i][j]=str[it++];
                //printf("%c  ",ara[i][j]);
            }
             //cout<<endl;
        }
        for(int i=0; i<k/2; i++)
        {
            for(int j=i; j<k; j++)
            {
                if(ara[i][j]!= ara[i][j] ||  ara[k-1-i][k-1-j]!=ara[k-1-j][k-1-i] || ara[i][j]!=ara[k-1-i][k-1-j])
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0) printf("Case #%d:\nNo magic :(\n",t);
        else
            printf("Case #%d:\n%d\n",t,k);

    }



}


