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
#define ull unsigned long long
#define V 1000001
#define sz 1005
#define MOD 100000007
using namespace std;

int mapping(string str,int &cnt,map<string,int> &imap)
{
    if(imap.find(str)==imap.end())
    {
        imap[str] = cnt++;
    }
    return imap[str];
}

int person[2][100+1];
int dp[100+1][100+1];
vector<string> word(200);

int m,n;

int lcs(int m,int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(person[0][j]==person[1][i])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    stack<string> st;
    int r = n,c = m;
    while(r!=0 && c!=0)
    {

        if(dp[r][c]==dp[r-1][c])
        {
            r = r-1;
        }
        else if(dp[r][c]==dp[r][c-1])
        {
            c= c-1;
        }
        else
        {
            st.push(word[person[0][c]]);
            r = r-1, c = c-1;
        }
    }

    string str = st.top();
    cout<<str;
    st.pop();
    while(!st.empty())
    {
        str = st.top();
        st.pop();
        cout<<" "<<str;
    }
    nl;

}
int main()
{
    string str;
    while(cin>>str)
    {
        mst(dp), mst(person) ;
        int cnt = 0,indx = 1;
        map<string,int> imap;

        int m = mapping(str,cnt,imap);
        word[m] = str;
        person[0][indx++] = m;
        int f=1,s=0;

        for(int p=0; p<2; p++)
        {
            while(cin>>str)
            {
                if(str=="#")
                {
                    indx = 1;
                    break;
                }
                m = mapping(str,cnt,imap);
                person[p][indx++] = m;
                word[m] = str;
                if(p==0) f++;
                else s++;
            }
        }

        lcs(f,s);


    }

}
