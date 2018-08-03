#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define MAX 208
using namespace std;
struct{
    double x,y;
    int np,jump;
} arr[MAX];
int source=0;
int no,rcap[MAX][MAX],par[MAX];
double D;
vector<int> edj[MAX];
//-------------
void vclear(){
    memset(rcap,0,sizeof(rcap));
    for(int i=0;i<=2*no+1;i++)edj[i].clear();
}
double discal(double x,double y,double a,double b){
    return sqrt( 1.0*((x-a)*(x-a)+(y-b)*(y-b)) );
}
 
bool bfs(int src,int sinc){
    queue<int> Q;
    int vis[MAX];
    memset(vis,0,sizeof(vis));
    memset(par,0,sizeof(par));
    Q.push(src);
    vis[src]=1;
    bool findaug=false;
    while(!Q.empty()){
        int u=Q.front();
        if(u==sinc){
            findaug=true;
            break;
        }
        for(int i=0;i<edj[u].size();i++){
            int v=edj[u][i];
            if(!vis[v] && rcap[u][v]>0){
                Q.push(v);
                vis[v]=1;
                par[v]=u;
            }
        }
        Q.pop();
    }
    //cout<<"Found\n";
    return findaug;
}
 
int ford_fulkerson(int src,int sinc){
    int max_flow=0;
    while(bfs(src,sinc)){
        vector<int>path;
        int tmp=sinc,vp;
        int flow=INT_MAX;
        while(tmp!=src){
            //cout<<tmp<<" ";
            vp=par[tmp];
            path.pb(tmp);
            flow=min(rcap[vp][tmp],flow);
            //printf("rcap[%d][%d]=%d\nFlow=%d\n",vp,tmp,rcap[vp][tmp],flow);
            tmp=vp;
        }
        //cout<<endl;
        //pr_p(path);
        //cout<<"Flow="<<flow<<endl;
        max_flow+=flow;
 
        tmp=sinc;
        while(tmp!=src){
            vp=par[tmp];
            rcap[vp][tmp]-=flow;
            rcap[tmp][vp]+=flow;
            //tmp[]
            tmp=vp;
        }
 
    }
    //print_path(aug_path);
    return max_flow;
}
 
int main(){
    int t,total;
    scanf("%d",&t);
    for(int test=1;test<=t;test++){
        scanf("%d %lf",&no,&D);
        total=0;
        double aa,bb;
        int cc,dd;
        for(int i=1;i<=no;i++){
            scanf("%lf %lf %d %d",&aa,&bb,&cc,&dd);
            arr[i].x=aa;
            arr[i].y=bb;
            arr[i].np=cc;
            arr[i].jump=dd;
            total+=arr[i].np;
        }
        bool stat=false;
        printf("Case %d:",test);
        for(int id=1;id<=no;id++){
            vclear();
            for(int j=1;j<=no;j++){
                edj[j].pb(no+j);
                rcap[j][no+j]=arr[j].jump;
                edj[no+j].pb(j);
 
                edj[source].pb(j);
                rcap[source][j]=arr[j].np;
                edj[j].pb(source);
            }
            for(int i=1;i<=no;i++){
                for(int j=i+1;j<=no;j++){
                    double dis=discal(arr[i].x,arr[i].y,arr[j].x,arr[j].y);
                    if(dis<=D){
                        edj[no+i].pb(j);
                        edj[j].pb(no+i);
                        rcap[no+i][j]=INT_MAX;
 
                        edj[no+j].pb(i);
                        edj[i].pb(no+j);
                        rcap[no+j][i]=INT_MAX;
                    }
                }
            }
            int mf=ford_fulkerson(0,id);
            if(mf==total){
                stat=true;
                printf(" %d",id-1);
            }
 
        }
        if(!stat) printf(" -1");
        printf("\n");
    }
    return 0;
}