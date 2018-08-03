#include<bits/stdc++.h>
#define pb push_back
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
using namespace std;
void bfs(int src,int dist[]);
vector<int> edj[111],df;
int no,ed;
int visit[111];
int vis[102],parent[111];
 
void input(){
    memset(visit,0,sizeof(visit));
    sc2(no,ed);
    int x,y;
    for(int i=0;i<ed;i++){
        sc2(x,y);
        edj[x].pb(y);
        edj[y].pb(x);
    }
}
 
int res(int s,int d){
    if(ed==0||no<=1)return 0;
    int distt[111],dist[111];
    memset(distt,0,sizeof(distt));
    memset(dist,-1,sizeof(dist));
    dist[d]=0;
    bfs(d,dist);
    bfs(s,distt);
    int mn=-1;
    for(int i=0;i<no;i++){
        mn=max(mn,dist[i]+distt[i]);
    }
    return mn;
}
void clr(){
    for(int i=0;i<no;i++)edj[i].clear();
}
int main(){
    int t,x,y;
    sc1(t);
    for(int i=1;i<=t;i++){
        input();
        sc2(x,y);
        printf("Case %d: %d\n",i,res(x,y));
        clr();
    }
    return 0;
}
 
void bfs(int src,int dist[]){
    queue<int> Q;
    int vis[101];
    memset(vis,0,sizeof(vis));
    Q.push(src);
    vis[src]=1;
    dist[src]=0;
    while(!Q.empty()){
        int u=Q.front();
        for(int i=0;i<edj[u].size();i++){
            int v=edj[u][i];
            if(!vis[v]){
                dist[v]=dist[u]+1;
                Q.push(v);
                vis[v]=1;
                parent[v]=u;
            }
        }
        Q.pop();
    }
}