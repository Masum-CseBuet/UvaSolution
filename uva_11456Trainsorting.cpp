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
// this is a variant of lis problem
// there exist an easy solution of  O(n^2)
// this soln,however,  is of O(nlogn)
 // idea is to find the longest increasing and decreasing subsequence for every num then , as  we can add at front or back ,
 // we can find the solution by finding the max of (Vx)(for all)  LengthOfLIS+LengthLDS-1 (as the number which is being considered to be at first) is being counted twice

int findIndex1(int ara[],vector<int> &indxStore1,int how,int num)
{
    int high=how,low=0;
    int mid=max(1,(high+low)/2);
    while(low<=high)
    {
        mid=max(1,(high+low)/2);
        if(num>=ara[indxStore1[mid]] && num<ara[indxStore1[mid-1]]) return mid;
        if(num<ara[indxStore1[mid]] ) low=mid+1 ;
        else if(num>ara[indxStore1[mid-1]] ) high=max(1,mid-1) ;
    }
}

int findIndex2(int ara[],vector<int> &indxStore2,int how,int num)
{
    int high=how,low=0;
    int mid=max(1,(high+low)/2);;
    while(low<=high)
    {
        mid=max(1,(high+low)/2);
        if(num<ara[indxStore2[mid]] && num>ara[indxStore2[mid-1]]) return mid;
        if(num>ara[indxStore2[mid]] ) low=mid+1 ;
        else if(num<ara[indxStore2[mid+1]] ) high=max(1,mid-1) ;
    }
}

int  lenCalculate(int prev[],int num,int len[])
{
    if(prev[num]==-1) return len[num]=1;
    else if(len[num]!=1) return len[num];
    len[num]=lenCalculate(prev,prev[num],len)+1;
}

int Trainsorting(int ara[],int how)
{
    int len1[how],len2[how];
    int prev1[how],prev2[how];
    mstn(prev1), mstn(prev2);
    for(int i=0; i<how; i++) len1[i]=len2[i]=1;

    vector<int> indxStore1,indxStore2;
    vector<int>::iterator it;

    indxStore1.pb(how-1),indxStore2.pb(how-1);

     // we will loop through form back end
     // so that when will calculate the length by recursively going with previous index we can find the correct length
     // notice that finding the LIS of of 3 2 1 from front
     // is same as finding the LDS of it from back

    for(int i=how-2; i>=0; i--)
    {

        if(ara[i]<ara[indxStore1.back()])  // as we are going from back part this is actually counting The LIS from front part
        {
            prev1[i]=indxStore1.back(),indxStore1.pb(i) ;
        }
        else if(ara[i]>ara[indxStore1[0]])
        {
            indxStore1[0]=i;
        }
        else
        {
            int indxLocation=findIndex1(ara,indxStore1,indxStore1.size()-1,ara[i]);
            indxStore1[indxLocation]=i;
            prev1[i]=indxStore1[indxLocation-1];
        }
        //this part is same as previous one . only difference is this is finding LDS from front part (or LIS form back end)

        if(ara[i]>ara[indxStore2.back()])
        {
            prev2[i]=indxStore2.back(), indxStore2.pb(i);

        }
        else if(ara[i]<ara[indxStore2[0]])
        {
            indxStore2[0]=i;
        }
        else
        {
            int indxLocation=findIndex2(ara,indxStore2,indxStore2.size()-1,ara[i]);
            indxStore2[indxLocation]=i;
            prev2[i]=indxStore2[indxLocation-1];
        }

    }

    for(int i=0; i<how; i++)
    {
        lenCalculate(prev1,i,len1);  // for lis part
        lenCalculate(prev2,i,len2);  // for lds part
    }
    int ans=-INF;
    for(int i=0; i<how; i++)
    {
        ans=max(ans,len1[i]+len2[i]-1);
    }
    return ans;
}
int main()
{
    int test;
    sf(test);
    while(test-- )
    {
        int how;
        sf(how);
        int ara[how];
        for(int i=0; i<how; i++)
            sf(ara[i]);
        if(how==0) cout<<0<<endl;
        else
        {
            int ret=Trainsorting(ara,how);
            cout<<ret<<endl;
        }
    }

}
