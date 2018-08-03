#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
using namespace std;
vector<int> edj[1010];
int K,no,ed,kp[110],visit[1010];
void input(){
    int x,y,cst;
    sc3(K,no,ed);
    memset(visit,0,sizeof(visit));
    for(int i=1;i<=K;i++)cin>>kp[i];
    for(int i=0;i<ed;i++){
        sc2(x,y);
        edj[x].pb(y);
    }
}
void dfs(int src,int k){
    visit[ src ]++;
    if(edj[src].empty())
        return;
    for(int i=0;i<edj[src].size();i++){
        int u=edj[src][i];
        if(visit[ u ]<k){
            dfs(u,k);
        }
    }
}
int res(){
    for(int i=1;i<=K;i++){
        dfs(kp[i],i);
    }
    int co=0;
    //cout<<endl;
    for(int i=1;i<=no;i++)if(visit[i]==K)co++;
    //cout<<endl;
    for(int i=0;i<=no;i++)edj[i].clear();
    return co;
}
int main(){
    int t;
    sc1(t);
    for(int i=1;i<=t;i++){
        input();
        int r=res();
        printf("Case %d: %d\n",i,r);
    }
    return 0;
}