#include<bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,k,base;
lli dp[(1<<16)+3][27];
int Set(int N,int pos){return N=N |(1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){ return (bool)(N&(1<<pos));}
string str;
lli call(lli mask,lli rem){
    //cout<<rem<<endl;
    //printf("Mask=%lld Base=%lld K=%lld  rem=%lld\n",mask,base,k,rem);
    if( mask==(1<<(n))-1 )return (rem==0);
    if(dp[mask][rem]!=-1)return dp[mask][rem];
    lli cnt=0;
    for(int i=0;i<n;i++){
        if(check(mask,i)==0){
            lli dt=(lli)str[i];
            lli d=(rem*base+dt )%k;
            //cout<<"dt="<<dt<<endl;
 
            cnt+=call( Set(mask,i),( rem*base+dt )%k );
        }
    }
    return dp[mask][rem]=cnt;
}
 
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        memset(dp,-1,sizeof(dp));
        cin>>base>>k;
        cin.ignore();
        cin>>str;
        for(int i=0;i<str.length();i++) str[i]=(str[i]>='0'&&str[i]<='9')?str[i]-'0':str[i]-'A'+10;
 
        //cout<<endl;
        n=str.length();
        printf("Case %d: %lld\n",i,call(0,0));
        //cout<<call(0,0)<<endl;
    }
    return 0;
}
 