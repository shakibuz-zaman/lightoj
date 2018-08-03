#include<bits/stdc++.h>
using namespace std;
int Z[2*1000000];
int pr(int n,int chk){
    //cout<<endl;
    int co=0;
    for(int i=chk+1;i<n;i++){
        if(Z[i]==chk)
            co++;
        //cout<<Z[i]<<" ";
    }
    //cout<<endl;
    return co;
}
void setZ(string s){
    Z[0]=0;
    int left=0,right=0,i,j,k,len=s.length();
    for(i=0;i<len;i++){
        if(i>right){
            left=right=i;
            while(right<len&&s[right]==s[right-left]){right++;}
            Z[i]=right-left;
            right--;
        }
        else{
            int k=i-left;
            if(Z[k]<right-i+1)
                Z[i]=Z[k];
            else{
                left=i;
                while(right<len&&s[right]==s[right-left]){right++;}
                Z[i]=right-left;
                right--;
            }
        }
    }
}
int main(){
    string s,sub;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>s>>sub;
        int tmp=sub.length();
        sub+='$';
        sub+=s;
        setZ(sub);
        printf("Case %d: %d\n",i,pr(sub.length(),tmp));
        //cout<<pr(sub.length(),tmp)<<endl;
    }
    return 0;
}