#include<bits/stdc++.h>
#define lli long long int
using namespace std;
lli H(lli n){
    int i=2,co=1;
    lli sum=0;
    while((n/i)+1<n/(i-1)){
            sum=sum+(-((n/i)+1)+(n/(i-1))+1)*(i-1);
           i++;
    }
    lli tmp=(n/(i-1));
    for(int k=tmp;k>=1;k--){
        sum=sum+n/k;
    }
    return sum;
}
int main (){
    lli n,t,i,j,tmp;
    scanf("%lld",&t);
    for(i=1;i<=t;i++){
        scanf("%lld",&n);
        printf("Case %lld: %lld\n",i,H(n));
    }
    return 0;
}