#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n);

using namespace std;
int bfs(int f,int s,const vector< int > *adlist)
{
    int level[30]= {};
    bool vis[30]= {};
    queue<int> show;
    show.push(f);
    level[f]=0;
    vis[f]=1;

    while(!show.empty())
    {
        int top=show.front();
        show.pop();
        for(int i=0; i<adlist[top].size(); i++)
        {
            int tmp=adlist[top][i];
            if(!vis[tmp])
            {
                show.push(tmp);
                vis[tmp]=1;
                level[tmp]=level[top]+1;

            }
        }
    }

    return level[s];

}
int main()
{
    //freopen ("myfile.txt","w",stdout);
    int kase=1,how;
    while(scanf("%d",&how)==1)
    {
        vector<int> adlist[30];
        int query,f,s,num;
        int i,j;
        fr(j,0,how)
        {
            {
                cin>>num;
                adlist[1].pb(num);
                adlist[num].pb(1);

            }
        }


        fr(i,1,19)
        {

            cin>>how;
            fr(j,0,how)
            {
                {
                    cin>>num;
                    adlist[i+1].pb(num);
                    adlist[num].pb(i+1);

                }
            }
        }
        cin>>query;
        printf("Test Set #%d\n",kase++);
        fr(j,0,query)
        {
            cin>>f>>s;
            printf("%2d to %2d: %d\n",f,s,bfs(f,s,adlist));
        }
        cout<<endl;
        for(int i=0; i<21; i++)
        {
            adlist[i].clear();
        }
    }
    return 0;

}


