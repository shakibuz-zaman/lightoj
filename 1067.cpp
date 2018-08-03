#include<bits/stdc++.h>
#define lli long long int
#define MAX 9000009
#define MOD 1000003
#define PP 1000000007
using namespace std;
lli fn[1000004],infn[1000006];
//-----------Using Euler's theorem - Inverse Modulo - x=a^(M-2)mod(M)
lli F(lli N, lli P){
    if(P==0) return 1;
    if(P%2==0){
        lli ret=F(N,P/2);         //------x^-1 mod(M) = x^(M-2) mod(M) if M is prime
        return ( (ret%MOD)*(ret%MOD) )%MOD;
    }
     else return ( (N%MOD)*( F(N,P-1)%MOD ) )%MOD;
}
//---------------------------------------
lli invmod( lli a ){       //Inverse Modulo calculation
    return F(a,MOD-2);
}
 
lli ncr(lli n, lli r){
    if(n<r) return 0;
    if(r==0) return 1;
    lli aa=1,bb=1;
    aa=(invmod(fn[n-r])*invmod(fn[r]))%MOD;
    return (fn[n]*aa)%MOD;
 
}
void ini(){
 
    lli aa=1,bb=1;
    fn[0]=1;
    for(lli i=1;i<=1000000;i++){
        fn[i]=(fn[i-1]*i)%MOD;
    }
}
 
int main(){
    int t;
    ini();
    //cout<<ncr(5,3);
    scanf("%d",&t);
    lli x,y;
    for(int i=1;i<=t;i++){
        scanf("%lld%lld",&x,&y);
        lli res=ncr(x,y);
        cout<<"Case "<<i<<": "<<res<<endl;
    }
    return 0;
 
}