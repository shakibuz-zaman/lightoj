#define mx 100001
using namespace std;
int a[mx],tree[mx*3],n,poor;
void ini(int node,int st,int en){
    if(st==en){
        tree[node]=a[st];
        return;
    }
    int left=2*node,right=2*node+1;
    int mid=(st+en)/2;
    ini(left,st,mid);
    ini(right,mid+1,en);
    tree[node]=tree[left]+tree[right];
 
}
void update(int node,int st,int en,int in,int x){
    if(in>en||in<st)
        return;
    if(st>=in&&en<=in){
        if(x==-1){
            poor=tree[node];
            tree[node]=0;
        }
        else
            tree[node]+=x;
        return;
    }
    int left=2*node,right=2*node+1,mid=(st+en)/2;
    update(left,st,mid,in,x);
    update(right,mid+1,en,in,x);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int st,int en,int p,int r){
    if(st>r||en<p)
        return 0;
    if(st>=p&&en<=r)
        return tree[node];
    int left=2*node,right=2*node+1,mid=(st+en)/2;
    int p1=query(left,st,mid,p,r);
    int p2=query(right,mid+1,en,p,r);
    return p1+p2;
}
int main(){
    int i,j,t,q,ind,k,ii,jj,pp,ch;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d",&n,&q);
        for(j=1;j<=n;j++){
            scanf("%d",&a[j]);
        }
        ini(1,1,n);
        printf("Case %d:\n",i);
        for(k=1;k<=q;k++){
            scanf("%d",&ch);
            if(ch==1){
                scanf("%d",&ind);
                update(1,1,n,ind+1,-1);
                printf("%d\n",poor);
            }
            else if(ch==2){
                scanf("%d%d",&ind,&pp);
                update(1,1,n,ind+1,pp);
            }
            else if(ch==3){
                scanf("%d%d",&ii,&jj);
                pp=query(1,1,n,ii+1,jj+1);
                printf("%d\n",pp);
            }
        }
    }
    return 0;
}