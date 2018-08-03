#include <bits/stdc++.h>
#define lli unsigned long long int
#define mod 1000000007
using namespace std;
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
            for(int k=0;k<2;k++)
                a.mat[i][j]=(a.mat[i][j]+(this->mat[i][k]*b.mat[k][j]));
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
int main(){
    lli p,q,n;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
 
        printf("Case %d: ", i);
        cin>>p>>q>>n;
        if(n==0){
            printf("2\n");continue;
        }
        if(n==1){
            printf("%llu\n",p);continue;
        }
        lli  a1,a2,b1,b2;//=(p+sqrt(p*p-4*q))/2;
        matrix m;m.st(p,-q,1,0);
        m=m^(n-1);
        //m.show();
        lli ans=m.mat[0][0]*p+m.mat[0][1]*2;
        printf("%llu\n",ans);
 
    }
    return 0;
}