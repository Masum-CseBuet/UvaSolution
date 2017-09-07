#include<bits/stdc++.h>
#define bug cout<<"bug";
#define pb(n) push_back(n)
#define lli long long int
#define fr(i,s,l) for(i=s;i<l;i++)
#define sf(n) scanf("%d",&n);
#define nl printf("\n")
#define mst(n) memset(n,0,sizeof(n))



using namespace std;

int main()
{
   while(1)
   {
       int hr,mn;
       double angle,hr_angle,mn_angle;
       scanf("%d:%d",&hr,&mn);
       if(hr==0 && mn==0)  return 0;
       hr_angle= hr* 30 +  mn/2.0  ,  mn_angle= mn*6 ;
       angle = abs(hr_angle - mn_angle);
       if(angle > 180 ) angle = 360 - angle;
       printf("%.3lf\n",angle);
   }
}
