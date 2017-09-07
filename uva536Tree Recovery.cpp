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

using namespace std;

int lft[26+1];
int rght[26+1];
int strIndx;

void postOrder(int n)
{
    char ch = n+65;
    if(lft[n]==-1 && rght[n]==-1)
    {
        cout<<ch;
        return;
    }
    if(lft[n]!=-1) postOrder(lft[n]);
    if(rght[n]!=-1) postOrder(rght[n]);

    cout<<ch;
}
int buildTree(string pre,string in,int strt,int lst)
{
    if(strt>lst) return -1;
    char ch = pre[strIndx++];

    int indx = in.find(ch);
    if(strt==lst)
    {
        lft[ch-65] = rght[ch-65] = -1;
        return ch-65;
    }
    lft[ch-65] = buildTree(pre,in,strt,indx-1);
    rght[ch-65] = buildTree(pre,in,indx+1,lst);

    return ch-65;
}
int main()
{
    string pre,in;
    while(cin>>pre>>in)
    {
        mstn(lft), mstn(rght);
        strIndx = 0;
        buildTree(pre,in,0,pre.length()-1);
        postOrder(pre[0]-65);
        nl;
    }
}
