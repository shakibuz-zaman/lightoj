#include<bits/stdc++.h>
#define lli long long int
using namespace std;
 
lli npalin(string str){
    lli dp[111][111];
    memset(dp,0,sizeof(dp));
    int slen=str.length();
    for(int i=0;i<slen;i++)
        dp[i][i]=1;
    for(int i=0;i<slen-1;i++)
        dp[i][i+1]=(str[i]==str[i+1])?3:2;
 
    for(int i=2;i<slen;i++){
        int m=0,n=m+i;
        while(n<slen){
            //cout<<m<<" "<<n<<endl;
            if(str[m]==str[n]){
                dp[m][n]+=(dp[m+1][n-1]*2+3);
            }
            if(str[m]!=str[n]){
                dp[m][n]+=(dp[m+1][n-1]+2);
            }
            //-------A AAA A----
            for(int j=n-1;j>m+1;j--)
                if(str[m]==str[j]) dp[m][n]+=(dp[m+1][j-1]+1);
            if(str[m]==str[m+1])
                dp[m][n]++;
 
            for(int j=m+1;j<n-1;j++)
                if(str[j]==str[n]) dp[m][n]+=(dp[j+1][n-1]+1);
            if(str[n]==str[n-1])
                dp[m][n]++;
 
            //cout<<dp[m][n]<<" ";
 
            m++;n++;
        }
        //cout<<endl;
    }
    //cout<<endl;
    return dp[0][slen-1];
}
 
 
int main(){
    int t;
    cin>>t;
 
    string str;
    for(int i=1;i<=t;i++){
        cin>>str;
        cout<<"Case "<<i<<": ";
        cout<<npalin(str)<<endl;
    }
    return 0;
}
 
 