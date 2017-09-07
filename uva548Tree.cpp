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

int postIndx;
struct node
{
    int data;
    node* left;
    node* right;

};
// node to store the information of leaf node with minimum sum
struct minNode
{
    int indx,sum;
    minNode(int i,int s)
    {
        indx = i, sum = s;
    }
    minNode() {};
    bool operator<(minNode a)
    {
        if(sum==a.sum) return indx<a.indx;
        return sum<a.sum;
    }
};

node* newNode(int d)
{
    node* tmp = new node();
    tmp->data = d;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

int searchIndx(int ara[],int strt,int lst,int val)
{
    for(int i=strt; i<=lst; i++)
    {
        if(ara[i]==val) return i;
    }
}

minNode mn;

minNode findLeaf(node* root,int sum)
{

    if(root->left==NULL && root->right==NULL)
    {
        minNode cur = minNode(root->data,sum+root->data);
        if(cur<mn) mn = cur;
    }
    if(root->left!=NULL)
        findLeaf(root->left,sum+root->data);
    if(root->right!=NULL)
        findLeaf(root->right,sum+root->data);
}

node* buildTree(int inorder[],int postorder[],int strt,int lst)
{
    if(strt>lst) return NULL;
    node *cur = newNode(postorder[postIndx--]);
    if(strt==lst) return cur;
    int indx = searchIndx(inorder,strt,lst,cur->data);

    cur->right = buildTree(inorder,postorder,indx+1,lst);
    cur->left = buildTree(inorder,postorder,strt,indx-1);

    return cur;

}

int main()
{
    string str;
    int inorder[10000];
    int postorder[10000];
    while(getline(cin,str))
    {
        mst(inorder), mst(postorder);
        int i = 0;
        stringstream ss(str);
        while(ss>>inorder[i++]);
        int len = i-1;
        i = 0;
        getline(cin,str);
        ss.clear();
        ss.str(str);
        while(ss>>postorder[i++]);

        postIndx = len-1;
        node *root = buildTree(inorder,postorder,0,len-1);
        mn.sum = INF;
        findLeaf(root,0);
        cout<<mn.indx<<endl;
    }

}
