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
#define mstn(n) memset(n,-1,szeof(n))
#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)
#define ull unsigned long long
#define V 1000001
#define sz 1005
#define mod 1000000007
using namespace std;

int main()
{
    int y;

    string str;
    while(getline(cin,str))
    {
        vector<int> c;
        vector<int> x;
        istringstream ss;
        ss.str(str);
        while(ss>>y)
        {
            c.push_back(y);
        }
        ss.str("");
        ss.clear();
        int n = c.size()-1;
        reverse(c.begin(),c.end());
        getline(cin,str);
        ss.str(str);
        while(ss>>y)
        {
            x.push_back(y);
        }

        int how = x.size();
        for(int i=0; i<how; i++)
        {
            long long val = x[i];
            long long sum=c[0];
            for(int j=1; j<=n; j++)
            {
                //cout<<val<<"  "<<c[i]<<endl;
                sum+=(val*c[j]);
                val*=x[i];
            }
            cout<<sum;
            if(i!=how-1)
                cout<<" ";
        }
        nl;
    }



}

