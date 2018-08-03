#include<bits/stdc++.h>
#define pb push_back
#define si1(a) scanf("%d",&a);
#define si2(a,b) scanf("%d%d",&a,&b);
#define lli long long int
using namespace std;
int ar[100001];
int tree[3*100001],bit[100001];
void ini(int node,int st,int en){
    if(st==en){
        tree[node]=ar[st];
        return;
    }
    int left=2*node,right=2*node+1,mid=(st+en)/2;
    ini(left,st,mid);
    ini(right,mid+1,en);
    tree[node]=min(tree[left],tree[right]);
}
 
int mxquery(int node,int st,int en,int p,int r){
    if(st>r||en<p)
        return INT_MAX;
    if(st>=p&&en<=r){
        //res=max(res,tree[node]);
        return tree[node];
    }
    int left=2*node,right=2*node+1,mid=(st+en)/2;
    int p1=mxquery(left,st,mid,p,r);
    int p2=mxquery(right,mid+1,en,p,r);
    return min(p1,p2);
}
int main(){
    int t,n,q;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        si2(n,q);
        memset(tree,0,sizeof(tree));
        for(int j=1;j<=n;j++) si1(ar[j]);
        int a,b;
        ini(1,1,n);
        printf("Case %d:\n", i);
        for(int j=1;j<=q;j++){
            si2(a,b);
            printf("%d\n",mxquery(1,1,n,a,b));
 
        }
    }
    return 0;
}