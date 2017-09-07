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

int image[2][4092+2]; // required size of array : 4 + 4^2 + 4^3 +4^4 +4^5 // since depth is 5
int finalImage[4092+1];
int strIndx;

int levelCounting(int indx)
{
    return (int)ceil(log(3*indx*1.0/4+1)/log(4))-1;
}

int countBlackPixel()
{
    int total=0;
    for(int i=1; i<=4092; i++)
    {
        if(finalImage[i]==2)
        {
            total+=1024/pow(4,levelCounting(i));  // at each level pixel is divided by 4
        }
    }
    return total;
}
// nodes will be colored as following
// parent 0,white = 1 ,black  = 2;

void buildFinalTree(int indx)
{
    for(int i=indx; i<indx+4; i++)
    {
        if(image[0][i]==2 || image[1][i]==2) // if any of the two is a black node then we will make
                                            // make the resultant node to be black
        {
            finalImage[i] = 2;
            continue;
        }
        else if (image[0][i]==0 || image[1][i]==0) buildFinalTree(i*4+1); // if any of the node is parent (obviously not black )
                                                                         // we will go into recursion
    }
    return;
}

void buildTree(string str,int indx,int n)
{
    if(strIndx==str.length()) return;
    for(int i=indx; i<indx+4 && strIndx<str.length(); i++)
    {
        if(str[strIndx]=='p')
        {
            image[n][i] = 0 ,  strIndx++;
            buildTree(str,i*4+1,n);
        }
        else if(str[strIndx]=='f')
        {
            image[n][i] = 2,   strIndx++;
        }
        else
        {
            image[n][i] = 1,   strIndx++;
        }

    }
    return;
}

int main()
{
    int test;
    sf(test);
    while(test--)
    {
        mstn(image), mst(finalImage);
        string str;
        cin>>str;
        strIndx = 0;
        buildTree(str,1,0); // first tree
        cin>>str;
        strIndx = 0;
        buildTree(str,1,1); // second tree
        buildFinalTree(1);
        int cnt = countBlackPixel();
        printf("There are %d black pixels.\n",cnt);
    }
}
