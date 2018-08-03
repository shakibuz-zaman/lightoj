#include<bits/stdc++.h>
using namespace std;
int Set(int N,int pos){return N=N |(1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){ return (bool)(N&(1<<pos));}
int n,dp[999999];
int w[16][16];
int call(int mask){
    //cout<<mask<<endl;
    if(mask==((1<<n)-1))return 0;
    if(dp[mask]!=-1)return dp[mask];
    int ans=1<<28;
    for(int i=0;i<n;i++){
        if(check(mask,i)==0){
            int price=w[i][i];
            for(int j=0;j<n;j++)
                if(check(mask,j)==1)price+=w[i][j];
            int ret=price+call(Set(mask,i));
            ans=min(ret,ans);
        }
    }
    return dp[mask]=ans;
 
}
 
int main(){
    int t;
    cin>>t;
    for(int k=1;k<=t;k++){
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>w[i][j];
        int tot=call(0);
        printf("Case %d: %d\n",k,tot);
    }
}
