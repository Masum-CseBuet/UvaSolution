#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n);
#define nl printf("\n")
#define mst(n) memset(n,0,sizeof(n))

using namespace std;
typedef struct ELPHANT
{
    int weight;
    int iq;
    int indx;  // to store the index that will be assigned while giving input
} elpnt;
elpnt Make_Pair(int w,int q,int indx)
{
    elpnt a;
    a.weight=w,a.iq=q,a.indx=indx+1;
    return a;
}
bool cmp(elpnt a,elpnt b)
{
    return a.weight<b.weight;
}
int print(int indx,const vector<int>& ara,vector<elpnt>& lst)
{
    if(ara[indx]==-1)
    {
        printf("%d\n",lst[indx].indx);
        return 0;
    }
    print(ara[indx],ara,lst);
    printf("%d\n",lst[indx].indx);
}
int main()
{
    vector<elpnt> lst;
    int w,q,cnt=0,i,j;
    while(scanf("%d %d",&w,&q)==2)
    {
        lst.push_back(Make_Pair(w,q,cnt));
        cnt++;
    }
    sort(lst.begin(),lst.end(),cmp); // sorting input vector in the ascending order of weight
    vector<int> lds(cnt,1),show(cnt,-1); //lds for longest decreasing(iq) sequence and show for storing the index of the sequence
    for(i=0; i<cnt; i++)
    {
        for(j=0; j<i; j++)
        {
            if(lst[i].iq<lst[j].iq && (lst[i].weight>lst[j].weight)) //as weight must be strictly great
            {
                if(lds[i]<(1+lds[j]))
                {
                    lds[i]=1+lds[j];
                    show[i]=j;
                }
            }
        }
    }
    vector<int>:: iterator it= max_element(lds.begin(),lds.end());
    int indx=it-lds.begin(); //getting the index of the element that is holding the biggest number which indicates the biggest sequence

    cout<<*it<<endl;
    //now we will print the index recursively in opposite order (because we are asked to print in decreasing order )
    print(indx,show,lst);

}


