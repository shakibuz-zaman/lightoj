#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
int n;
int men[333],fen[333];
int choice[2*300+1][300+1];
 
bool chover(int w,int m1,int m){
    for(int i=1;i<=n;i++){
        if(choice[w][i]==m1)
            return true;
        if(choice[w][i]==m)
            return false;
    }
}
void stable(int n){
 
    for(int i=0;i<=n+2;i++){
        men[i]=fen[i]=0;
    }
 
    int mfree=n;
    int mtmp;
    while(mfree>0){
 
        for(int i=1;i<=n;i++){
            if(men[i]==0){
                mtmp=i;
                break;
            }
        }
        for(int i=1;i<=n && men[mtmp]==0;i++){
            int w=choice[mtmp][i];
            if(fen[w-n]==0){
                mfree--;
                men[mtmp]=w;
                fen[w-n]=mtmp;
            }
            else{
                int mpast=fen[w-n];
                if(chover(w,mtmp,mpast)==true){
                    men[mtmp]=w;
                    men[mpast]=0;
                    fen[w-n]=mtmp;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<" ("<<i<<" "<<men[i]<<")";
    puts("");
 
}
int main(){
    int T;
    cin>>T;
    for(int z=1;z<=T;z++){
        cin>>n;
 
        for(int i=1;i<=2*n;i++)
            for(int j=1;j<=n;j++)
                cin>>choice[i][j];
        cout<<"Case "<<z<<":";
        stable(n);
    }
    return 0;
}
 