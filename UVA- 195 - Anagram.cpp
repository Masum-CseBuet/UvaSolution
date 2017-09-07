#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n);
#define nl printf("\n")
#define mst(n) memset(n,0,sizeof(n));

using namespace std;

bool cmp(char a,char b)
{
    if(abs(a-b)!=32)
    return tolower(a)<tolower(b);
    return a<b;
}

int main()
{
    int test;
    sf(test);
    while(test--)
    {
        string str;
        cin>>str;
        sort(str.begin(),str.end(),cmp);
        do{
            cout<<str;
            nl;
        }while(next_permutation(str.begin(),str.end(),cmp));

    }
}
