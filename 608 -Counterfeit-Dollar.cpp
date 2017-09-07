#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n);
#include<stdlib.h>

//3==even  if found up then 1st string ch value is reduced else increased
//then the max absoulte diff.. is the indicator of ans  bcz it appeared most of the time at same condition

using namespace std;

int main()
{
    int test;
    cin>>test;
    getchar();
    while(test--)
    {
        vector<int> ara(12,-1);
        vector<string> str1[3];
        string str;
        for(int i=0; i<3; i++)
        {
            for(int m=0; m<3; m++)
            {
                cin>>str;
                str1[i].push_back(str);
            }

            int len=str1[i][1].length();

            for(int k=0; k<2; k++)
                for(int j=0; j<len; j++)
                {
                    int num=str1[i][k][j]-65;
                    if(str1[i][2]=="even")
                        ara[num]=3;

                    else if(str1[i][2]=="up")
                    {
                        if(ara[num]==-1) ara[num]=4;  //if visited 1st time then set it to 1 greater then even value
                        else if(ara[num]>3) ara[num]++; //if visited twice then increase the value
                        else if(ara[num]<3) ara[num]=3; //bcz a value can't have 2 different weight simultaneously
                        if(j==len-1) str1[i][2]="down";

                    }
                    else if(str1[i][2]=="down")
                    {

                        if(ara[num]==-1) ara[num]=2;
                        else if(ara[num]<3) ara[num]--;
                        else if(ara[num]>3) ara[num]=3;
                        if(j==len-1) str1[i][2]="up";
                    }

                }

        }

        int mx=0,ans;
        // checking for the most visited ch by max abs diff..
        for(int i=0; i<12; i++)
        {
            if(ara[i]!=-1 && abs(3-ara[i])>mx) mx=abs(3-ara[i]), ans=i;
        }

        printf("%c is the counterfeit coin and it is %s.",ans+65,ara[ans]>3?"heavy":"light");
        cout<<endl;
    }
}
