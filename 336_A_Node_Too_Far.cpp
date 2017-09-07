#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n);

using namespace std;

int main()
{
    int kase=1;
    while(1)
    {
        int num;
        sf(num);
        if(num==0) return 0;

        vector<int> nodes[40];
        map<int,int> imap;
        int assin=0,ind=0;
        int level[40];
        for(int i=0; i<num; i++)
        {
            int f,s;
            int in1,in2;
            cin>>f>>s;  //array compression
            if(imap.find(f)==imap.end())
            {
                imap[f]=assin++;
            }
            in1=imap[f];
            if(imap.find(s)==imap.end())
            {
                imap[s]=assin++;
            }

            in2=imap[s];
            if(in1!=in2)
            {
                nodes[in1].push_back(in2);
                nodes[in2].pb(in1);
            }
            else
                nodes[in1].push_back(in2);

        }
        int st,ttl;

        while(1)
        {
            cin>>st>>ttl;
            int ans=0;
            if(st==0 && ttl==0)
            {
                break;
            }
            level[imap[st]]=0;
            queue<int> show;
            int vis[40]= {};
            show.push(imap[st]);
            vis[imap[st]]=1;

            while(!show.empty())
            {
                int top=show.front();

                show.pop();
                for(int i=0; i<nodes[top].size(); i++)
                {

                    int tmp=nodes[top][i];
                    if(!vis[tmp])
                    {
                        show.push(tmp);
                        vis[tmp]=1;
                        level[tmp]=level[top]+1;

                        if(level[tmp]<=ttl)
                            ans++;
                    }

                }
            }
            int total_node=assin-1;
   // cout<<total_node;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",kase++,total_node-ans,st,ttl);


        }
    }


}


