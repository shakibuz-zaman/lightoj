#include<bits/stdc++.h>
#define SIZE 2
#define lli long long int
using namespace std;
int mod;
struct matrix{
    lli mat[3][3];
    void st(int a,int b,int c,int d){
        mat[0][0]=a;mat[0][1]=b;mat[1][0]=c;mat[1][1]=d;
    }
    void zero(){
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                mat[i][j]=0;
    }
    void show(){
        cout<<endl;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++)
                cout<<mat[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    matrix operator*(matrix &b){
        matrix a;a.zero();
        for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<SIZE;k++)
                a.mat[i][j]=(a.mat[i][j]+(this->mat[i][k]*b.mat[k][j])%mod)%mod;
        }
        }
        return a;
    }
    matrix operator^(lli n){
        matrix res,tmp;
        res.mat[0][0]=res.mat[1][1]=1;res.mat[1][0]=res.mat[0][1]=0;
        tmp.mat[0][0]=mat[0][0];tmp.mat[1][1]=mat[1][1];tmp.mat[1][0]=mat[1][0];tmp.mat[0][1]=mat[0][1];
        while(n>0){
        if(n%2==0){
 
            tmp=tmp*tmp;
            n/=2;
            continue;
        }
        n--;
        res=res*tmp;
        }
        return res;
    }
};
void setm(lli m){
    int s=10;
    for(int i=1;i<=m;i++){
        mod*=s;
    }
}
void solve(lli a,lli b,lli n,lli m){
    setm(m);
    if(n==0){
        a%=mod;
        printf("%lld",a);return;
    }
    if(n==1){
        b%=mod;
        printf("%lld",b);return;
    }
    matrix fib;fib.st(1,1,1,0);
    matrix r;r.st(1,1,1,0);
    fib=fib^(n-2);
    lli f1=fib.mat[0][0];
    fib=fib*r;
    lli f2=fib.mat[0][0];
    lli res=(f1*a+f2*b)%mod;
    printf("%lld\n",res);
}
int main(){
    lli a,b,t,n,m;
    cin>>t;
    for(int i=1;i<=t;i++){
        mod=1;
        cin>>a>>b>>n>>m;
        printf("Case %d: ",i);
        solve(a,b,n,m);
    }
    return 0;
}