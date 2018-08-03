#include<bits/stdc++.h>
 #define mx 103
#define mod  100000007
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
 using namespace std;
 int coin[51],c[51];
 int dp[10001][51];
 map<int,int>mp;
int calc(int i,int amount,int cn,int mon){
    if(i>=cn){
        if(amount==mon)
            return 1;
        return 0;
    }
    if(amount>mon)return 0;
    if(amount==mon)return 1;
    if(dp[amount][i]!=-1)return dp[amount][i];
    int ret=0;
    for(int ii=1;ii<=c[i];ii++){
        if(amount+coin[i]*ii<=mon)
            ret+=calc(i+1,amount+coin[i]*ii,cn,mon)%mod;
        else break;
    }
    ret+=calc(i+1,amount,cn,mon)%mod;
    return dp[amount][i]=ret%mod;
 
}
 int main(){
    int t,i,j,cn,mon;
 
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d",&cn,&mon);
        for(int j=0;j<cn;j++)
            scanf("%d",&coin[j]);
        for(int j=0;j<cn;j++)
            scanf("%d",&c[j]);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",i,calc(0,0,cn,mon)%mod);
    }
    return 0;
 }