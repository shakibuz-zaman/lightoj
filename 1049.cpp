#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
using namespace std;
int wt[111][111];
vector<int> edj[111],df,ded[111];
int no,ed;
int visited[111];
void input(){
    sc1(ed);
    memset(wt,0,sizeof(wt));
    int x,y,cst;
 
    for(int i=0;i<ed;i++){
        sc3(x,y,cst);
        edj[x].pb(y);
        edj[y].pb(x);
        wt[y][x]=cst;
    }
}
int cost(int node,int ct){
 
 
    if(node==1)return ct;
    visited[node]=1;
    int nxt=-1;
    for(int i=0;i<edj[node].size();i++){
        if( !visited[ edj[node][i] ] ) {nxt=edj[node][i];}
    }
    for(int i=0;i<edj[node].size();i++){
        if( nxt==-1&&edj[node][i]==1 ) {nxt=edj[node][i];}
    }
    int css=wt[node][nxt];
    return cost( nxt,ct+css );
}
 
int res(){
 
    memset(visited,0,sizeof(visited));
    visited[1]=1;
    int x=edj[1][0],y=edj[1][1];
 
    int cs=wt[1][x],cs2=wt[1][y];
 
    int s1=cost(x,cs);
    memset(visited,0,sizeof(visited));
    visited[1]=1;
    int s2=cost(y,cs2);
    for(int i=0;i<=ed;i++){
        edj[i].clear();
    }
    return min(s1,s2);
}
 
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        input();
        int r=res();
        printf("Case %d: %d\n",i,r);
    }
    return 0;
}