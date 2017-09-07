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
typedef pair<int,int> pi;
vector<int> ara;
// this is nlogn solution for longest_increasing_subsequesnce

int ceilIndex(vector<int> &store,int num,int low,int high)
{
    int mid=max(1,(high+low)/2);
    if(low>high) return -1;
    if(num<=ara[store[mid]] && num>ara[store[mid-1]])
    {
        return mid;
    }
    if(num<ara[store[mid-1]])   ceilIndex(store,num,low,mid-1);
    if(num>ara[store[mid]])    ceilIndex(store,num,mid+1,high);
}
void longest_increasing_subsequesnce(vector<int> &ara)
{
    int siz=ara.size();
    int prevIndex[siz+1];
    vector<int> store;
    store.pb(0);
    int indx=0,location;
    mstn(prevIndex);
    int mxIndx,mxLength;
    for(int i=1; i<siz; i++)
    {
        if(ara[i]>ara[store[indx]])
        {
            store.pb(i), prevIndex[i]=store[indx], indx++ ;
        }
        else if(ara[i]<ara[store[0]])
        {
            store[0]=i ;
        }
        else
        {
            location=ceilIndex(store,ara[i],0,indx);
            store[location]=i, prevIndex[i]=store[location-1];
        }
    }
    mxLength=store.size();
    printf("%d\n-\n",mxLength);

    int show[mxLength],cnt=mxLength-1;
    mxIndx=store[cnt];

    while(mxIndx!=-1)
    {
        show[cnt--]=ara[mxIndx];
        mxIndx=prevIndex[mxIndx];
    }
    show[cnt]=ara[mxIndx];
    for(auto &a:show)
        cout<<a<<endl;


}
int main()
{
    int num;
    while(scanf("%d",&num)!=EOF )
    {
        ara.pb(num);
    }
    longest_increasing_subsequesnce(ara);
}


