#include<bits/stdc++.h>
#include <functional>
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
#define ull unsigned long long
#define V 1000001
#define sz 1005
#define MOD 1000000007
using namespace std;

int main()
{
    int test,kase = 1;
    sf(test);
    while(test--)
    {
        int num;
        sf(num);
        getchar();
        string str;
        vector<string> given;
        map<string,int> imap;

        for(int i=1; i<=num; i++)
        {
            getline(cin,str);
            imap[str] = num-i;
            given.push_back(str);
        }
        reverse(all(given));

        int req[num],ordering[num];
        for(int i=num-1; i>=0; i--)
        {
            getline(cin,str);
            req[imap[str]] = i;
            ordering[i] = imap[str];
        }
        int cnt = 0;
        vector<int> stk;

        for(int i=0;i<num;i++)
        {
            if(imap[given[i]]-cnt<req[imap[given[i]]])
            {
                cnt++;
                stk.push_back(req[imap[given[i]]]);
            }
        }
        sort(all(stk));

        for(int i=0; i<stk.size(); i++)
        {
            printf("%s\n",given[ordering[stk[i]]].c_str());
        }
        nl;
    }

}
