#include<bits/stdc++.h>
#define pb(n) push_back(n)
#define bug cout<<"bug";
#define all(c) c.begin(),c.end()
#define fr(i,n) for(i=0;i<n;i++)
#define sf(n) scanf("%d",&n)
#define mst(n,num) memset(n,0,sizeof(int)*num)
#define nl printf("\n")
#define lli long long int
#define tr(container,it) \
    for (auto it = container.begin(); it != container.end() ; ++it)

#define INF INT_MAX
#define MOD 1000000007

#define infile freopen("in.txt","r",stdin)
#define outfile freopen("out.txt","w",stdout)
#define pr(a) cout<<cout<<a.a.first<<"  "<< a.a.second<<endl
using namespace std;
// this is a simple shortest path problem in 2d grid using bfs algorithm

typedef pair<int,int> pi;
class square
{
public:
    pi a;
    square() {};
    void setpi(int,int );
    square operator+( square);
    bool operator==(square);
    bool operator<(const square &b) const;
    bool chk()
    {
        if((a.first>8) || (a.first<1) || (a.second>8) || (a.second<1) ) return 1;
        return 0;
    }
    ~square() {};

};
void square::setpi(int x,int y)
{
    a=make_pair(x,y);
}
square square::operator+( square b)
{
    square tmp;
    tmp.a.first=a.first+b.a.first,tmp.a.second=a.second+b.a.second;
    return tmp;
}
bool square::operator==(square b)
{
    return( (a.first==b.a.first) && (a.second==b.a.second)) ;
}

bool square::operator<(const square &b) const  // this operator overloading is necessary as we are going to use our class object as
                                                // map key value
{
    if(a.first==b.a.first)
        return (a.second<b.a.second);
    return (a.first< (b.a.first));
}


int bfs(square sr,square des)  // source , destination;
{
    int assin=0,des_indx,sr_indx;

    vector<square> adlist[64]; // a vector to push the squares
    map<square,int> imap;
    bool vis[64]= {};
    if(imap.find(sr)==imap.end())
        imap[sr]=assin++;
    if(imap.find(des)==imap.end())
        des_indx=imap[des]=assin++;
    if(imap[sr]==imap[des])
        return 0;

    int level[64];

    queue<square> str;
    str.push(sr), level[imap[sr]]=0;
    vis[imap[sr]]=1;
    square mov[8];
    mov[0].setpi(2,1),mov[1].setpi(2,-1),mov[2].setpi(1,2),mov[3].setpi(1,-2), mov[4].setpi(-1,2),mov[5].setpi(-1,-2),mov[6].setpi(-2,1) ;
    mov[7].setpi(-2,-1) ;  //direction array

    while(!str.empty())
    {
        square tmp=str.front();
        str.pop();
        int in1,in2;
        in1=imap[tmp];
        for(int i=0; i<8; i++)
        {
            square nw=tmp+mov[i];

            if(nw.chk()!= true)
            {

                if(imap.find(nw)==imap.end())
                {
                    imap[nw]=assin++;
                }

                adlist[in1].push_back(nw);

            }
        }

        for(int i=0; i<adlist[in1].size(); i++)
        {

            in2=imap[adlist[in1][i]];
            if(!vis[in2])
            {
                str.push(adlist[in1][i]);
                level[in2]=level[in1]+1;
                vis[in2]=1;

                if(in2==des_indx)
                    return level[in2];

            }
        }


    }


}
int main()
{
    infile;
    outfile;
    int r1,r2;
    char ch1,ch2;
    while(scanf("%c%d %c%d\n",&ch1,&r1,&ch2,&r2)!=EOF)
    {

        square sr,ds;
        sr.setpi(r1,(int)(ch1-'a'+1)),ds.setpi(r2,(int)(ch2-'a'+1));

        int min_mov=bfs(sr,ds);
        printf("To get from %c%d to %c%d takes %d knight moves.",ch1,r1,ch2,r2,min_mov);
        nl;


    }

}
