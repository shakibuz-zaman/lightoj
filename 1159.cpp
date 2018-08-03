#include<bits/stdc++.h>
#define mx 55
using namespace std;
int dp[mx][mx][mx];
bool visited[mx][mx][mx];
int calc(char *s1,char *s2,char *s3,int i,int j,int k){
    if(s1[i]=='\0'||s2[j]=='\0'||s3[k]=='\0'){
            return 0;
    }
    if(visited[i][j][k]){
        return dp[i][j][k];
    }
    int ans=0;
    if((s1[i]==s2[j])&&(s1[i]==s3[k])){
        ans=1+calc(s1,s2,s3,i+1,j+1,k+1);
    }
    else{
        int a=calc(s1,s2,s3,i+1,j,k);
        int b=calc(s1,s2,s3,i,j+1,k);
        int c=calc(s1,s2,s3,i,j,k+1);
        ans=max(max(a,b),c);
    }
    visited[i][j][k]=1;
    dp[i][j][k]=ans;
    return dp[i][j][k];
}
 
int main(){
    char s1[55],s2[55],s3[55];
    int i,t,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        //printf("\n");
        memset(dp,0,sizeof(dp));
        memset(visited,false,sizeof(visited));
        scanf("%s%s%s",s1,s2,s3);
        printf("Case %d: %d\n",i,calc(s1,s2,s3,0,0,0));
        //cout<<calc(s1,s2,s3,0,0,0)<<endl;
    }
    return 0;
}