#include<bits/stdc++.h>
#define pb(n) push_back(n)
#define bug cout<<"bug";
#define all(c) c.begin(),c.end()
#define fr(i,n) for(i=0;i<n;i++)
#define sf(n) scanf("%d",&n)
#define mst(n) memset(n,0,sizeof(n))
#define nl printf("\n")
#define lli long long int
#define tr(container,it) \
    for (auto it = container.begin(); it != container.end() ; ++it)

#define INF INT_MAX

#define mp(i,j) make_pair(i,j)
#define mstn(n) memset(n,-1,sizeof(n))
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)

#define V 5

using namespace std;
class Num
{
public:
    string str;

    Num() {}
    Num(string b)
    {
        str=b;
    }

    Num rev()
    {
        Num tmp;
        tmp.str=str;
        reverse(tmp.str.begin(),tmp.str.end());
        return tmp;
    }

    Num operator+(Num b)
    {
        Num tmp;

        char t[100];
        int len=b.str.length();
        int prev=0,i;
        for( i=len-1; i>=0; i--)
        {
            t[len-1-i]=(b.str[i]-'0'+str[i]-'0'+prev)%10+'0';

            prev=(b.str[i]-'0'+str[i]-'0'+prev)/10;
        }

        if(prev>0) t[len-1-(i--)]=prev+'0';
        t[len-1-i]='\0';
        tmp.str=t;
        reverse(tmp.str.begin(),tmp.str.end());
        return tmp;
    }
    bool isPallindrome()
    {
        int len=str.length();
        for(int i=0; i<len/2; i++)
            if(str[i]!=str[len-1-i])
            {
                return 0;
            }
        return 1;
    }
};
string to_str(int num)
{
    stringstream ss;
    ss<<num;
    return ss.str();
}
int main()
{

    int n,test;
    sf(test);
    while(test--)
    {
        scanf("%d",&n);
        Num a(to_str(n)),b,add;

        int cnt=0;
        while(1)
        {
            b=a.rev();
            add=a+b;
            cnt++;
            if(add.isPallindrome())
                break;
            a=add;

        }
        cout<<cnt<<" "<<add.str<<endl;
    }
}






















/*
int main()
{
    outfile;
    int n,s,r,c=2,g=1,v;
    int ara[]= {0,80,46,40,35};
    for(int i=1; i<=15; i++)
    {
        printf("Roll:%d\n",i);
        for(int j=1; j<=4; j++)
        {
            n=(2*c+3*(j+2)+i) % ara[j] ;
            v=(3*c+5*(j+2)+i) % 60 + 60*g;
            printf("Exercise:2.%d--Problem no=%d  Verifier Id:%d\n",j+2,n,v);
        }
        cout<<endl;
    }
}
*/








